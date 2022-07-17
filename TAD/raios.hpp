#ifndef RAIOS_HPP
#define RAIOS_HPP

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Raios{

    private:
    int numLarg;
    int numComp;
    int vezesCaiu;
    vector<int> larg;
    vector<int> comp;
       
    public:
    
    Raios(int n, int m){ 
        vezesCaiu = 0;
        numLarg = n;
        numComp = m;
        for (int i = 0; i < n; i++) {
            larg.push_back(0);
            comp.push_back(0);
        }
    }

    void add(int x, int y){
        if (x != 0 && y != 0) {
            if (larg[x-1] == 1 && comp[y-1] == 1) {
                vezesCaiu++;
            } else {
                larg[x-1] = 1;
                comp[y-1] = 1;
            }            
        } else if (x == 0 && y != 0) {
            if (larg[x] == 1 && comp[y-1] == 1) {
                vezesCaiu++;
            } else {
                larg[x] = 1;
                comp[y-1] = 1;
            }                        
        } else if (x != 0 && y == 0) {
            if (larg[x-1] == 1 && comp[y] == 1) {
                vezesCaiu++;
            } else {
                larg[x-1] = 1;
                comp[y] = 1;
            }                        
        } else {
             if (larg[x] == 1 && comp[y] == 1) {
                vezesCaiu++;
            } else {
                larg[x] = 1;
                comp[y] = 1;
            }           
        }
    }

    int mesmo_lugar(){
       if (vezesCaiu >= 1) {
        return 1;
       } else {
        return 0;
       }
    }
};


#endif
