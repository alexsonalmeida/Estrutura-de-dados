#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<char> pilha;
    pilha.push('A');
    pilha.push('B');
    pilha.push('C');
    pilha.push('D');
    pilha.push('E');
    pilha.push('F');
    pilha.push('G');
    pilha.push('H');
    pilha.push('I');
    pilha.push('J');
    pilha.push('K');
    pilha.push('L');
    pilha.push('M');
    pilha.push('N');
    pilha.push('O');
    pilha.push('P');

    int n, m;
    for (int i = 0; i < 15; i++) {
        cin >> n >> m;

        if (n > m) {
            char vit = pilha.front();
            pilha.push(vit);
            pilha.pop();
            pilha.pop();
            //pilha.push(vit);
        } else {
            pilha.pop();
            char vit = pilha.front();
            pilha.pop();
            pilha.push(vit);
        }
    }
    
    cout << pilha.front() << endl;

    return 0;
}