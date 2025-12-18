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

/*
최초 로직은 부모->자식(graph), 자식->부모(graph_reverse) 일방향 그래프 2개를 이용해 경로를 탐색하면서 cycle을 확인하려고 했다.
다만 이 과정에서 graph 탐색 후 현재 시작 node 방문을 취소하고 graph_reverse를 탐색하며 진행
    - 이 경우는 양방향 그래프가 아니라 부모<->자식을 각 각 분리해 고려하며 노드들의 연결 상태를 온전히 보장하지 못한다. 중간에 끊어질 가능성이, 트리가 쪼개지는 문제가 존재한다는 의미이다.
수정한 로직은 양방향 그래프로 설정을 하고 현재 노드가 방문할 수 있는 노드가 "이미 방문되었으며 부모가 아닌 경우"를 cycle로 간주하며 개선했다.
*/