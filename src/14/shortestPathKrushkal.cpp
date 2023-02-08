#include <iostream>
template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
    Node(T data, Node<T> *next){
        this->data = data;
        this->next = next;
    }
};
template <typename T>
class WeightedEdge{
    public:
    Node<T>* node1;
    Node<T>* node2;
    WeightedEdge<T>* next;
    int weight;
    WeightedEdge<T>(Node<T> node1, Node<T> node2, int weight,WeightedEdge<T>* next =NULL){
        this->node1 = node1;
        this->node2 = node2;
        this->weight = weight;
        this->next = next;
    }
};

template <typename T>
class WeightedGraph{
    Node<T> *nodeHead;
    WeightedEdge<T> *edgeHead;
    WeightedGraph<T>(){
        this->nodeHead = NULL;
        this->edgeHead = NULL;
    }
    void addNode(T data){
        Node<T> *temp = this->head;
        if (this->nodeHead ==NULL ){
            this->nodeHead = new Node<T>(data);
            return;
        }
        while (temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new Node<T>(data);
    }
    Node<T>* findNode(T data){
        if (this->nodeHead==NULL){
            return NULL;
        }
        Node<T>* temp = this->nodeHead;
        while (temp !=NULL){
            if (temp->data == data){
                return temp;
            }
            temp = temp->next;
        }
    }
    void addEdge(T data1, T data2, int weight){
        Node<T>* node1 = findNode(data1);
        Node<T>* node2 = findNode(data2);
        WeightedEdge<T> edge = new WeightedEdge<T>(node1, node2, weight),
        temp=this->edgeHead;
        if (this->edgeHead == NULL){
            this->edgeHead = edge;
            return;
        }
        while (this->temp->next !=NULL){
            
        }
    }
};
