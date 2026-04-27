#include "../include/graph_generator.h"
#include <cstdlib>
#include <random>

Graph generate_rand_graph(const vertex_t& v_count, const double& e_prob, size_t isolated_cnt) {
	if(isolated_cnt > v_count) {
		isolated_cnt = v_count;
	}

	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::bernoulli_distribution edge_prob(e_prob);
	
	std::vector<std::vector<vertex_t>> adj_list;
	adj_list.resize(v_count);

	for(vertex_t i = 0; i < v_count - isolated_cnt; ++i) {
		for(vertex_t j = 0; j < v_count; ++j) {
			if (i != j && edge_prob(generator)) {
				adj_list[i].push_back(j);
			}
		}
	}
	for(vertex_t i = v_count + isolated_cnt; i < v_count; ++i) {
		adj_list[i].push_back({});
	}

	return Graph(std::move(adj_list));	
}
