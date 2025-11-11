#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, start, end, cnt;
    std:: cin >> n >> start >> end >> cnt;
    std::vector<std::vector<int>> graph(n+1, std::vector<int>(n, 0));
    std::vector<bool> visited(n+1, false);
    while(cnt) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cnt--;
    }

    std::queue<std::vector<int>> q;
    for(auto& a: graph[start]) {
        q.push({a, 1});
        visited[a] = true;
    }

    while (!q.empty()) {
        std::vector<int> node_info = q.front();
        int node = node_info[0], depth = node_info[1];
        q.pop();

        if (node == end) {
            std::cout << depth;
            return 0;
        }

        for(auto& a: graph[node]) {
            if (!visited[a]) {
                q.push({a, depth+1});
                visited[a] = true;
            }
        }
    }
    std::cout << -1;
}

/*
위의 코드는 BFS를 이용한 코드이고 DFS로도 한번 풀어보자
*/