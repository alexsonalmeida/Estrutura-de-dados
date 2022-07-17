#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int contaRepetidos(vector<int> vetor, int num) {
    int n = 0;
    int c = 0;
    int tam = vetor.size();

    for (int i = 0; i < tam; i++) {
        if (vetor[i] == num) {
            c++;
        }
    }

    if (c > 1) {
        n = c;
    }

    return n;
}

int main() {
    int tam = 0;
    cin >> tam;
    int numRepetidos = 0;

    vector<int> vetor;

    for (int i = 0; i < tam; i++) {
        int num;
        cin >> num;
        vetor.push_back(num);
    }

    sort(vetor.begin(), vetor.end());

    for (int i = 0; i <= tam;) {
        int valor = vetor[i];
        int res = contaRepetidos(vetor, valor);

        if (res == 0) {
            i++;
        } else {
            if (res > 2) {
                numRepetidos += (res-1);                 
            } else {
                numRepetidos++;
            }

            i += res;
        }
    }

    cout << numRepetidos << "\n";

    return 0;
}