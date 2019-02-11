#include "algo3.h"

// dijkstra distance vector
std::vector<int> d_dij;

struct cmp {
     bool operator()(const edge &x, const edge &y) const {
         return d_dij[x.first] > d_dij[y.first];
     }
};

std::vector<int> dijkstra(const std::vector<std::vector<edge> >& graph, int source) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        d_dij[i] = INT_MAX;
    }
    std::priority_queue <edge, std::vector<edge>, cmp > pq;
    n = graph.size();
    d_dij[source] = 0;
    pq.push({source, 0});
    while(!pq.empty()){
        int node = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        if(d_dij[node] < dist)
            continue;
        for(unsigned int j = 0; j < graph[node].size(); j++){
            int son = graph[node][j].first;
            int weight = graph[node][j].second;
            if(weight == INT_MAX)
                continue;
            long long possible_weight = 1LL * (1LL * d_dij[node] + 1LL * weight);
            long long current_weight = d_dij[son];
            if(current_weight > possible_weight){
                d_dij[son] = d_dij[node] + weight;
                pq.push({son, d_dij[son]});
            }
        }
    }
    return d_dij;
}

std::vector<int> bellman_ford(const std::vector<std::vector<edge> >& graph, int source, bool &ok) {
    std::queue <int> Queue;
    int n;
    n = graph.size();
    std::vector<int> occ(n, 0);
    // bellman-ford distance vector
    std::vector<int> d_bell(n, INT_MAX);
    d_bell[source] = 0;
    Queue.push(source);

    while(!Queue.empty()){
        int node = Queue.front();
        Queue.pop();
        ++occ[node];
        if(occ[node] == n) {
            ok = 0;
            return d_bell;
        }
        for(unsigned int j = 0; j < graph[node].size(); j++){
            int son = graph[node][j].first;
            int weight = graph[node][j].second;
            if (weight == INT_MAX) {
                continue;
            }
            long long current_weight = 1LL * d_bell[son];
            long long possible_weight = 1LL * d_bell[node] + 1LL * weight;
            if(current_weight > possible_weight){
                d_bell[son] = d_bell[node] + weight;
                Queue.push(son);
            }
        }
    }
    return d_bell;
}

/**
 * For a given input graph T, computes the distance from every node to every other node in the graph.
 *
 * @graph: The graph is represented using adjacency lists (graph[i] - gives you the neighbours of node i) *
 * @returns: The adjacency matrix with the minimum distances between every node.
 */
std::vector<std::vector<int> > shortest_path_all(const std::vector<std::vector<edge> >& graph) {
    int n = graph.size();

    // add a new node to the graph
    std::vector<edge> new_edges(n);
    std::vector<std::vector<edge> > extended_graph(graph);
    for(int i = 0; i < n; i++) {
        // add a 0 cost edge to each vertex
        new_edges[i] = {i, 0};
    }
    extended_graph.push_back(new_edges);

    // to check if a negative cycle exists
    bool ok = 1;

    // bellman ford distance vector with new vertex as source
    std::vector<int> d_bell = bellman_ford(extended_graph, n, ok);

    // found a negative cycle
    if(ok == 0)
        return std::vector<std::vector<int> > (n, std::vector<int>(n, INT_MAX));

    // remove newly added edges
    extended_graph.pop_back();

    // reweight previous edges
    for (int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < extended_graph[i].size(); j++) {
            int son = extended_graph[i][j].first;
            extended_graph[i][j].second =
            extended_graph[i][j].second + d_bell[i] - d_bell[son];
        }
    }

    for(int i = 0; i < n; i++)
        d_dij.push_back(INT_MAX);

    // compute matrix of shortest paths
    std::vector<std::vector<int> > result(n, std::vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        std::vector<int> dijkstra_result = dijkstra(extended_graph, i);
        for (int j = 0; j < n; j++) {
            if(dijkstra_result[j] == INT_MAX)
                continue;
            result[i][j] = dijkstra_result[j] + d_bell[j] - d_bell[i];
        }
    }
    return result;
}
