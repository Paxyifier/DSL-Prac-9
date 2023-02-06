#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data,Node *next=NULL){
        this->data = data;
        if (next != NULL){
            this->next = next;
        }
    }
};
class Stack{
    public:
    Node *top;
    Stack(){
        top = NULL;
    }
    void push(int data){
        if (top == NULL){
            top = new Node(data);
        }
        else{
            top = new Node(data,top);
        }
    }
    int pop(){
        if (top == NULL){
            return -1;
        }
        else{
            int temp = top->data;
            top = top->next;
            return temp;
        }
    }
    void print(){
        Node *temp = top;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
class Term{
    public:
    int node1,node2,value=1;
    Term *next;
    Term(int node1,int node2,Term *next=NULL){
        this->node1 = node1;
        this->node2 = node2;
        if (next != NULL){
            this->next = next;
        }
    }
};
class Graph {
    public:
    Term *head;
    int nodes;
    Graph(int nodes){
        this->nodes = nodes;
        head = NULL;
    }
    void addTerm(int node1,int node2){
        if (head == NULL){
            head = new Term(node1,node2);
        }
        else{
            Term *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new Term(node1,node2);
        }
    }
    void print(){
        Term *temp = head;
        for (int i=1; i<=nodes; i++) {
            for (int j=1; j<=nodes; j++) {
                if (temp == NULL) {
                    cout<<"0 ";
                    continue;
                }
                if (temp->node1 == i && temp->node2 == j) {
                    cout<<temp->value<<" ";
                    temp = temp->next;
                }
                else {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
    int *dfs(int node){
        int *visited = new int[nodes+1];
        for (int i=1; i<nodes+1; i++) {
            visited[i] = 0;
        }
        visited[node] = 1;
        Stack *stack = new Stack();
        stack->push(node);
        cout << "Stack :: Pushed : "<<node<<" : ";
        stack->print();
        while (stack->top != NULL) {
            int temp = stack->pop();
            cout << "Stack :: Popped : "<<temp<<" : ";
            stack->print();
            Term *tempTerm = head;
            while (tempTerm != NULL) {
                if (tempTerm->node1 == temp && visited[tempTerm->node2] == 0) {
                    stack->push(tempTerm->node2);
                    cout << "Stack :: Pushed : "<<tempTerm->node2<<" : ";
                    stack->print();
                    // printArray(visited, 0, nodes-1);
                    visited[tempTerm->node2] = 1;
                }
                tempTerm = tempTerm->next;
            }
        }
        return visited;
    }
    void printArray(int *arr, int start, int end){
        for (int i=start; i<=end; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    //generate test graph
    Graph *graph = new Graph(7);
    graph->addTerm(1,2);
    graph->addTerm(1,4);
    graph->addTerm(2,1);
    graph->addTerm(2,3);
    graph->addTerm(2,5);
    graph->addTerm(3,5);
    graph->addTerm(3,6);
    graph->addTerm(3,7);
    graph->addTerm(4,1);
    graph->addTerm(4,5);
    graph->addTerm(5,2);
    graph->addTerm(5,4);
    graph->addTerm(5,6);
    graph->addTerm(6,3);
    graph->addTerm(6,5);
    graph->addTerm(6,7);
    graph->addTerm(7,3);
    graph->addTerm(7,6);
    //print graph
    graph->print();
    //dfs
    cout<<"dfs:"<<endl;
    int *visited = graph->dfs(1);
    graph->printArray(visited, 1, 7);

    // cout << "Graph" << endl;
    // cout << "Enter number of Nodes in the graph: ";
    // int nodes;
    // cin >> nodes;
    // cout << "Enter number of nodes: ";
    // Graph s = Graph(nodes);
    // cout << "Enter number of edges: ";
    // int edges;
    // cin >> edges;
    // for (int i=0; i<edges; i++) {
    //     cout << "Enter node1: ";
    //     int node1;
    //     cin >> node1;
    //     cout << "Enter node2: ";
    //     int node2;
    //     cin >> node2;
    //     s.addTerm(node1,node2);
    // }
    // s.print();
    // s.dfs(5);
    return 0;
}