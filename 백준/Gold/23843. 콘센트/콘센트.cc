#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::priority_queue<int, std::vector<int>, std::less<int>> electric_device;
    std::priority_queue<int, std::vector<int>, std::greater<int>> outlet;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        electric_device.push(t);
    }
    
    while(!electric_device.empty()) {
        if (outlet.size() < m) {
            outlet.push(electric_device.top());
        } else {
            int top = outlet.top();
            outlet.pop();
            outlet.push(top + electric_device.top());
        }
        electric_device.pop();
    }
    
    int time = 0;
    while(!outlet.empty()) {
        time = outlet.top();
        outlet.pop();
    }
    
    std::cout << time;

}