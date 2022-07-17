#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool verificaValor(vector<int>vet, int menor, int num, int maior, int numVacas, int cap) {
    bool res = true;
    int teste = menor;

    numVacas--;
    while (numVacas != 0) {
        numVacas--;
        if (teste + num > maior) {
            res = false;
            break;
        } else {
            for (int i = 0; i < cap; i++) {
                if (teste + num != vet[i+1]) {
                    if (teste + num <= vet[i+1]) {
                        teste = vet[i+1];
                        break;
                    }
                } else {
                    teste += num;
                    break;
                }
            }            
        }
    }

    return res;
}

int verificaPossibilidade(vector<int> vetor, int numBaias, int numVacas) {
    int maior = vetor[numBaias-1];
    int menor = vetor[0];
    int divisao = maior / numVacas;
    int res;
    int i = divisao+1;
    while(verificaValor(vetor, menor, i, maior, numVacas, numBaias) == false) {
        i--;
    }
    res = i;

    return res;
}

int main() {
    int n, v, res;
    cin >> n;
    cin >> v;

    vector<int> baias;

    for (int i = 0; i < n; i++) {
        int baia;
        cin >> baia;
        baias.push_back(baia);
    }

    sort(baias.begin(), baias.end());
    res = verificaPossibilidade(baias, n, v);
    cout << res;

    return 0;
}