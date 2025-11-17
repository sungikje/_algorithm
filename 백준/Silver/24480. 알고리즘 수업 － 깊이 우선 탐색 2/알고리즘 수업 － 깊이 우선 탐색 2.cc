#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, r;
    std::cin >> n >> m >> r;

    std::vector<std::vector<int>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        std::sort(graph[i].begin(), graph[i].end()); 
    }

    std::vector<int> res(n+1, 0);
    std::vector<bool> visited(n+1, false);

    std::stack<int> st;
    st.push(r);
    int order = 1;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited[node]) continue;
        visited[node] = true;

        res[node] = order++;

        for (int i = 0; i < graph[node].size(); i++) {
            int nxt = graph[node][i];
            if (!visited[nxt]) st.push(nxt);
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << res[i] << "\n";
    }
}

/*
"\n" 대신 std::endl을 사용했을 때 시간초과 발생
*/