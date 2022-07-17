#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int proxMaiores(int n, int ind, vector<int> vet) {
    if (ind < n-1) {
        for (int i = ind+1; i < n; i++) {
            if (vet[i] > vet[ind]) {
                return i;
                break;
            }
            if (i == n-1) {
                return -1;
            }
        }
    } else {
        return -1;
    }
}

int main() {
    vector<int> vet;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vet.push_back(num);
    }

    stack<int> pilha; 

    for (int i = n-1; i >=0; i--) {
        int val = proxMaiores(n, i, vet);
        pilha.push(val);
    }


    for (int i = 0; i < n; i++) {
        cout << pilha.top() << " ";
        pilha.pop();
    }
    
    return 0;
}
