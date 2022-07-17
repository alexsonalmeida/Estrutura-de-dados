#include <iostream>
#include <sstream>
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
        if (node == nullptr) {
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
        if (node != nullptr && (node->left != nullptr || node->right != nullptr)) {
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
        if (node == nullptr) {
            return;  
        }
        __show_in_order(node->left);

        cout << node->value << " ";

        __show_in_order(node->right);
    }

Node * find(Node* root, int value) {
        Node* no = nullptr;
        if (root) {
            if (root->value == value) {
                return root;
            } else {
                no = find(root->left, value);
                if (no) {
                    if (no->value == value) {
                        return no;                        
                    }
                }

                no = find(root->right, value);
                if (no) {
                    if (no->value == value) {
                        return no;
                    }
                }    
        }
    } else {
         return nullptr;
    }

    return no; 
}

    int getAltura(Node * node) {
        if (node == nullptr) {
            return 0;
        } else {
            int esq = getAltura(node->left);
            int dir = getAltura(node->right);

            if (esq > dir) {
                return esq + 1;
            } else {
                return dir + 1;
            }
        }
    }

    int getProfundidade(Node* root, int x){
        if (root == nullptr) {
            return -1;            
        }

        int dist = 0;

        if ((root->value == x) || (dist = getProfundidade(root->left, x)) >= 0 || (dist = getProfundidade(root->right, x)) >= 0) {
            return dist + 1;            
        }

        return dist;
    }
};

bool fim(Node* node) {
    if (node == nullptr) {
        return true;
    }
}

int main() {
    string linha;
    getline(cin, linha);
    
    BTree arvore(linha);

    getline(cin, linha);
    stringstream ss(linha);
    int value;
    while(ss >> value) { //enquanto houver elementos no buffer
        Node * node = arvore.find(arvore.root, value);
        if (node != nullptr) {
            cout << arvore.getAltura(node) << " " << arvore.getProfundidade(arvore.root, value) << "\n";
        } else {
            cout << "-1" << endl;            
        }
    }
}