#include <vector>
#include <iostream>

using namespace std; 

int buscaBinaria(vector<int> vetor, int n, int item) {
    int inicio = 0;
    int fim = n - 1;
    int meio;
    int contador = 0;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        contador++;
        if (vetor[meio] == item) {
            break;
        } else if (vetor[meio] > item) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return contador;
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> vet1;
    vector<int> vet2;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vet1.push_back(num);
    }

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        vet2.push_back(num);
    }

    for (int i = 0; i < m; i++) {
        if (i == m - 1) {
           cout << buscaBinaria(vet1, vet1.size(), vet2[i]) << "\n"; 
        } else {
            cout << buscaBinaria(vet1, vet1.size(), vet2[i]) << " ";
        }
    }

    return 0;
}