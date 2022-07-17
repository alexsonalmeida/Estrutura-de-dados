#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    vector<int> vet;
    int tam = 0;

    while (curr != nullptr) {
        vet.push_back(curr->val);
        curr = curr->next;
        tam++;
    }

    vector<int> vetNew;
    int contadorAdicoes = 0;

    for (int i = 0; i < tam; i++) {
        if (i != tam-1) {
            if (vet[i] != vet[i+1]) {
                vetNew.push_back(vet[i]);
                contadorAdicoes++;
            }
        } else {
            vetNew.push_back(vet[i]);
            contadorAdicoes++;
        }
    }

    ListNode* res1 = nullptr; 
    if (contadorAdicoes == 1) {
        ListNode* res = new ListNode(vetNew[0]);
        return res;
    } else {
        for (int i = contadorAdicoes-1; i >= 0; i--) {
            if (i == contadorAdicoes-1 || i > 0) {
                ListNode* no = new ListNode(vetNew[i], res1);
                res1 = no;
            }

            if (i == 0) {
                ListNode* res = new ListNode(vetNew[0], res1);
                return res;
            }
        }        
    }
}

int main() {
    int n;
    ListNode * head= nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if( i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    head = deleteDuplicates(head);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}