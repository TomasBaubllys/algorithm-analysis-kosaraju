#include "../include/kosajaru.h"
#include <vector>

void dfs1(const vertex_t curr_vertex, const std::vector<std::vector<vertex_t>>& adj_list, std::vector<bool>& visited, std::vector<vertex_t>& visit_stack) {
    visited[curr_vertex] = true;
    for(const vertex_t& adj_v : adj_list[curr_vertex]) {
        if(!visited[adj_v])
            dfs1(adj_v, adj_list, visited, visit_stack);
    }
    visit_stack.push_back(curr_vertex);
}

void dfs2(const vertex_t curr_vertex, const std::vector<std::vector<vertex_t>>& adj_list, std::vector<bool>& visited, std::vector<vertex_t>& scc_container) {
    visited[curr_vertex] = true;
    scc_container.push_back(curr_vertex);
    for(const vertex_t& adj_v : adj_list[curr_vertex]) {
        if(!visited[adj_v])
            dfs2(adj_v, adj_list, visited, scc_container);
    }
}

std::vector<std::vector<vertex_t>>kosajaru(const std::vector<std::vector<vertex_t>>& adj_list) {
    size_t vertices_count = adj_list.size();
    std::vector<bool> visited(vertices_count, false);
    std::vector<vertex_t> visit_stack;
    for(vertex_t i = 0; i < vertices_count; ++i) {
        if(!visited[i]) {
            dfs1(i, adj_list, visited, visit_stack);
        }
    }

    // reverse the adj_list
    std::vector<std::vector<vertex_t>> rev_adj_list;
    rev_adj_list.resize(vertices_count);

    for(vertex_t i = 0; i < vertices_count; ++i) {
    	for(const vertex_t& v : adj_list[i]) {
   			rev_adj_list[v].push_back(i);
     	}
    }

    visited.assign(vertices_count, false);

    std::vector<std::vector<vertex_t>> sccs;

    while(!visit_stack.empty()) {
   		vertex_t v = visit_stack.back();
    	visit_stack.pop_back();
     	if(!visited[v]) {
      		std::vector<vertex_t> scc;
        	dfs2(v, rev_adj_list, visited, scc);
         	sccs.push_back(std::move(scc));
      	}
    }

    return sccs;
}

void print_sccs(const std::vector<std::vector<vertex_t>>& sccs) {
    for(const std::vector<vertex_t>& scc : sccs) {
        std::cout << "[";
        for(const vertex_t& v : scc) {
            std::cout << v << ", ";
        }
        std::cout << "\b\b]\n";
    }
}