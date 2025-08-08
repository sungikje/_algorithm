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
