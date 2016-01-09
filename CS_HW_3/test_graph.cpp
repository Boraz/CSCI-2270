#include "graph.h"

using namespace std;

int main()
{
	graph g;
    double limit = 100;
    init_graph_from_file(g, "ships.txt", limit);
}
