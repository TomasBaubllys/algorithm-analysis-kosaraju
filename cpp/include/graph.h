#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <cstdint>
#include <vector>
#include <iostream>

constexpr const char* FAILED_TO_OPEN_FILE = "Failed to open the provided file!";
constexpr const char* BAD_STRUCT = "Bad file format for the graph";

using vertex_t = size_t;
using edge_t = size_t;

class Graph {
	private:
		vertex_t vertices_count;
		std::vector<std::vector<vertex_t>> adj_list;

	public:
		Graph();

		Graph(std::vector<std::vector<vertex_t>>& adj_list);

		Graph(std::vector<std::vector<vertex_t>>&& adj_list);

		~Graph();

		std::vector<std::vector<vertex_t>>& get_adj_list_ref();

		vertex_t get_vertices_count();

		void print_graph();

		void load_from_file(const char* filename);

		void save_to_file(const char* filename);
};

#endif // GRAPH_H_INCLUDED
