#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, start, end, cnt;
    std:: cin >> n >> start >> end >> cnt;
    std::vector<std::vector<int>> graph(n+1, std::vector<int>(0, {}));
    std::vector<bool> visited(n+1, false);
    while(cnt) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cnt--;
    }

    

    std::stack<std::vector<int>> stack;
    if (graph[start].size() == 0) {
        std::cout << -1;
        return 0;
    }

    stack.push({start, 0});
    while(!stack.empty()) {
        std::vector<int> top = stack.top();
        int node = top[0], depth = top[1];
        stack.pop();
        visited[node] = true;
        
        if (node == end) {
            std::cout << depth;
            return 0;
        }

        for(auto& a: graph[node]) {
            if (!visited[a]) {
                stack.push({a, depth+1});
            }
        }
    }

    std::cout << -1;
}