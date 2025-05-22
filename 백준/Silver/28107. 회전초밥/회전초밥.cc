/*
처음에 set을 이용해서 모든 유저들의 먹고 싶은 초밥을 vector<set>으로 저장하고 초밥 만들 때마다 vector 순회하면서 진행
vector를 하나 하나 순회하면서 set find하고 있는 경우 erase 하는 방식으로 진행
    m == 200,000, n == 100,000인 경우 시간초과

두번째는 손님의 순서를 유지하기 위해 우선 순위 큐를 이용
그리고 입력할 때 같은 손님이 중복으로 초밥을 주문하는 것을 방지했으며 초밥을 만들 때 해당 초밥을 주문한 사람이 있는 경우 체크
    이 때 empty() 검사를 하지 않아 틀림. empty 검사를 추가하며 성공
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int n, m;

    std::cin >> n;
    std::cin >> m;
    std::vector<int> result(n, 0);

    std::map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> info;

    for(int i = 0; i < n; i++) {
        int cnt;
        std::cin >> cnt;

        std::unordered_set<int> seen;

        for(int j = 0; j < cnt; j++) {
            int sushi;
            std::cin >> sushi;

            if (!seen.count(sushi)) {
                info[sushi].push(i);
                seen.insert(sushi);
            }
        }
    }

    for(int i = 0; i < m; i++) {
        int sushi;
        std::cin >> sushi;

        if (info.find(sushi) != info.end()) {
            if (info[sushi].empty()) continue; 
            int customer = info[sushi].top();
            result[customer]++;
            info[sushi].pop(); 
        }
    }
    for(auto& i : result) {
        std::cout << i << " ";
    }
}
