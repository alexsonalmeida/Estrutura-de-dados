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

int listaMaior(ListNode* lis1, ListNode* lis2) {
    ListNode* listaTeste = lis1;
    ListNode* listaTeste2 = lis2;

    while (listaTeste != nullptr) {
        if (listaTeste->next != nullptr) {
            if (listaTeste2->next == nullptr) {
                return 1;
                break;
            }
        } else if(listaTeste2->next != nullptr) {
            return 2;
            break;
        } else {
            return 1;
            break;
        }
        listaTeste = listaTeste->next;
        listaTeste2 = listaTeste2->next;
    }
}

ListNode * intersectionList(ListNode * head1, ListNode * head2) {
    int listIdentifier = listaMaior(head1, head2);
    ListNode* maiorLista = nullptr;
    ListNode* menorLista = nullptr;
    vector<int> elements;
    int tam = 0;    
    

    if (listIdentifier == 1) {
        maiorLista = head1;
        menorLista = head2;
    } else {
        maiorLista = head2;
        menorLista = head1;
    }

    ListNode* curr = maiorLista;
    ListNode* currSmall = menorLista;

    vector<int> vetMenor;
    int tamMenor = 0;
    int i = 0;

    while (currSmall != nullptr) {
        if (i == 0) {
            vetMenor.push_back(currSmall->val);
            tamMenor++;  
        } else {
            if (currSmall->val != vetMenor[i]) {
                vetMenor.push_back(currSmall->val);
                tamMenor++;            
            }            
        }
        i++;
        currSmall = currSmall->next;
    }

    while (curr != nullptr) {
        if (curr->next != nullptr) {
            if (curr->val != curr->next->val) {
                for (int i = 0; i < tamMenor; i++) {
                    if (curr->val == vetMenor[i]) {
                        elements.push_back(vetMenor[i]);
                        tam++;
                        break;
                    }
                }
            }            
        } else {
            for (int i = 0; i < tamMenor; i++) {
                if (curr->val == vetMenor[i]) {
                    elements.push_back(vetMenor[i]);
                    tam++;
                    break;
                }
            }         
        }
        curr = curr->next;
    }

    ListNode* res1 = nullptr; 
    if (tam == 1) {
        ListNode* res = new ListNode(elements[0]);
        return res;
    } else {
        for (i = tam-1; i >= 0; i--) {
            if (i == tam-1 || i > 0) {
                ListNode* no = new ListNode(elements[i], res1);
                res1 = no;
            }

            if (i == 0) {
                ListNode* res = new ListNode(elements[0], res1);
                return res;
            }
        }        
    }
}

void printList(ListNode * head) {
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}

int main(){
    ListNode * head1 = readList();
    ListNode * head2 = readList();
     
    ListNode * res = intersectionList(head1, head2);

    printList(res);

    return 0;    
}