#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cassert>
#include <deque>
#include <vector>
#include <map>
#include "graph.h"
using namespace std;

// default constructor at work here; pretty cute!
graph::graph()
{

}

// destructor is easy, we just clear our vertex vector and our edge map
graph::~graph()
{
	vertices.clear();
	edges.clear();
}

// add a vertex to the graph by adding it to the vector
void graph::add_vertex(const vertex& v) 
{
	vertices.push_back(v);
}

// add an edge to the graph as long as it's under the distance limit
void graph::add_edge(vertex* v, vertex* u, double limit)
{
	double dist = great_circle_distance(*v, *u);

	if (dist <= limit)
	{
		edges[v].push_back(u);
	}
}

// compute distance from one lat/long to another as the crow flies
double graph::great_circle_distance(const vertex& v, const vertex& u) const
{
	double PI = 3.1415926535897932;
	double lat1, lat2, long1, long2, dist;

	lat1 = ((double) v.get_latitude_degrees()) + (((double) v.get_latitude_minutes()) / 60.0);
	lat1 *= PI/180.0;
	long1 = ((double) v.get_longitude_degrees()) + (((double) v.get_longitude_minutes()) / 60.0);
	long1 *= PI/180.0;
	lat2 = ((double) u.get_latitude_degrees()) + (((double) u.get_latitude_minutes()) / 60.0);
	lat2 *= PI/180.0;
	long2 = ((double) u.get_longitude_degrees()) + (((double) u.get_longitude_minutes()) / 60.0);
	long2 *= PI/180.0;

	// from http://www.meridianworlddata.com/Distance-Calculation.asp
	// result in km
	dist = 6378.7 * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(long2 - long1)));

	return dist;
}

// check whether a path exists via depth first search.
bool graph::does_dfs_path_exist(const string& city1, const string& city2)
{
	deque<vertex*> yet_to_explore;
	map<vertex*, bool> visited;
	map<vertex*, vertex*> path;
	vertex* v = nullptr; // making sure these are empty
	vertex* u = nullptr;

	// initialize your variables for the depth first search here

	vector<vertex>::iterator edge_city;

	for(edge_city = vertices.begin(); edge_city != vertices.end(); ++edge_city)
	{
		if(edge_city->get_city_name() == city1)
		{
			v = &*edge_city;
		}

		if(edge_city->get_city_name()==city2)
		{
			u= &*edge_city;
		}

		visited[&*edge_city] = false;
		path[&*edge_city] = nullptr;
	}

	if( !v || !u ){
		cerr << "Something went wrong" << endl;
		exit(1);
	} // if courtesy Daniel Noland

	visited[v] = true;
	yet_to_explore.push_back(v);
	/*
	for( unsigned
	v = vertices.city(city1);
	visited[v]==true;
	yet_to_explore.push_back(v); my old code
	*/
	// the rest of the code you can just use
	// launch the depth first search
	// if it succeeds, we say that it worked
	cout << "DEPTH FIRST" << endl;

	if (depth_first_search(u, visited, yet_to_explore, path))
	{
		cout << "path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;

		// now, use the path map to print the path we took
		vertex* node = u;
		cout << u->get_city_name() << endl;
		size_t length = 0;

		while (path.find(node) != path.end() && path[node] != nullptr)
		{
			++length;
			vertex* ancestor = path[node];
			cout << ancestor->get_city_name() << endl;
			node = ancestor;
		}
		cout << "Path length (in hops): " << length << endl;

		return true;
	}

		// if it fails, we admit there is no path
	else
	{
		cout << "no path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;
		return false;
	}

}

// check whether a path exists via breadth first search.
bool graph::does_bfs_path_exist(const string& city1, const string& city2)
{
	deque<vertex*> yet_to_explore;
	map<vertex*, bool> visited;
	map<vertex*, vertex*> path;
	vertex* v = nullptr; // empty double check
	vertex* u = nullptr;

	// initialize your variables for the depth first search here

	vector<vertex>::iterator edge_city;

	for(edge_city = vertices.begin(); edge_city != vertices.end(); ++edge_city)
	{
		if(edge_city->get_city_name() == city1)
		{
			v = &*edge_city;
		}

		if(edge_city->get_city_name()==city2)
		{
			u= &*edge_city;
		}

		visited[&*edge_city] = false;
		path[&*edge_city] = nullptr;
	}

	if( !v || !u ){
		cerr << "Something went wrong" << endl;
		exit(1);
	} // if courtesy Daniel Noland

	visited[v] = true;
	yet_to_explore.push_back(v);

	// the rest of the code you can just use

	// launch the breadth first search
	// if it succeeds, we say that it worked
	cout << "BREADTH FIRST" << endl;
	if (breadth_first_search(u, visited, yet_to_explore, path))
	{
		cout << "path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;

			// now, use the path map to print the path we took
		vertex* node = u;
		cout << u->get_city_name() << endl;
		size_t length= 0;

		while (path.find(node) != path.end() && path[node] != nullptr)
		{
			vertex* ancestor = path[node];
			cout << ancestor->get_city_name() << endl;
			node = ancestor;
			++length;
		}
		cout << "Path length (in hops): " << length << endl;
		return true;

	}
	// if it fails, we admit there is no path
	else
	{
		cout << "no path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;
		return false;
	}
}

