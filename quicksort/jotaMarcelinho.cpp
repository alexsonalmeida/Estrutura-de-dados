#include <iostream>

using namespace std;

float calculaPreco(int n, int doacao) {
    float valor = 0;

    for (int i = 0; i < n; i++) {
        valor = (valor + doacao) / 2;
    }

    return valor;
}

int main() {
    int n, doacao;
    float valor;

    cin >> n;
    cin >> doacao;

    valor = calculaPreco(n, doacao);

    cout << fixed;
    cout.precision(2);
    cout << valor;

    return 0;
}