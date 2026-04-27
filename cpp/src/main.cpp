#include <iostream>
#include "../include/kosajaru.h"
#include "../include/graph_generator.h"
#include <string.h>

#define HELP_ARG "-h"
#define GEN_RAND_GRAPH "-grg"
#define RUN_FILE_GRAPH "-gf"

constexpr const char* HELP_MSG = "Please provide and argument:\n"
                                GEN_RAND_GRAPH " <vertex count> <edge probability> <output filename>    \n==> Generates a random graph with given vertex count and edge probablity, saves it to a filename\n"
                                RUN_FILE_GRAPH " <filename>                                              \n==> Runs kosajaru on the provided graph in the file\n"
                                HELP_ARG "                                                              \n==> Displays this message";

constexpr const char* MISSING_FILENAME_OPERAND_MSG = "Please provide a filename";
constexpr const char* MISSING_V_COUNT_OPERAND_MSG = "Please provide the vertex count";
constexpr const char* MISSING_E_PROB_COUNT = "Please provide the edge probability";
constexpr vertex_t DEFAULT_V_COUNT = 10;

enum OPTIONS : uint8_t {
    OPTN_RUN_FROM_FILE = 0,
    OPTN_GEN_GRAPH = 1
};

int main(int argc, char* argv[]) {
    char* filename{NULL};  
    vertex_t v_cnt{0};
    double e_prob{0};
    uint8_t optns;

    if(argc <= 1) {
        std::cout << HELP_MSG << std::endl;
        return 0;
    }

    for(int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], RUN_FILE_GRAPH) == 0) {
            if(argc > i + 1) {
                filename = argv[i + 1];
                optns = OPTN_RUN_FROM_FILE;
                break;
            }
            else {
                std::cout << MISSING_FILENAME_OPERAND_MSG << std::endl;
            }
        }
        else if (strcmp(argv[i], GEN_RAND_GRAPH) == 0) {
            if(argc > i + 1) {
                v_cnt = std::stoi(argv[i + 1]);
            }
            else {
                std::cout << MISSING_V_COUNT_OPERAND_MSG << std::endl;
                return 0;
            }

            if(argc > i + 2) {
                e_prob = std::stod(argv[i + 2]);
            }
            else {
                std::cout << MISSING_E_PROB_COUNT << std::endl;
                return 0;
            }

            if(argc > i + 3) {
                filename = argv[i + 3];
                optns = OPTN_GEN_GRAPH;
                break;
            }
            else {
                std::cout << MISSING_FILENAME_OPERAND_MSG << std::endl;
                return 0;
            }
        }
        else {
            std::cout << HELP_MSG << std::endl;
            return 0;
        }
    }

    Graph g;
    switch (optns) {
    case OPTN_RUN_FROM_FILE: {
        g.load_from_file(filename);
        std::vector<std::vector<vertex_t>> sccs = kosajaru(g.get_adj_list_ref());
        print_sccs(sccs);
        break;
    }
    case OPTN_GEN_GRAPH: {
        g = generate_rand_graph(v_cnt, e_prob, 3);
        g.save_to_file(filename);
    }
    default:
        break;
    }

    return 0;
}
