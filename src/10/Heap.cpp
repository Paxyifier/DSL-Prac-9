#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Heap {
    public:
    Node *root;
    Heap() {
        root = NULL;
    }
    void insert(int data) {
        Node *node = new Node(data);
        if (root == NULL) {
            root = node;
        } else {
            Node *parent = root;
            Node *current = root;
            while (current != NULL) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (data < parent->data) {
                parent->left = node;
            } else {
                parent->right = node;
            }
        }
    }
    void print() {
        print(root);
        cout << endl;
    }
    void print(Node *node) {
        if (node != NULL) {
            print(node->left);
            cout << node->data << " ";
            print(node->right);
        }
    }
    void heapify (){
        Node *current = root;
        while (current != NULL) {
            if (current->left != NULL && current->right != NULL) {
                if (current->left->data < current->right->data) {
                    int temp = current->data;
                    current->data = current->left->data;
                    current->left->data = temp;
                    current = current->left;
                } else {
                    int temp = current->data;
                    current->data = current->right->data;
                    current->right->data = temp;
                    current = current->right;
                }
            } else if (current->left != NULL) {
                int temp = current->data;
                current->data = current->left->data;
                current->left->data = temp;
                current = current->left;
            } else if (current->right != NULL) {
                int temp = current->data;
                current->data = current->right->data;
                current->right->data = temp;
                current = current->right;
            } else {
                break;
            }
        }
    }
    void heapSort(){
        
    }
};
int main() {
    Heap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(4);
    heap.insert(2);
    heap.insert(1);
    heap.print();
    heap.heapify();
    heap.print();
    heap.heapSort();
    heap.print();
    return 0;
}