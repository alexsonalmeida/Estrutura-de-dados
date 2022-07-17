#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Product {
    private:
    string name;
    int price;

    public:
    Product(string n, int p) {
        name = n;
        price = p;
    }

    bool operator<(const Product & a) {
        if ( price != a.price) {
            return price < a.price;
        } else {
            return name < a.name;
        }
    }

    int getPrice() {
        return price;
    }

    string getName() {
        return name;
    }
};

bool antes(shared_ptr<Product> p1, shared_ptr<Product> p2) {
    if (p1 -> getPrice() != p2 -> getPrice()) {
        return p1 -> getPrice() < p2 -> getPrice();
    } else {
        return p1 -> getName() < p2 -> getName();
    }
}

bool trocaIguais(shared_ptr<Product> p1, shared_ptr<Product> p2) {
    if (p1 -> getPrice() == p2 -> getPrice()) {
        return p1 -> getName() < p2 -> getName();
    }
}

void mostraCompras(vector<shared_ptr<Product>> vet1, vector<shared_ptr<Product>> vet2, int p, int q) {
    vector<shared_ptr<Product>> compras;
    sort(vet1.begin(), vet1.end(), antes);
    sort(vet2.begin(), vet2.end(), antes);

    for (int i = 0; i < p; i++) {
        compras.push_back(vet1[i]);
    }

    for (int i = 0; i < q; i++) {
        compras.push_back(vet2[i]);
    }

    sort(compras.begin(), compras.end(), trocaIguais);

    for (int i = 0; i < compras.size(); i++) {
        if (i == compras.size() - 1) {
           cout << compras[i] -> getName() << "\n"; 
        } else {
            cout << compras[i] -> getName() << " ";
        }
    }
}

int main() {
    int n, m, p, q;

    cin >> n;
    cin >> m;
    cin >> p;
    cin >> q;

    int total = n + m;

    vector<shared_ptr<Product>> secao1;
    vector<shared_ptr<Product>> secao2;

    for (int i = 0; i < total; i++) {
        string name;
        int price;
        cin >> name;
        cin >> price;

        Product prt(name, price);

        if (i < n) {
            secao1.push_back(make_shared<Product>(name, price));
        } else {
            secao2.push_back(make_shared<Product>(name, price));
        }
    }

    mostraCompras(secao1, secao2, p, q);
}