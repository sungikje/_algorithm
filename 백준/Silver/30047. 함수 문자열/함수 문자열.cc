#include <iostream>
#include <string>
#include <array>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    std::string s;
    std::cin >> s;
    int len = s.length();
    std::stack<int> stack;
    bool invalid = false;

    for(int i = len-1; i >= 0; i--) {
        if(s[i] == 'x') {  
            stack.push(0);
        } else if (s[i] == 'g') {
            if (stack.size() < 1) {
                invalid = true;
                break;
            } else {
                int top = stack.top();
                stack.pop();
                stack.push(top + 1);
            }
        } else {
            if (stack.size() < 2) {
                invalid = true;
                break;
            } else {
                int top = stack.top();
                stack.pop();
                int top_1 = stack.top();
                stack.pop();
                int max = top > top_1? top_1 : top;
                stack.push(max);
            }
        }
    }

    if (stack.size() == 1 && !invalid) {
        std::cout << stack.top();
    } else {
        std::cout << -1;
    }
}