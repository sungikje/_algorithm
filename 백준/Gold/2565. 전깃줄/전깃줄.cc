#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int electric_wire_cnt;
    std::cin >> electric_wire_cnt;
    std::vector<int> node(501, 0);
    std::vector<int> dp(501, 0);
    int max_wire_cnt = 0;
    for(int i = 0; i < electric_wire_cnt; i++) {
        int start, end;
        std::cin >> start >> end;
        node[start] = end;
        if (max_wire_cnt < start) max_wire_cnt = start;
    }

    int max = 0;
    for(int i = 1; i <= max_wire_cnt; i++) {
        int sub_max = 1;
        if (node[i] != 0) {
            for(int j = i-1; j >= 1; j--) {
                if (node[j] < node[i] && sub_max <= dp[j]) {
                    sub_max = dp[j]+1;
                }
            }
            dp[i] = sub_max;
            if (sub_max > max) {
                max = sub_max;
            }
        }
    }
    std::cout << electric_wire_cnt - max;
}

/*
최초 겹치는 것을 방지하기 위해 1~... 순회할 때 이 전에 도달한 상대 노드보다 더 큰 상대 노드가 나와야 한다는 개념은 인지했지만 점화식을 정확히 찾지 못하고 반례만 맞췄었음.
LSI 알고리즘 이용해 해결
*/