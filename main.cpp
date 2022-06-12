#include <iostream>
#include <string>
#include <stack>

using namespace std;

int IsNorm(string  str) {
    stack <char> steck;
    stack <int> steck2;
    char c;
    int j;

    for(j = 0; j < str.length(); j++) {

        c = str[j];
        if( c != '[' and c != '(' and c != '{' and c != ']' and c != ')' and c != '}' ) {
            continue;
        }

        if(steck.empty()) {
            if( c == ']' or c == ')' or c == '}' ) {
                cout << (j+1);
                return (j+1);
            }
            steck.push(c);
            steck2.push(j+1);
        }
        else {
            if( c == '[' or c == '(' or c == '{' ) {
                steck.push(c);
                steck2.push(j+1);
            }
            if( (c == ']' and steck.top() != '[') or (c == ')' and steck.top() != '(') or
               (c == '}' and steck.top() != '{') ) {
                cout << (j+1);
                return (j+1);
            }
            if( (c == ']' and steck.top() == '[') or (c == ')' and steck.top() == '(') or
              (c == '}' and steck.top() == '{') ) {
                steck.pop();
                steck2.pop();
            }
        }
    }
    if(steck.empty()) {
        cout << "Success";
        return 0;
    }
    cout << steck2.top();
    return 0;
}

int main() {
    string str;
    cin >> str;
    IsNorm(str);
    return 0;
}
