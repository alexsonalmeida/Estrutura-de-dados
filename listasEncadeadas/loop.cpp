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
    int n, x;
    cin >> n >> x;
    ListNode * head;
    ListNode * tmp = nullptr;

    ListNode * ptr;
        
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        
        if(i == 1){
            head = new ListNode(v);
            ptr = head;
        } else {
            ptr->next = new ListNode(v, nullptr);
            ptr = ptr->next;
        }

        if(i == x){
            tmp = ptr;
        }
    }

    ptr->next = tmp;
    return head;

}

void print_list(ListNode * head){
    cout << "\n";
    for(auto ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << endl;
    }
}

bool detectLoop(ListNode* head) {
    ListNode* curr = head;
    ListNode* slow = head;
    ListNode* fast = head;

    int c = 1;

    while (curr != nullptr) {
            slow = slow->next;

            if (fast->next == nullptr) {
                return false;
                break;
            }

            fast = fast->next->next;

            if (slow->val == fast->val) {
                return true;
                break;
            } 
            curr = curr->next;
            c++;
    }   
}

int main() {
    ListNode * head = readList();
    
    cout << detectLoop(head) << endl;

    return 0;    
}