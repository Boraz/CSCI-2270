#include "graph.h"
using namespace std;

// default constructor at work here; pretty cute!
graph::graph()
{
}

// destructor is easy, we just clear our vertex vector and our edge map
graph::~graph()
{
	vertices.clear(); // vertex
	edges.clear(); // maps
}

// add a vertex to the graph by adding it to the vector
void graph::add_vertex(const vertex& v) 
{
	vertices.push_back(v);
}

// add an edge to the graph as long as it's under the distance limit
void graph::add_edge(vertex* v, vertex* u, double limit)
{
	double dist = 0;
	dist = great_circle_distance(*v, *u);

	if(dist <= limit)
	{
		 // edges[v].push_back(u); // edge v or u? both?
		edges[u].push_back(v);
		 // add_edge(v, u, great_circle_distance);
	}
	 // compute distance, evaluate if you add an edge
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

// read in 120 cities and their latitude/longitude
// cities within limit km of each other are connected by edges
void init_graph_from_file(graph& g, const string& filename, double limit)
{
	string line;
	string city_name;
	string tempstr;
	int lat1, lat2, long1, long2;
	ifstream file_to_read;
	char compass_dir_NS;
	char compass_dir_EW;

	// open the data file of cities
	open_for_read(file_to_read, filename);

	unsigned int k = 0;
	while(k < 120)
	{
		do
		{
			//getline(tempstr, city_name, ':');
			//getline(tempstr, lat1, )
			file_to_read >> tempstr;
			city_name += tempstr;
		}
		while(tempstr[tempstr.length()-1] != ':');

		file_to_read >> lat1;
		file_to_read >> lat2;
		file_to_read >> compass_dir_NS;
			
			if(compass_dir_NS == 'S')
			{
				lat1 *= -1;
				lat2 *= -1;
			}

		file_to_read >> long1;
		file_to_read >> long2;
		file_to_read >> compass_dir_EW;

			if(compass_dir_EW == 'W')
			{
				long1 *= -1;
				long2 *= -1;
			}
		 // string find, starting position + position of the : 
		 // multuply by -1 to get S latitude break at N or S
		 // then break on E or W

		 // add_vertex(vector<v>); // need to add the data to the vector
		vertex city(city_name, lat1, lat2, long1, long2); // constructor call
		g.add_vertex(city); // this code just puts this vertex at the end of our vertices array

		++k;
	}

	file_to_read.close();

	 // add the edges
	for(unsigned int i = 0; i < k; ++i)
	{
		for (unsigned int j = 0; j < k; ++j)
		{
			if(i != j)
			{
				g.add_edge(&g.vertices[i], &g.vertices[j], limit); // seems to work
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

bool depth_first_search(vertex* u,map<vertex*, bool>& visited,
		deque<vertex*>& yet_to_explore, map<vertex*, vertex*>& path);
{
	if(!yet_to_explore.empty())
	{
		vertex* w = yet_to_explore.back(); // use .front to find the front
		yet_to_explore.pop_back();
		
		if(w->get_city_name() == u->get_city_name())
		{
			return true;
		}
		vector<vertex*>::iterator it;
		for(it = edges[w].begin(); it != edges[w].end(); ++it)
		{
			vertex* neighbor = *it;
			if(visited[neighbor] == false)
			{
				yet_to_explore.push_back(neighbor);
				visited[neighbor] = true;
				path[neighbor] = w;
			}
		}
		return depth_first_search(u, visited, yet_to_explore, path);
	}
	else return false; //  depth first. for breth add from the other sides
}
