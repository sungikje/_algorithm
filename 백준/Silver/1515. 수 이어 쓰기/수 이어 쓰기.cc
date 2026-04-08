#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);

    std::string s;
    std::cin >> s;

    int num = 0;
    int str_idx = 0;
    bool fully_checked = false;
    while(true) {
        num++;
        std::string s_num = std::to_string(num);
        for(int i = 0; i < s_num.length(); i++) {
            if (s_num[i] == s[str_idx]) {
                str_idx++;
                if (str_idx >= s.length()){
                    fully_checked = true;
                    break;
                }
            }
        }
        if (fully_checked) {
            break;
        }
    }
    std::cout << num;
}