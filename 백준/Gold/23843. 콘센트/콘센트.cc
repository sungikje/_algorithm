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

/*
초기 로직은 outlet에서 top을 추출하고 outlet을 순회하면서 top만큼 뺐을 때 0보다 작은 경우만 tmp_outlet이라는 별도의 priority queue에 저장하며 outlet = tmp_outlet으로 진행했다.
하지만 위의 로직은 1개가 남았을 때의 시간을 고려하지 않았고 이를 추가하기에는 코드가 난잡해짐
=> 콘센트의 누적 합을 구하는 것이기 때문에 electric_device, outlet 정렬 기준은 그대로 가져가되 콘센트(outlet)이 다 채워진 경우와 아닌 경우를 나눠가며 누적합을 계산했다.
*/