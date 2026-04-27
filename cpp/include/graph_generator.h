#ifndef GRAPH_GENERATOR_H_INCLUDED
#define GRAPH_GENERATOR_H_INCLUDED

#include "graph.h"
#include <cstdint>

Graph generate_rand_graph(const vertex_t& v_count, const double& e_prob, size_t isolated_cnt = 0);

#endif // GRAPH_GENERATOR_H_INCLUDED
