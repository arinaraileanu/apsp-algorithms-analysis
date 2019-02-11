#include "algo1.h"
#include "algo2.h"
#include "algo3.h"
#include "algo4.h"
#include <climits>
#include <string>

std::vector<std::string> input_files {"in/test0.in", "in/test1.in",
"in/test2.in", "in/test3.in", "in/test4.in", "in/test5.in", "in/test6.in",
"in/test7.in", "in/test8.in", "other_tests/test0.in", "other_tests/test1.in", 
"other_tests/test2.in", "other_tests/test3.in", "other_tests/test4.in", "other_tests/test5.in", 
"other_tests/test6.in", "other_tests/test7.in", "other_tests/test8.in", "other_tests/test9.in",
"other_tests/test10.in", "other_tests/test11.in", "other_tests/test12.in", "other_tests/test13.in"};

std::vector<std::string> output_files = {"out/test0.out", "out/test1.out",
"out/test2.out", "out/test3.out", "out/test4.out", "out/test5.out", "out/test6.out",
"out/test7.out", "out/test8.out", "other_tests_out/test0.out", "other_tests_out/test1.out", 
"other_tests_out/test2.out", "other_tests_out/test3.out", "other_tests_out/test4.out", 
"other_tests_out/test5.out", "other_tests_out/test6.out", "other_tests_out/test7.out", 
"other_tests_out/test8.out", "other_tests_out/test9.out","other_tests_out/test10.out", 
"other_tests_out/test11.out", "other_tests_out/test12.out", "other_tests_out/test13.out"};

std::vector<std::vector<edge> > read_graph(int &n, int &m, int poz) {
    std::ifstream in(input_files[poz]);
    in >> n >> m;
    std::vector<std::vector<edge> > graph(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        in >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }
    return graph;
}
int main()
{
	for (unsigned int i = 0; i < input_files.size(); i++) {
		std::ofstream out(output_files[i]);
		int n, m;
		std::vector<std::vector<edge> > graph;
		graph = read_graph(n, m, i);
		std::vector<std::vector<int> > result;

		// int start_s=clock();
		result = shortest_path_all(graph);
		// int stop_s=clock();

		for(int i = 0; i < n; i++) {
		        for(int j = 0; j < n; j++) {
		            if(result[i][j] == INT_MAX)
		                out << "inf ";
		            else
		                out << result[i][j] << " ";
		        }
		        out << '\n';
		}
	}
    // out << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << '\n';
    return 0;
}
