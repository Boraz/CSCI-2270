#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "graph.h"

using namespace std;

int main()
{
    string city1 = "Amsterdam, Netherlands";
    string city2 = "Teheran, Iran";
    graph g;
    // edges <= limit are included in the graph
    double limit = 2000;
    init_graph_from_file(g, "world_cities.txt", limit);
    cout << "At a limit of " << limit << ":" << endl;
    g.does_dfs_path_exist(city1, city2);
    g.does_bfs_path_exist(city1, city2);

    limit = 4000;
    init_graph_from_file(g, "world_cities.txt", limit);    
    city1 = "Singapore, Singapore";
    city2 = "Odessa, Ukraine";
    cout << "At a limit of " << limit << ":" << endl;
    g.does_dfs_path_exist(city1, city2);
    g.does_bfs_path_exist(city1, city2);

    limit = 1500;
    init_graph_from_file(g, "world_cities.txt", limit);    
    city1 = "Veracruz, Mexico";
    city2 = "Sao Paulo, Brazil";
    cout << "At a limit of " << limit << ":" << endl;
    g.does_dfs_path_exist(city1, city2);
    g.does_bfs_path_exist(city1, city2);
    
}
