#include <iostream>
#include <vector>
#include <stack>

int dfs(std::vector<std::vector<int>>& graph, std::vector<int>& visited, int start) {
    std::stack<std::vector<int>> stack;
    bool is_round = false;

    stack.push({start, 0});
    while(!stack.empty()) {
        std::vector<int> node_info = stack.top();
        int node = node_info[0], parent = node_info[1];
        stack.pop();

        if (visited[node]) {
            continue;
        }
        visited[node] = true;

        for(int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                stack.push({graph[node][i], node});
            } else {
                if (graph[node][i] != parent) {
                    is_round = true;
                }
            }
        }
    }

    return is_round? false : true;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n = -1, m = -1;
    int case_cnt = 1;
    while (true) {
        std::cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        std::vector<std::vector<int>> graph(n+1);
        std::vector<std::vector<int>> graph_reverse(n+1);
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            int s, e;
            std::cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }
        
        std::vector<int> visited(n+1, false);
        for(int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cnt += dfs(graph, visited, i);
            }
        }

        if (cnt == 0) {
            std::cout << "Case " << case_cnt<< ": No trees.\n";
        } else {
            if (cnt == 1) {
                std::cout << "Case " << case_cnt<< ": There is one tree.\n";
            } else {
                std::cout << "Case " << case_cnt<< ": A forest of " << cnt << " trees.\n";
            }
        }
        case_cnt++;
    }
}