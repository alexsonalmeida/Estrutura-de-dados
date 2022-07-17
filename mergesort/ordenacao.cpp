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

int main() {
    int tam;
    cin >> tam;

    vector<int> vetor;
    vector<int> vetorRes;

    for (int i = 0; i < tam; i++) {
        int op = 0;
        int num = 0;

        cin >> op;
        cin >> num;

        if (op == 1 && vetor.size() > 1) {
            vetor.push_back(num);
            mergesort(vetor, 0, vetor.size() - 1);
        } else if (op == 1) {
            vetor.push_back(num);
        } else if (op == 2) {
            vetorRes.push_back(vetor[num]);
        }
    }

    for (int i = 0; i < vetorRes.size(); i++) {
        cout << vetorRes[i] << "\n";
    }

    return 0;
}