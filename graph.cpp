#include <iostream>
#include <stdexcept>

// data types
struct Node {
    int id;
};

struct Edge {
    Node* node_a;
    Node* node_b;
    int weight;
};

class Graph {
    public:
        Node* nodes;
        Edge* edges;
        const int max_nodes;
        const int max_edges;
        Graph(int max_nodes_arg, int max_edges_arg): 
            nodes {new Node[max_nodes_arg]},
            edges {new Edge[max_edges_arg]},
            max_nodes{max_nodes_arg},
            max_edges{max_edges_arg}{};
        ~Graph() {
            delete[] edges;
            delete[] nodes;
            std::cout << "graph destroyed.\n";
        }
        int get_amount_nodes() {return current_amount_nodes;}
        void inc_amount_nodes() {current_amount_nodes++;}
        int get_amount_edges() {return current_amount_edges;}
        void inc_amount_edges() {current_amount_edges++;}
    private:
        int current_amount_nodes = 0;
        int current_amount_edges = 0;
};

// functions
void add_node(Graph& graph, int id) {
    auto i = graph.get_amount_nodes(); // next position to write to
    if (i < graph.max_nodes) {
        graph.nodes[i] = Node{ id };
        graph.inc_amount_nodes();
    } else {
        throw std::out_of_range("maximum amount of nodes reached");
    }
}

void add_edge(Graph& graph, Node* node_a, Node* node_b, int weight) {
    auto i = graph.get_amount_edges(); // next position to write to
    if (i < graph.max_edges) {
        graph.edges[i] = Edge{ node_a, node_b, weight };
        graph.inc_amount_edges();
    } else {
        throw std::out_of_range("maximum amount of edges reached");
    }
}

void show_status(Graph& g) {
    std::cout << "Graph@" << &g;
    std::cout << " #nodes: " << g.get_amount_nodes();
    std::cout << " #edges: " << g.get_amount_edges();
    std::cout << " |";
    std::cout << " max nodes: " << g.max_nodes;
    std::cout << " max edges: " << g.max_edges << "\n";
}


int main() {
    Graph graph { Graph(16, 32) };
    show_status(graph);

    add_node(graph, 5);
    show_status(graph);

    add_node(graph, 2);
    show_status(graph);

    add_node(graph, 4);
    show_status(graph);

    add_edge(graph, &graph.nodes[0], &graph.nodes[1], 10);
    show_status(graph);
    
    Edge* e = &graph.edges[0];
    std::cout << "The graph has an edge from node " << e->node_a->id << " to node " << e->node_b->id << " with weight " << e->weight << "\n";
    return 0;
}

