#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* curr1 = l1;
    ListNode* curr2 = l2;
    vector<int> vet;
    int tam = 0;

    while (curr1 != nullptr) {
        vet.push_back(curr1->val);
        curr1 = curr1->next;
        tam++;
    }

    while (curr2 != nullptr) {
        vet.push_back(curr2->val);
        curr2 = curr2->next;
        tam++;
    }

    sort(vet.begin(), vet.end());

    ListNode* res1 = nullptr; 
    if (tam == 1) {
        ListNode* res = new ListNode(vet[0]);
        return res;
    } else {
        for (int i = tam-1; i >= 0; i--) {
            if (i == tam-1 || i > 0) {
                ListNode* no = new ListNode(vet[i], res1);
                res1 = no;
            }

            if (i == 0) {
                ListNode* res = new ListNode(vet[0], res1);
                return res;
            }
        }        
    }
}

ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head = nullptr;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if (i == 0) {
            head = new ListNode(x);
            ptr = head;
        } else {
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;
}

int main() {
    ListNode * list1 = readList();
    ListNode * list2 = readList();
    ListNode * head = mergeTwoLists(list1, list2);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}