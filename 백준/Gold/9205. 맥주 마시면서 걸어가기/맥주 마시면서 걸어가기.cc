#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<std::vector<int>> loc;
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        std::vector<std::vector<int>> loc;
        std::string res = "sad";
        int convenience_cnt;
        std::cin >> convenience_cnt;

        // starting point
        int loc_x, loc_y;
        std::cin >> loc_x >> loc_y;
        loc.push_back({loc_x, loc_y});
        
        // convenience
        for(int j = 0; j < convenience_cnt; j++) {
            std::cin >> loc_x >> loc_y;
            loc.push_back({loc_x, loc_y});
        }

        // destination
        std::cin >> loc_x >> loc_y;
        loc.push_back({loc_x, loc_y});

        // make edge
        std::vector<std::vector<int>> edge(loc.size());
        for(int j = 0; j < loc.size(); j++) {
            int node_x = loc[j][0], node_y = loc[j][1];
            for (int k = j+1; k < loc.size(); k++) {
                int dest_x = loc[k][0], dest_y = loc[k][1];
                if (1000 >= abs(node_x - dest_x) + abs(node_y - dest_y)) {
                    edge[j].push_back(k);
                    edge[k].push_back(j);
                }
            }
        }

        std::queue<int> q;
        std::vector<int> visited(edge.size(), false);
        q.push(0);
        visited[0] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == edge.size() - 1) {
                res = "happy";
                break;
            }

            for(int j = 0; j < edge[node].size(); j++) {
                if (!visited[edge[node][j]]) {
                    q.push(edge[node][j]);
                    visited[edge[node][j]] = true;
                }
            }
        }
        std::cout << res << std::endl;
    }
}

/*
처음에 노드 간 거리를 고려하는 것이 아니라 2차원 배열로 진행해서 틀림.
단방향 노드로 처리해 틀림.

양방향 노드로 성공.
위의 코드를 단방향으로 처리한다면 나보다 큰 노드들과의 간선만 연결되는 형태. 
처음엔 탐색하면서 앞으로 갈 일이 있나? 방문처리가 되어 있을텐데 생각했지만 아래 예시를 보면 간선이 끊기는 것을 알 수 있다.
< 단방향 >
탐색하며 자신보다 큰 노드들만 간선이 연결. 이 경우 0(시작점)->3으로 간선이 끊긴다.
0: 3
1: 3
2:
3:
< 양방향 >
이 경우 0(시작점)->3->1로 간선이 끊기지 않는다.
0: 3
1: 3
2: 
3: 0, 1
*/