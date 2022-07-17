#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root {nullptr};
    BTree() {
    }

    void clone(stringstream& ss, Node ** elo) {
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

    void __destroy(Node * node) {
        if (node == nullptr) {
            return;            
        }

        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    ~BTree() {
        __destroy(this->root);
    }

    string find_path_aux(Node * node, int value, string path = "") {
        if (node->value == value) {
            return path += "x";
        }

        if (node->left != nullptr) {
            path += find_path_aux(node->left, value, "l");
        }

        if (node->right != nullptr) {
            path += find_path_aux(node->right, value, "r");
        }

        if (path.back() == 'x') {
            return path;
        }
        return "";
    }

    string find_path(Node * node, int value) {
        string saida = find_path_aux(node, value, "");
        return (saida == "")? "!": saida;
    }
};

int main() {
    string linha;
    getline(cin, linha);

    BTree arvore(linha);

    int value;
    cin >> value;

    string path = arvore.find_path(arvore.root, value);
    cout << path << "\n";
}