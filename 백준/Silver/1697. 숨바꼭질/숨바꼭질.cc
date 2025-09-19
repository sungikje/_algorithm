#include <iostream>
#include <queue>
#include <vector>

void push_q(std::queue<std::vector<int>>& q, std::vector<bool> visited, int loc, int cnt) {
    int new_loc = loc-1;
    int new_cnt = cnt+1;
    if (!visited[new_loc] && 0 <= new_loc && new_loc <= 100000) {
        q.push({new_loc, new_cnt});
    }
    
    new_loc = loc+1;
    if (!visited[new_loc] && 0 <= new_loc && new_loc <= 100000) {
        q.push({new_loc, new_cnt});
    }

    new_loc = loc*2;
    if (!visited[new_loc] && 0 <= new_loc && new_loc <= 100000) {
        q.push({new_loc, new_cnt});
    }
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::queue<std::vector<int>> q;
    std::vector<bool> visited(100001, false);
    q.push({n, 0});
    while(!q.empty()) {
        std::vector<int> front = q.front();
        int loc = front[0], cnt = front[1];
        visited[loc] = true;
        q.pop();

        if (loc == k) {
            std::cout << cnt;
            return 0;
        }
        push_q(q, visited, loc, cnt);
    }
}

/*
방문했던 노드를 굳이 또 방문할 필요는 없다. 방문 여부를 체크하지 않는 경우 메모리 초과 발생
*/