#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int> & A, int start, int mid, int end) {
    vector <int> B;
    B.resize(end-start + 1);
    
    int start1 = start;
    int start2 = mid + 1;
    int start3 = 0;

    while (start1 <= mid && start2 <= end) {
        if (A[start1] <= A[start2]) {
            B[start3++] = A[start1++];
        } else {
            B[start3++] = A[start2++];
        }
    }

    while ( start1 <= mid ) {
        B[start3++] = A[start1++];
    }

    while ( start2 <= end ) {
        B[start3++] = A[start2++];
    }

    for (int i = start, j = 0; i <= end; i++, j++) {
        A[i] = B[j];
    }
}

void mergesort(vector <int> & A, int start, int end ) {
    if (end > start) {
        int mid = (start + end) / 2;
        mergesort(A, start, mid);
        mergesort(A, mid+1, end);
        merge(A, start, mid, end );
    }
}

int contaDiferentes(vector<int> v1, vector<int> v2) {
    int diferentes = 0;

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            diferentes++;
        }
    }   
    return diferentes;
}

int main() {
    int tam;
    cin >> tam;

    vector<int> vetor;
    vector<int> vetor1;

    for (int i = 0; i < tam; i++) {
        int num;
        cin >> num;
        vetor.push_back(num);
    }

    vetor1 = vetor;   

    mergesort(vetor, 0, vetor.size() - 1); 

    int res = contaDiferentes(vetor, vetor1);
    cout << res;

    if (res > 0) {
        if (vetor.size() - 2 >= 2) {
            if ((vetor.size() - res) % 2 == 0 && vetor.size() - res > 0) {
                cout << res - 1 << "\n";
            } else if (vetor.size() - res == 2){
                cout << res - 1 << "\n";
            } else if(vetor.size() - res == 0 || vetor.size() % 2 == 0){
                cout << res - 1 << "\n";
            } else {
                cout << res - 2 << "\n";
            }        
        } else {
            cout << res - 1 << "\n";
        }        
    } else {
        
        cout << 0 << "\n";
    }

    return 0;
}