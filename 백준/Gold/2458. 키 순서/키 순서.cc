#include <iostream>
#include <vector>
#include <stack>

uint32_t dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int start) {
    std::stack<int> stack;
    int cnt = 0;

    stack.push(start);
    while(!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (visited[node]) continue;
        visited[node] = true;
        if (start != node) cnt++;
        for(int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                stack.push(graph[node][i]);
            }
        }
    }
    return cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph_bigger(n+1);
    std::vector<std::vector<int>> graph_smaller(n+1);
    for(int i = 0; i < m; i++) {
        int s, b;
        std::cin >> s >> b;
        graph_bigger[s].push_back(b);
        graph_smaller[b].push_back(s);
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        std::vector<bool> visited_bigger(n+1, false);
        cnt += dfs(graph_bigger, visited_bigger, i);

        std::vector<bool> visited_smaller(n+1, false);
        cnt += dfs(graph_smaller, visited_smaller, i);
        if (cnt == n-1) {
            res++;
        }
    }
    std::cout << res;
}

/*
처음 각 노드 별로 탐색을 진행하며 "노드에 도달"하는 + "노드에서 출발"하는 모든 노드들을 찾아야되나? 이ㄹ 찾기 위해 어떻게 구상해야되지? 고민
- 모든 노드를 탐색하는 것과 탐색 시 방문 노드들을 계속해서 관리해야되는 부담이 크다 생각

그래서 고려한 로직은 일방향 그래프 2개를 활용하는 것
- 더 큰 노드를 가리키는 일방향 그래프와 더 작은 노드를 가리키는 일방향 그래프 사용
- 모든 노드를 순회하며 2개의 일방향 그래프 DFS 탐색을 진행하고 자신을 제외한 n-1개의 노드를 탐색하는 노드를 체크
*/