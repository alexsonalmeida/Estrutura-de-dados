#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inverteVetor(vector<int> & vet, vector<int> & vetc, int indice) {
    int decrementador = indice;

    if (indice == 0) {
       swap(vet[indice], vet[indice+1]);
    } else if (indice == 1) {
        swap(vet[indice], vet[indice-1]);
    } else {
        for (int i = 0; i <= indice; i++) {
            vet[i] = vetc[decrementador];
            decrementador--;
        }
    }

    vetc = vet;
}

bool vetoresIguais(vector<int> vet, vector<int> ordem, int tam) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] != ordem[i]) {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> vet;
    vector<int> vetc;
    vector<int> res;
    vector<int> ordem;

    int tam = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vet.push_back(num);
    }

    vetc = vet;
    ordem = vet;
    sort(ordem.begin(), ordem.end());
    int indice = n-1;

    while (vetoresIguais(vet, ordem, n) != true) {
        if (vet[0] == ordem[indice]) {
            inverteVetor(vet, vetc, indice); 
            res.push_back(n-indice);
            tam++;
        } else {
            if (vet[indice] != ordem[indice]) {
                for (int i = 0; i < n; i++) {
                    if (vet[i] == ordem[indice]) {
                        inverteVetor(vet, vetc, i);
                        res.push_back(n-i);
                        tam++;  
                        if (vetoresIguais(vet, ordem, n) != true) {
                            inverteVetor(vet, vetc, indice); 
                            res.push_back(n-indice);
                            tam++;                            
                            break; 
                        }
                        break;
                    }
                }
            }
        }
        indice--;
    }

    res.push_back(0);
    tam++;

    for (int i = 0; i < tam; i++) {
        if (i == tam-1) {
            cout << res[i] << "\n";
        } else {
            cout << res[i] << " ";
        }
    }
}