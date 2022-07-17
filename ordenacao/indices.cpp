#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vetor1;
    vector<int> vetor2;
    vector<int> vetor3;

    int tam = 0;
    cin >> tam;

    for (int i = 0; i < tam; i++) {
        int num;
        cin >> num;
        vetor1.push_back(num);
    }

    vetor2 = vetor1;

    sort(vetor1.begin(), vetor1.end());

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (vetor1[i] == vetor2[j]) {
                int num = j;
                vetor3.push_back(num);
            }
        }
    }

    int fim = 0;

    for (int i: vetor3) {
        fim++;

        if (fim == tam) {
            cout << i << "\n";
        } else {
            cout << i << " ";      
        }
    }

    return 0;
}