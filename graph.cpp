#include <iostream>

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
        Graph(int max_nodes, int max_edges): 
            nodes {new Node[max_nodes]},
            edges {new Edge[max_edges]}{};
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
    Node new_node;
    new_node.id = id; 
    graph.nodes[graph.get_amount_nodes()] = new_node;
    graph.inc_amount_nodes();
}

int main() {
    Graph* graph = new Graph(4, 2);
    add_node(*graph, 5);
    
    std::cout << "Made a graph with a node with id " << graph->nodes[0].id;
    
    delete graph;
    return 0;
}
