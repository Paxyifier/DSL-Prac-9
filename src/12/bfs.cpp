#include <iostream>
using namespace std;
class Term{
    public:
    int node1,node2,value;
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
    int *bfs(int node){
        int *visited = new int[nodes];
        for (int i=0; i<nodes; i++) {
            visited[i] = 0;
        }
        visited[node-1] = 1;
        int *queue = new int[nodes];
        int front = 0;
        int rear = 0;
        queue[rear] = node;
        rear++;
        while (front != rear) {
            int temp = queue[front];
            front++;
            Term *tempTerm = head;
            while (tempTerm != NULL) {
                if (tempTerm->node1 == temp && visited[tempTerm->node2-1] == 0) {
                    queue[rear] = tempTerm->node2;
                    rear++;
                    printArray(queue, front, rear-1);
                    visited[tempTerm->node2-1] = 1;
                }
                tempTerm = tempTerm->next;
            }
        }
        return visited;
    }
    int *dfs(int node){
        int *visited = new int[nodes];
        for (int i=0; i<nodes; i++) {
            visited[i] = 0;
        }
        visited[node-1] = 1;
        int *stack = new int[nodes];
        int top = 0;
        stack[top] = node;
        top++;
        while (top != 0) {
            int temp = stack[top];
            top--;
            Term *tempTerm = head;
            while (tempTerm != NULL) {
                if (tempTerm->node1 == temp && visited[tempTerm->node2-1] == 0) {
                    stack[top] = tempTerm->node2;
                    top++;
                    printArray(stack, 0, top-1);
                    visited[tempTerm->node2-1] = 1;
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
    cout << "Graph" << endl;
    cout << "Enter number of Nodes in the graph: ";
    int nodes;
    cin >> nodes;
    cout << "Enter number of nodes: ";
    Graph s = Graph(nodes);
    cout << "Enter number of edges: ";
    int edges;
    cin >> edges;
    for (int i=0; i<edges; i++) {
        cout << "Enter node1: ";
        int node1;
        cin >> node1;
        cout << "Enter node2: ";
        int node2;
        cin >> node2;
        s.addTerm(node1,node2);
    }
    s.print();
    return 0;
}