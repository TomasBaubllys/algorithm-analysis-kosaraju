#ifndef GRAPH_GENERATOR_H_INCLUDED
#define GRAPH_GENERATOR_H_INCLUDED

#include "graph.h"
#include <cstdint>

Graph generate_rand_graph(const vertex_t& v_count, const double& e_prob, size_t isolated_cnt = 0);


// Generates a random tree graph where each node has between n_low and n_high children 
Graph generate_rand_tree(const vertex_t& v_count, const vertex_t& n_low, const vertex_t& n_high);

#endif // GRAPH_GENERATOR_H_INCLUDED
