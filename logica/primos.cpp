#include <iostream>

using namespace std;

int primo(int n) {
    for (int i = 2; i < n; i++) 
        if (n % i == 0) return 0;

    return 1;
}

int main() {
    int a, b;

    cin >> a;
    cin >> b;

    for (int i = a; i <= b; i++) 
        if (primo(i) == 1) cout << i << endl;

    return 0;
}