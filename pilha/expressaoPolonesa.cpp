#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
using namespace std;

string expr;
int pos = 0;

string get_token() {
    string token = "";
    
    if(pos == expr.size() ){
        token = "$";
        return token;
    }
    
    while( expr[pos] == ' ') pos++;

    if(expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '/' || expr[pos] == '*'){
        token = token + expr[pos];
        pos++;
        return token;
    }
    else if(isdigit(expr[pos]) ){
        while( isdigit(expr[pos]) ){
            token = token + expr[pos];
            pos++;
        }
        return token;
    }

    return token;
}

int main(){
    getline( cin, expr );
    stack <int> s;
    string token = get_token();
    while(token != "$") {
        int num1, num2;
        if (token == "+") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            int soma = num1 + num2;
            s.push(soma);
        } else if (token == "-") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            int dif = num1 - num2;
            s.push(dif);           
        } else if (token == "*") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            int mul = num1 * num2;
            s.push(mul);          
        } else if (token == "/") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            int div = num1 / num2;
            s.push(div);        
        } else {
            s.push( atoi(token.c_str() ) );
        }
        
        token = get_token();
    }

    while (s.empty() == false) {
        cout << s.top() << endl;
        s.pop();
    }
}