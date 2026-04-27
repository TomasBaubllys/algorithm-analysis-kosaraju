#ifndef KOSAJARU_H_INCLUDED
#define KOSAJARU_H_INCLUDED

#include <vector>
#include <cstdint>
#include <stack>
#include "graph.h"

std::vector<std::vector<vertex_t>> kosajaru(const std::vector<std::vector<vertex_t>>& adj_list);

static void dfs1(const vertex_t curr_vertex, const std::vector<std::vector<vertex_t>>& adj_list, std::vector<bool>& visited, std::vector<vertex_t>& visit_stack);

static void dfs2(const vertex_t curr_vertex, const std::vector<std::vector<vertex_t>>& adj_list, std::vector<bool>& visited, std::vector<vertex_t>& scc_container);

void print_sccs(const std::vector<std::vector<vertex_t>>& sccs);

#endif // KOSAJARU_H_INCLUDED
