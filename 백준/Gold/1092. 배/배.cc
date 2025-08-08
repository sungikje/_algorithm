#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n;
    std::vector<int> craines;
    std::list<int> boxes;
    
    for(int i = 0 ; i < n; i++) {
        int t;
        std::cin >> t;
        craines.push_back(t);
    }

    std::cin >> m;
    for(int i = 0 ; i < m; i++) {
        int t;
        std::cin >> t;
        boxes.push_back(t); 
    }
    std::sort(craines.begin(), craines.end(), std::greater<int>());
    boxes.sort(std::greater<int>());

    if (*boxes.begin() > craines[0]) {
        std::cout << -1;
        return 0;
    }

    int time = 0;
    while (boxes.size() > 0) {
        auto box_it = boxes.begin();
        for(auto& i : craines) {
            while(box_it != boxes.end() && i < *box_it) {
                box_it++;
            }
            
            if (box_it != boxes.end()) {
                box_it = boxes.erase(box_it);
            }
        }
        time++;
    }

    std::cout << time;
}

/*
처음 진행했던 로직(시간 초과)은 아래와 같다. 
while (use time check)
    for (cranes)
        for (boxes)
이는 (x * cranes * boxes) = (x * 50 * 10000)으로 x가 200만 된다고 해도 초과 발생

구현하고자 했던 로직은 cranes가 1바퀴 돌 때 boxes도 1바퀴 도는 로직이었는데 반복문을 2번 중첩하며 시간 초과가 발생했다.
*/