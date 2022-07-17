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

bool comparaVetor(vector<int> v1, vector<int>v2) {
    bool res = true;

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            res = false;
            break;
        }
    }

    return res;
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

    for (int i = 0; i < tam; i++) {
        int num;
        cin >> num;
        vetor1.push_back(num);
    } 

    mergesort(vetor, 0, vetor.size() - 1);
    mergesort(vetor1, 0, vetor1.size() - 1);

    bool igual = comparaVetor(vetor, vetor1);

    if (igual == true) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}