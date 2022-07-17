#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree {
    Node * root {nullptr};
    BTree() {
    }

    void clone(stringstream& ss, Node ** elo){
        string value;
        ss >> value;

        if (value == "#") {
            return;            
        }

        int num;
        stringstream(value) >> num;
        *elo =  new Node(num);

        clone(ss, &(*elo)->left);
        clone(ss, &(*elo)->right);
    }

    BTree(string serial) {
        stringstream ss(serial);
        clone(ss, &root);
    }

    ~BTree() { //destrutor da árvore
        __destroy(this->root);
    }

    void __destroy(Node * node) {
        if(node == nullptr) {
            return;            
        }
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }
    
    void bshow() {
        __bshow(this->root);
    }

    void __bshow(Node * node, string heranca = "") {
        if(node != nullptr && (node->left != nullptr || node->right != nullptr)) {
            __bshow(node->left , heranca + "l");            
        }

        for (int i = 0; i < (int) heranca.size() - 1; i++) {
            cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");            
        }

        if (heranca != "") {
            cout << (heranca.back() == 'l' ? "┌───" : "└───");            
        }

        if (node == nullptr) {
            cout << "#" << endl;
            return;
        }

        cout << node->value << endl;

        if (node != nullptr && (node->left != nullptr || node->right != nullptr)) {
            __bshow(node->right, heranca + "r");            
        }

    }

    void show_in_order() {
        cout << "[ ";

        __show_in_order(root);
        cout << "]\n";

    }

    void __show_in_order(Node * node) {
        if(node == nullptr) {
            return;  
        }
        __show_in_order(node->left);

        cout << node->value << " ";

        __show_in_order(node->right);
    }

};

int main() {
    string linha;
    getline(cin, linha);

    BTree arvore(linha);
    arvore.show_in_order();
}