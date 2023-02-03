#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
class BinarySearchTree{
    private:
        Node *root;
    public:
        BinarySearchTree(){
            root = NULL;
        }
        Node* getRoot(){
            return root;
        }
        void insert(int data){
            insert(root, data);
        }
        void insert(Node *node, int data){
            if(root == NULL){
                root = new Node;
                root->data = data;
                root->left = NULL;
                root->right = NULL;
            }else{
                if(data < node->data){
                    if(node->left != NULL){
                        insert(node->left, data);
                    }else{
                        node->left = new Node;
                        node->left->data = data;
                        node->left->left = NULL;
                        node->left->right = NULL;
                    }
                }else if(data >= node->data){
                    if(node->right != NULL){
                        insert(node->right, data);
                    }else{
                        node->right = new Node;
                        node->right->data = data;
                        node->right->left = NULL;
                        node->right->right = NULL;
                    }
                }
            }
        }
        void remove(int data){
            remove(root, data);
        }
        Node* remove(Node *node, int data){
            if(node == NULL){
                return node;
            }else if(data < node->data){
                node->left = remove(node->left, data);
            }else if(data > node->data){
                node->right = remove(node->right, data);
            }else{
                if(node->left == NULL && node->right == NULL){
                    delete node;
                    node = NULL;
                }else if(node->left == NULL){
                    Node *temp = node;
                    node = node->right;
                    delete temp;
                }else if(node->right == NULL){
                    Node *temp = node;
                    node = node->left;
                    delete temp;
                }else{
                    Node *temp = findMin(node->right);
                    node->data = temp->data;
                    node->right = remove(node->right, temp->data);
                }
            }
            return node;
        }
        void display(){
            display(root);
            cout << endl;
        }
        void display(Node *node){
            if(node != NULL){
                display(node->left);
                cout << node->data << " ";
                display(node->right);
            }
        }
        void preOrder(){
            preOrder(root);
            cout << endl;
        }
        void preOrder(Node *node){
            if(node != NULL){
                cout << node->data << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
        void inOrder(){
            inOrder(root);
            cout << endl;
        }
        void inOrder(Node *node){
            if(node != NULL){
                inOrder(node->left);
                cout << node->data << " ";
                inOrder(node->right);
            }
        }
        void postOrder(){
            postOrder(root);
            cout << endl;
        }
        void postOrder(Node *node){
            if(node != NULL){
                postOrder(node->left);
                postOrder(node->right);
                cout << node->data << " ";
            }
        }
        Node* search(int data){
            return search(root, data);
        }
        Node* search(Node *node, int data){
            if(node != NULL){
                if(node->data == data){
                    return node;
                }else if(data < node->data){
                    return search(node->left, data);
                }else{
                    return search(node->right, data);
                }
            }else{
                return NULL;
            }
        }
        Node* findMin(){
            return findMin(root);
        }
        Node* findMin(Node *node){
            if(node == NULL){
                return NULL;
            }else if(node->left == NULL){
                return node;
            }else{
                return findMin(node->left);
            }
        }
        Node* findMax(){
            return findMax(root);
        }
        Node* findMax(Node *node){
            if(node == NULL){
                return NULL;
            }else if(node->right == NULL){
                return node;
            }else{
                return findMax(node->right);
            }
        }
        int height(){
            return height(root);
        }
        int height(Node *node){
            if(node == NULL){
                return -1;
            }else{
                int leftHeight = height(node->left);
                int rightHeight = height(node->right);
                if(leftHeight > rightHeight){
                    return leftHeight + 1;
                }else{
                    return rightHeight + 1;
                }
            }
        }
        int size (){
            return size(root);
        }
        int size(Node *node){
            if(node == NULL){
                return 0;
            }else{
                return size(node->left) + 1 + size(node->right);
            }
        }
        int deselectAfter(){
            return countNodes(root);
        }
        int countNodes(Node *node){
            if(node == NULL || (node->left == NULL && node->right == NULL)){
                return 0;
            }else if(node->left != NULL && node->right != NULL){
                return 1 + countNodes(node->left) + countNodes(node->right);
            }else{
                return countNodes(node->left) + countNodes(node->right);
            }
        }

};
int main(){
    BinarySearchTree bst = BinarySearchTree();
    bool run = true;
    // test cases
    if (!run){
        bst.insert(5);
        bst.insert(3);
        bst.insert(1);
        bst.insert(4);
        bst.insert(7);
        bst.insert(6);
        bst.insert(8);
        bst.display();
        cout << "countNodes: "<<bst.deselectAfter() << endl;
        cout << "size: "<<bst.size() << endl;
        cout << "height: "<<bst.height() << endl;
        cout << "findMin: "<<bst.findMin()->data << endl;
        cout << "findMax: "<<bst.findMax()->data << endl;
        cout << "search: "<<bst.search(8)->data << endl;
        cout << "search: "<<bst.search(9)->data << endl;
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.postOrder();
        bst.remove(1);
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.postOrder();
        bst.remove(3);
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.postOrder();
        bst.remove(5);
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.postOrder();
        bst.remove(4);
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.postOrder();
        bst.remove(6);
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.postOrder();
        bst.remove(7);
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.postOrder();
        bst.remove(8);
        bst.display();
        bst.preOrder();
        bst.inOrder();
        bst.display();
        bst.postOrder();
        run = true;

    }
    // Program
    int choice, data;
    while (run){
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. PreOrder" << endl;
        cout << "5. InOrder" << endl;
        cout << "6. PostOrder" << endl;
        cout << "7. Search" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter data: ";
                cin >> data;
                bst.insert(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                bst.remove(data);
                break;
            case 3:
                bst.display();
                cout << endl;
                break;
            case 4:
                bst.preOrder();
                cout << endl;
                break;
            case 5:
                bst.inOrder();
                cout << endl;
                break;
            case 6:
                bst.postOrder();
                cout << endl;
                break;
            case 7:
                cout << "Enter data: ";
                cin >> data;
                if(bst.search(data) != NULL){
                    cout << "Found" << endl;
                }else{
                    cout << "Not Found" << endl;
                }
                break;
            case 8:
                run = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }

    }


    return 0;
}
