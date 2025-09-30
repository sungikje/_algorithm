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