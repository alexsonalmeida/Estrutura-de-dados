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

 
ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if ( i == 0) {
            head = new ListNode(x);
            ptr = head;
        } else {
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;

}

void print_list(ListNode * head){
    cout << "\n";
    for(auto ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << endl;
    }

}

int soma(int n) {
    if (n + 1 == 10) {
        return 0;
    } else {
        return n+1;
    }
}

ListNode* someUm(ListNode *head){
    ListNode* curr = head;
    
    while (curr != nullptr) {
        if (curr->next == nullptr) {
            if (curr->val + 1 < 10) {
                curr->val += 1;
                break;
            } else {
                curr = head;
                vector<int> vet;
                int i = 0; 
                 

                while (curr != nullptr) {
                    vet.push_back(curr->val);
                    curr = curr->next;
                    i++;
                }    

                i--;
                int contadorFinal = i;

                while (i >= 0) {
                    int num = soma(vet[i]);

                    if (num != 0) {
                        vet[i] = num;
                        break;
                    } else {
                        vet[i] = 0;
                    }

                    i--;
                }   

                curr = head; 

                for (i = 0; i <= contadorFinal; i++) {
                    if (curr->val != vet[i]) {
                        curr->val = vet[i];
                    }
                    curr = curr->next;
                }

                break;
            }
        }
        curr = curr->next;
    }

    if (head->val == 0) {
        ListNode *head2 = new ListNode(1, head);
        return head2;
    } else {
        return head;
    }
} 

int main() {
    ListNode * head = readList();
    head = someUm(head);
    print_list(head);
    return 0;    
}