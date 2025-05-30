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

/*
처음엔 괄호의 역활을 무시하고 단순히 입력 받은 문자열을 뒤에서부터 순차적으로 f, g, x를 연속적으로 합치는게 문제 조건이라 판단했엇음

오답이었고, stack을 기반으로 f, g의 연산을 반복하며 하나의 정수값(stack size == 0)으로 귀결될 수 있는지로 판단
    
*/