bool graph::depth_first_search(vertex* u, map<vertex*, bool>& visited, deque<vertex *>& yet_to_explore, map<vertex*, vertex*>& path)
{
	if(!yet_to_explore.empty()) // our 'stack' still has depth
	{
		vertex *w = yet_to_explore.back(); // take the top and make it a vertex
		yet_to_explore.pop_back(); // pop the 'stack'

		if(w->get_city_name() == u->get_city_name()) // if this is our destination return true
		{
			return true;
		}
		else
		{
			vector<vertex*>::iterator edge_city;

			for(edge_city = edges[w].begin(); edge_city != edges[w].end(); ++edge_city)
			{
				vertex* neighbor = *edge_city;

				if(visited[neighbor] == false)
				{
					yet_to_explore.push_back(neighbor);
					visited[neighbor]=true;
					path[neighbor] = w;
				}

			}
			return depth_first_search(u, visited,yet_to_explore,path);
		}
	}
	return false;
}

bool graph::breadth_first_search(vertex* u, map<vertex*, bool>& visited, deque<vertex*>& yet_to_explore, map<vertex*, vertex*>& path)
{
	if(!yet_to_explore.empty()) // our que is not empty
	{
		vertex *w = yet_to_explore.front(); // add next in que to a vertex
		yet_to_explore.pop_front(); // pop the front of the que

		if(w->get_city_name() == u->get_city_name())
		{
			return true;
		}
		else
		{
			vector<vertex*>::iterator edge_city;

			for(edge_city = edges[w].begin(); edge_city != edges[w].end(); ++edge_city)
			{
				vertex* neighbor = *edge_city;

				if(visited[neighbor] == false)
				{
					yet_to_explore.push_back(neighbor);
					visited[neighbor] = true;
					path[neighbor] = w;
				}
			}
			return breadth_first_search(u, visited,yet_to_explore,path);
		}
	}
	return false;
}

// read in 120 cities and their latitude/longitude
// cities within limit km of each other are connected by edges
void init_graph_from_file(graph& g, const string& filename, double limit)
{
	string line;
	string city_name;
	int lat1, lat2, long1, long2;
	ifstream file_to_read;
	string part_string;
	char compass_dir_NS;
	char compass_dir_EW;

	// open the data file of cities
	open_for_read(file_to_read, filename.c_str());
	size_t k = 0;
	// keep reading until all cities have been added
	while (is_more_stuff_there(file_to_read) && k < 120)
	{
		stringstream ss;
		string data;
		getline(file_to_read, data);
		int loc = data.find(':');
		string city_name = data.substr(0, loc);
		string city_data = data.substr(loc + 2, data.length() - loc - 2);
		ss << city_data;
		ss >> lat1 >> lat2 >> compass_dir_NS >> long1 >> long2 >> compass_dir_EW;
		
		 // string find, starting position + position of the : 
		 // multiply by -1 to get S latitude break at N or S
		 // then break on E or W
		if (compass_dir_NS == 'S')
		{
			lat1 *= -1;
			lat2 *= -1;
		}

		if (compass_dir_EW == 'W')
		{
			long1 *= -1;
			long2 *= -1;
		}

		 // add_vertex(vector<v>); // need to add the data to the vector
		vertex city(city_name, lat1, lat2, long1, long2); // constructor call
		g.add_vertex(city); // this code just puts this vertex at the end of our vertices array
		
		++k;
	}

	// now we are done with our file
	file_to_read.close();

	// now we compute the edges that are within the allowed distance
	vector<vertex>::iterator it1, it2;
	for (it1 = g.vertices.begin(); it1 != g.vertices.end(); ++it1)
	{
		for (it2 = g.vertices.begin(); it2 != g.vertices.end(); ++it2)
		{
			if (it1 != it2)
			{
				g.add_edge(&*it1, &*it2, limit);
			}
		}
	}
}

// function defined by Michael Main for input data
void open_for_read(ifstream& f, string filename)
{
	f.open(filename);

	if (f.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(0);
	}
}

// function defined by Michael Main for input data
bool is_more_stuff_there(ifstream& f)
{
		return (f && (f.peek() != EOF));
}
