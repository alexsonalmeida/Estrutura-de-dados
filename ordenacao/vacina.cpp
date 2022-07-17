#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tam = 0;
    cin >> tam;

    vector<int> vetor1;
    vector<int> vetor2;

    for (int i = 0; i < tam; i++) {
        int num;
        cin >> num;
        vetor1.push_back(num);
    }

    for (int i = 0; i < tam; i++) {
        int num;
        cin >> num;
        vetor2.push_back(num);
    }

    sort(vetor1.begin(), vetor1.end());
    sort(vetor2.begin(), vetor2.end());

    bool res = true;

    for (int i = 0; i < tam; i++) {
        if (vetor1[i] <= vetor2[i]) {
            res = false;
        }
    }

    if (res == true) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}