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
    visited[n] = true;
    while(!q.empty()) {
        std::vector<int> front = q.front();
        int loc = front[0], cnt = front[1];
        q.pop();
        if (loc == k) {
            std::cout << cnt;
            break;
        }

        int new_loc = loc * 2;
        if (new_loc <= 100000 && !visited[new_loc]) {
            q.push({new_loc, cnt});
            visited[new_loc] = true;
        }  

        new_loc = loc - 1;
        if (0 <= new_loc && !visited[new_loc]) {
            q.push({new_loc, cnt+1});
            visited[new_loc] = true;
        }

        new_loc = loc + 1;
        if (new_loc <= 100000 && !visited[new_loc]) {
            q.push({new_loc, cnt+1});
            visited[new_loc] = true;
        }
    }
}
/*
최초 성공 로직(숨바꼭질 3-1.cc 참고)
    q pop할 때 visited를 체크하며 진행.
    push 순서는 +1, -1, *2

두번째 성공 로직
    q push할 때 visited를 체크
    push 순서는 위에처럼 *2, -1, 1

두번째 로직이 시간, 공간 복잡도가 훨씬 줄어든다.
    공간 복잡도는 visited 여부 때문에 그럴 것 같고.

이유
    BFS에서 q에 최소 비용부터 넣는 것이 가장 중요.
    두번째 로직에서 -1을 먼저 큐에 넣는 이유는 만약 +1을 먼저 넣게 되면 노드에 최단 거리로 접근하지 못하는 경우가 발생한다.
        *2, +1은 우측 방향. -1은 좌측 방향으로 향하며 우측 노드에 (-1 후에 *2)로 접근하는게 (+1)로 접근하는 것보다 더 최단 거리이다.
        만약 +1을 먼저 큐에 추가한 경우 이미 방문 체크가 되어 최소 거리가 유효하지 않게 된다.
*/