#include "../include/graph.h"

#include <fstream>
#include <sstream>

Graph::Graph() {}

Graph::Graph(std::vector<std::vector<vertex_t>>& adj_list) : vertices_count(adj_list.size()),
																					 adj_list(adj_list) {}

Graph::Graph(std::vector<std::vector<vertex_t>>&& adj_list) : vertices_count(adj_list.size()),
																						adj_list(std::move(adj_list)) {
}

Graph::~Graph() {}

std::vector<std::vector<vertex_t>>& Graph::get_adj_list_ref() {return this->adj_list;}

vertex_t Graph::get_vertices_count() {return this->vertices_count;}

void Graph::print_graph() {
	for(const std::vector<vertex_t>& adj_vs : this->adj_list) {
		for(const vertex_t& v : adj_vs) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::load_from_file(const char* filename) {
	if(!filename) {
		return;
	}

	std::ifstream fr(filename);
	if(fr.fail()) {
		std::cout << FAILED_TO_OPEN_FILE << std::endl;
		return;
	}

	size_t v_count = 0;
	fr >> v_count;

	adj_list.clear();
	adj_list.reserve(v_count);
	
	while(true) {
		size_t line_size{0};
		fr >> line_size;
		std::vector<vertex_t> adj;
		adj.reserve(line_size);
		for(size_t i = line_size; i-- > 0;) {
			size_t temp{0};
			fr >> temp;
			adj.push_back(temp);
		}
		if(!fr.eof()) {
			adj_list.push_back(adj);
		}
		else {
			break;
		}
	} 
}

void Graph::save_to_file(const char* filename) {
	if(!filename) {
		return;
	}

	std::ofstream fw(filename);
	if(fw.fail()) {
		std::cout << FAILED_TO_OPEN_FILE << std::endl;
		return;
	}

	fw << adj_list.size() << "\n";
	for(const std::vector<vertex_t>& adj : adj_list) {
		fw << adj.size() << " ";
		for(const vertex_t& v : adj) {
			fw << v << " ";
		}
		fw << '\n';
	}
}