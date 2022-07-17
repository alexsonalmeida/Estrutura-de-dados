#include <iostream>
#include <stack>

using namespace std;

template <class T>

class StackMin {
    private:
        stack <T> data;
        stack <T> min;
    public:
        void push(T x) {
            data.push(x);
            if (min.empty()) {
                min.push(x);
            } else {
                if (data.top() < min.top()) {
                    min.push(x);
                } else {
                    min.push(min.top());
                }
            }
        }

        bool empty() {
            return data.empty();
        }

        T top() {
            return data.top();
        }

        void pop() {
            data.pop();
            min.pop();
        }

        T getmin() {
            return min.top();
        }
};

int main() {
    int n;
    StackMin <int> s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int op, x;
        cin >> op;

        if (op == 1) {
            cin >> x;
            s.push(x);
        } else if (op == 2) {
            s.pop();
        } else {
            cout << s.getmin() << endl;
        }
    }
}