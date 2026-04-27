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

Graph generate_rand_tree(const vertex_t& v_count, const vertex_t& n_low, const vertex_t& n_high) {
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution unif_int_gen(n_low, n_high);

	std::vector<std::vector<vertex_t>> adj_list;
	adj_list.resize(v_count);

	size_t i{1};
	size_t j{0};
	// generate the root
	// the idea, root connects to entire next block
	while(i < v_count) {
		size_t curr_block = unif_int_gen(generator);
		curr_block = (curr_block + i >= v_count? v_count - i: curr_block); 
		adj_list[j].resize(curr_block);
		std::iota(adj_list[j].begin(), adj_list[j].end(), i);
		i += curr_block;
		++j;
	}

	return Graph(std::move(adj_list));
}