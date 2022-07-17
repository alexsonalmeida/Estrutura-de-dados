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
    ListNode(ListNode *head1, ListNode *head2) {
        while (head1!=nullptr) {
            head2 = new ListNode(head1->val, head2);
            head1=head1->next;
        }
    }
};

void printList(ListNode * head) {
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}

ListNode* oddEvenList(ListNode* head) {
    //ListNode* no = new ListNode(head->val);
    ListNode* curr = nullptr;
    ListNode* no = nullptr;
    ListNode*head2 = nullptr;
    vector<int> pares;
    vector<int> impares;

    int cp = 0;
    int ci = 0;
    int c = 1;

    while (head != nullptr) {
        if (c % 2 == 0) {
            pares.push_back(head->val);
            cp++;
        } else {
            impares.push_back(head->val);
            ci++;
        }
        head = head->next;
        c++;
    }

    while (c > 1) {
        for (int i = cp-1; i >= 0; i--) {
            head2 = new ListNode(pares[i], head2);
            c--;
        }

        for (int i = ci-1; i >= 0; i--) {
            head2 = new ListNode(impares[i], head2);
            c--;
        }

    }

    
    //printList(head2);
    return head2;
    /*
    while (curr != nullptr) {
        if (c % 2 == 0) {
            no = new ListNode(curr->val, no);
            curr = curr->next;
        }
        curr = curr->next;
        c++;
    }*/

    //cout << head-> val;
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

    head = oddEvenList(head);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}