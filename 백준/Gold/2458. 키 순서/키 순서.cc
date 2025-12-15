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
