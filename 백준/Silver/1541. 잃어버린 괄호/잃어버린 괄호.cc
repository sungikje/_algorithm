#include <iostream>
#include <sstream>

int main () {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);

    std::string input;
    std::cin >> input;
    std::stringstream ss(input);

    int sum = 0;
    int tmp_sum = 0;
    bool minus_state = false;

    int num;
    char op;
    ss >> sum;
    while(ss >> op >> num) {
        if (minus_state) {
            if (op == '+') {
                tmp_sum += num;
            } else {
                sum -= tmp_sum;
                tmp_sum = num;
            }
        } else {
            if (op == '+') {
                sum += num;
            } else {
                tmp_sum += num;
                minus_state = true;
            }
        }
    }
    sum -= tmp_sum;
    std::cout << sum;
}