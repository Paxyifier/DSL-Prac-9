#include <iostream>
template <typename T>
class Node{
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
    Node<T>* node1;
    Node<T>* node2;
    int weight;
    WeightedEdge<T>(Node<T> node1, Node<T> node2, int weight){
        this->node1 = node1;
        this->node2 = node2;
        this->weight = weight;
    }
};

template <typename T>
class WeightedGraph{
    Node<T> *head;
    WeightedGraph<T>(){
        this->head = NULL;
    }
    void addNode(T data){
        Node<T> *temp = this->head;
        if (this->head ==NULL ){
            this->head = new Node<T>(data);
            return;
        }
        while (temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new Node<T>(data);
    }
    void addEdge(T data1, T data2, int weight){
        
    }
};
