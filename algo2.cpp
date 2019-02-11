#include "algo2.h"
/**
 * For a given input graph T, computes the distance from every node to every other node in the graph.
 *
 * @graph: The graph is represented using adjacency lists (graph[i] - gives you the neighbours of node i) *
 * @returns: The adjacency matrix with the minimum distances between every node.
 */
std::vector<std::vector<int> > shortest_path_all(const std::vector<std::vector<edge> >& graph) {
    std::queue <int> Queue;
    int n;
    n = graph.size();

	// to count occurences of a node
    std::vector<int> occ(n, 0);

	// distance array
    std::vector<int> d(n);
    std::vector<std::vector<int> > result(n, std::vector<int>(n, INT_MAX));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[j] = INT_MAX;
            result[i][j] = INT_MAX;
            occ[j] = 0;
        }
        d[i] = 0;
        Queue.push(i);

        while(!Queue.empty()){
            int node = Queue.front();
            Queue.pop();
            ++occ[node];
            if(occ[node] == n) {
                // found a negative cycle
                return std::vector<std::vector<int> > (n, std::vector<int>(n, INT_MAX));
            }
            for(unsigned int j = 0; j < graph[node].size(); j++){
                int son = graph[node][j].first;
                int weight = graph[node][j].second;

                if(d[son] > d[node] + weight){
					// found a better distance
                    d[son] = d[node] + weight;
                    Queue.push(son);
                }
            }
        }
		// copy result
        for(int j = 0; j < n; j++) {
            result[i][j] = d[j];
        }
    }

    return result;
}
