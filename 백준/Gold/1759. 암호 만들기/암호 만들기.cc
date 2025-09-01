#include <iostream>
#include <vector>
#include <algorithm>

void check_condition(std::vector<char> vec, std::vector<bool> visited) {
    int parent = 0, child = 0;
    std::string str = "";
    for(int i = 0; i < vec.size(); i++) {
        if (visited[i]) {
            int t = vec[i];
            if (t == 97 || t == 101 || t == 105 || t == 111 || t == 117) {
                parent++;
            } else {
                child++;
            }
            str += vec[i];
        }
    }
    if (parent >= 1 && child >= 2) {
        std::cout << str << std::endl;
    }
}

void comb(std::vector<char> vec, std::vector<bool> visited, int start, int len, int max) {
    if (len == max) {
        check_condition(vec, visited);
    }

    for(int i = start; i < vec.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            comb(vec, visited, i+1, len+1, max);
            visited[i] = false;
        }
    }
}

int main() {
    std::vector<char> vec;
    int l, c;
    std::cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char t;
        std::cin >> t;
        vec.push_back(t);
    }
    std::sort(vec.begin(), vec.end());

    std::vector<bool> visited(vec.size()+1, false);
    comb(vec, visited, 0, 0, l);
}