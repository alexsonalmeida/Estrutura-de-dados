#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Estudante{
    public:
        string nome;
        int h;
        Estudante(){}
        Estudante(string nome, int h) : nome(nome), h(h) {}
         
};

/*
Binary function that accepts two elements in the range as arguments, and returns a value convertible
to bool. The value returned indicates whether the element passed as first argument is considered to 
go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.
*/

bool comp(const Estudante e1, const Estudante e2){
    return e1.h > e2.h;
}


int main() { 
    int n, t;
    
    cin >> n >> t;

    vector <Estudante> v;

    v.resize(n);

    for(int i = 0; i < n; i++){
        cin >> v[i].nome >> v[i].h;
    }

    //Ordena os estudantes em ordem decrescente
    sort(v.begin(), v.end() , comp );

    queue<Estudante> time;
    int resto = n % t;
    for (int i = 0; i < t; i++) {
        int adicaoAbsoluta = 0;
        int jogadores = n / t;
        int jogAdicionados = 0;
        vector<string> nomes;

        for (int c = i; jogAdicionados < jogadores; c+=t) {
            time.push(v[c]);
            jogAdicionados++;
            adicaoAbsoluta++;
            if (jogAdicionados == jogadores) {
                if (resto != 0) {
                    time.push(v[c+t]);
                    resto--;
                    adicaoAbsoluta++;
                }
            }
        }
        
        while (time.empty() == false) {
            nomes.push_back(time.front().nome);
            time.pop();
        }
       
        sort(nomes.begin(), nomes.end());
        cout << "Time " << i+1 << endl;

        for (int k = 0; k < adicaoAbsoluta; k++) {
            cout << nomes[k] << endl;
        }

        cout << endl;

        if (i == t-1) {
            cout << endl;
        }

        nomes.clear();
    }
}