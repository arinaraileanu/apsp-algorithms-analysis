#include "algo4.h"

// distance vector
std::vector<int> d;
 struct cmp {
     bool operator()(const edge &x, const edge &y) const {
         return d[x.first] > d[y.first];
     }
 };

/**
 * For a given input graph T, computes the distance from every node to every other node in the graph.
 *
 * @graph: The graph is represented using adjacency lists (graph[i] - gives you the neighbours of node i) *
 * @returns: The adjacency matrix with the minimum distances between every node.
 */
std::vector<std::vector<int> > shortest_path_all(const std::vector<std::vector<edge> >& graph) {
    int n;
	n = graph.size();
    std::priority_queue <edge, std::vector<edge>, cmp > pq;	 // acts as a minheap for distances
    std::vector<std::vector<int> > result(n, std::vector<int>(n, INT_MAX));
	for (int i = 0; i < n; i++)
		d.push_back(INT_MAX);
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[j] = INT_MAX;
		}

		// start with node i as root
        d[i] = 0;
        pq.push({i, 0});

        while(!pq.empty()){
            int node = pq.top().first;
            int dist = pq.top().second;
            pq.pop();

			// maybe we already checked a better distance for node
            if(d[node] < dist)
                continue;

			// try to find a better distance for its neighbours
            for(unsigned int j = 0; j < graph[node].size(); j++){
                int son = graph[node][j].first;
                int weight = graph[node][j].second;
                if(d[son] > d[node] + weight){
					// found a better distance for son
                    d[son] = d[node] + weight;
                    pq.push({son, d[son]});
                }
            }
        }
		// copy distances for node i
        for(int j = 0; j < n; j++) {
            result[i][j] = d[j];
        }
    }
    return result;
}
