#ifndef HW5_GRAPH_H
#define HW5_GRAPH_H
#include <cstdlib>  // Provides size_t
#include <iostream> // Provides istream and ostream
#include <vector>
#include <map>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream> // collaboration with Daniel Noland
#include "vertex.h"

class graph
{
	public:

	// CONSTRUCTORS and DESTRUCTORS
	graph();
	~graph();

	// MEMBER FUNCTIONS
	void add_vertex(const vertex& v);
	void add_edge(vertex* v, vertex* u, double dist);

	bool is_vertex_there(const vertex& v);
	bool does_dfs_path_exist(const string& city1, const string& city2);
	bool depth_first_search(vertex* u, map<vertex*, bool>& visited, deque<vertex*>& vertex_list, map<vertex*, vertex*>& path);
	bool does_bfs_path_exist(const string& city1, const string& city2);
	bool breadth_first_search(vertex* u, map<vertex*, bool>& visited, deque<vertex*>& vertex_list, map<vertex*, vertex*>& path);
	double great_circle_distance(const vertex& v, const vertex& u) const;

	friend void init_graph_from_file(graph& g, const string& filename, double limit=0.0);

	private:
		// list of cities
		vector<vertex> vertices;
		// neighbours of each city
		map<vertex *, vector<vertex *> > edges;
	};

	void open_for_read(ifstream& f, string filename);
	bool is_more_stuff_there(ifstream& f);

#endif