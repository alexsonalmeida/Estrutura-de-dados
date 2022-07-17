#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tam;
    cin >> tam;
    vector<int> distance;
    vector<int> fuel;
    int tanque;

    for (int i = 0; i < tam; i++) {
        int gasolina;
        int distancia;
        cin >> gasolina;
        cin >> distancia;
        fuel.push_back(gasolina);
        distance.push_back(distancia);
    }

    for (int i = 0; i < tam; i++) {
        int ind = i;
        int k = 0;
        tanque = 0;

        while (true) {
            k++;
            if (k == tam-1) {
                cout << i << endl;
                i = tam;
                break;
            }

            tanque += fuel[ind];
            tanque -= distance[ind];
            if (tanque < 0) {
                break;
            }  

            if (ind == tam-1) {
                ind = -1;
            } 
            ind++;                  
        }
    }

    return 0;
}