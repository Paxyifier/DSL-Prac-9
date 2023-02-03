#include <iostream>
using namespace std;
class Edge;
class Node {
public:
    int data;
    Node *next;
    Edge *edges;
    Node(int data) {
        this->data = data;
    }
};
class Edge {
    public:
    Node *node;
    Edge *next;
    Edge(Node *node) {
        this->node = node;
        next = NULL;
    }
};
class Graph {
    public:
    Node *nodes;

    Graph() {
        nodes = NULL;
    }
    void addNode(int data) {
        Node *node = new Node(data);
        if (nodes == NULL) {
            nodes = node;
        } else {
            Node *current = nodes;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }
    void addEdge(int data1, int data2) {
        Node *node1 = findNode(data1);
        Node *node2 = findNode(data2);
        if (node1 != NULL && node2 != NULL) {
            Edge *edge = new Edge(node2);
            if (node1->edges == NULL) {
                node1->edges = edge;
            } else {
                Edge *current = node1->edges;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = edge;
            }
        }
    }
    Node *findNode(int data) {
        Node *current = nodes;
        while (current != NULL) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    void print() {
        Node *current = nodes;
        while (current != NULL) {
            cout << current->data << ": ";
            Edge *edge = current->edges;
            while (edge != NULL) {
                cout << edge->node->data << " ";
                edge = edge->next;
            }
            cout << endl;
            current = current->next;
        }
    }
    
};
int main() {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.print();
    return 0;
}