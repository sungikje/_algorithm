#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<bool> visited(100001, false);
    std::queue<std::vector<int>> q;
    q.push({n, 0});
    int min = 100000;
    while(!q.empty()) {
        std::vector<int> front = q.front();
        int loc = front[0], cnt = front[1];
        visited[loc] = true;
        q.pop();
        if (loc == k) {
            if (cnt < min) min = cnt;
        }

        int new_loc = loc + 1;
        if (new_loc <= 100000 && !visited[new_loc]) {
            q.push({new_loc, cnt+1});
        }

        new_loc = loc - 1;
        if (0 <= new_loc && !visited[new_loc]) {
            q.push({new_loc, cnt+1});
        }

        new_loc = loc * 2;
        if (new_loc <= 100000 && !visited[new_loc]) {
            q.push({new_loc, cnt});
        }   
    }
    std::cout << min;
}
/*
여기서 성공한 이유는 아래와 같다.
    pop할 때 방문을 체크하기 때문에 q에 노드가 중복해서 들어간다.
    loc == k 일 때 최소 값을 계속해서 최신화하기 때문에 마지막에 출력되는 값은 최소 값이된다.
    하지만 노드가 중복되기 때문에 공간 복잡도는 올라간다.
*/