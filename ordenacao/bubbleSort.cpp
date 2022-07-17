#include <iostream>
#include <vector> 
using namespace std;

int BubbleSort(vector<int> vetor) {
    int c = 0;
    bool swapped = true;
    int n = vetor.size();    

    while (swapped != false) {
        swapped = false;
        c++;
        for (int i = 0; i < (n-1); i++) {
            if (vetor[i] > vetor[i+1]) {
                swap(vetor[i], vetor[i+1]);
                swapped = true;
            }
        }
    }

    return c;
}

int main() {
    int tam = 0;
    cin >> tam;

    vector<int> vetor;

    for (int i = 0; i < tam; i++) {
        int num;
        cin >> num;
        vetor.push_back(num);
    }

    cout << BubbleSort(vetor) << "\n";
 }

