#ifndef DISJUNTOS_HPP
#define DISJUNTOS_HPP

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Disjuntos{

    private:
    vector<int> vet;
    vector<int> unidos;
    
    public:
    
    Disjuntos(int n){ 
        for (int i = 0; i < n; i++) {
            vet.push_back(i);
        }
    }

    void une(int x, int y){
        bool findX = false;
        bool findY = false;

        for (int num : unidos) {
            if (x == num) {
                findX = true;
            }
            if (y == num) {
                findY = true;
            }
        }

        if (findX == false) {
            unidos.push_back(x);
        }

        if (findY == false) {
            unidos.push_back(y);
        }
    }

    int mesmo(int x, int y){
        int encontrados = 0;

        for (int num : unidos) {
            if (x == num || y == num) {
                encontrados++;
            }
        }

        if (encontrados == 2) {
            return 1;
        } else {
            return 0;
        }
    }
};


#endif