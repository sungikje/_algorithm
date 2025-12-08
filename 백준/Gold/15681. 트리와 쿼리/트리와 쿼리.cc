#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void dfs(std::vector<std::vector<int>>& nodes, std::vector<int>& parents, std::vector<int>& visited, std::vector<std::vector<int>>& depth_map, int node) {
    std::stack<std::vector<int>> stack;
    stack.push({node, 1});

    while(!stack.empty()) {
        std::vector<int> info = stack.top();
        stack.pop();

        int n = info[0], d = info[1];
        if (visited[n] > 0) continue;
        visited[n] = d;
        depth_map.push_back({n, d});
        for(auto& i: nodes[n]) {
            if (!visited[i]) {
                parents[i] = n;
                stack.push({i, d+1});
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, r, q;
    std::cin >> n >> r >> q;
    std::vector<std::vector<int>> nodes(n+1);
    std::vector<int> parents(n+1);
    std::vector<int> visited(n+1, 0);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    
    std::vector<int> us(q);
    for(int i = 0; i < q; i++) {
        std::cin >> us[i];
    }

    std::vector<std::vector<int>> depth_map;
    dfs(nodes, parents, visited, depth_map, r);
    std::sort(depth_map.begin(), depth_map.end(), [](std::vector<int> a, std::vector<int> b) {
        if (a[1] > b[1]) {
            return true;
        }
        return false;
    });

    std::vector<int> weight(n+1, 1);
    for(auto& i: depth_map) {
        int n = i[0];
        weight[parents[n]] += weight[n];
    }

    for(auto& i: us) {
        std::cout << weight[i] << "\n";
    }
}
