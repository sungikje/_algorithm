#include <iostream>
#include <array>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    struct _time {
        int p_60;
        int p_10;
        int m_10;
        int p_1;
        int m_1;
        int t;
    };
    std::array<bool, 61> visited = {false};
    std::array<struct _time, 61> value = {{0, 0, 0, 0, 0, 0}};
    std::queue<struct _time> q;

    q.push({0, 0, 0, 0, 0, 0});
    while(!q.empty()) {
        struct _time tmp = q.front();
        q.pop();
        if (!visited[tmp.t] && (0 <= tmp.t && tmp.t <= 60)){
            visited[tmp.t] = true;
            value[tmp.t] = tmp;
            q.push({tmp.p_60, tmp.p_10, tmp.m_10, tmp.p_1, tmp.m_1 + 1, tmp.t-1});
            q.push({tmp.p_60, tmp.p_10, tmp.m_10, tmp.p_1 + 1, tmp.m_1, tmp.t+1});
            q.push({tmp.p_60, tmp.p_10, tmp.m_10 + 1, tmp.p_1, tmp.m_1, tmp.t-10});
            q.push({tmp.p_60, tmp.p_10 + 1, tmp.m_10, tmp.p_1, tmp.m_1, tmp.t+10});
            q.push({tmp.p_60 + 1, tmp.p_10, tmp.m_10, tmp.p_1, tmp.m_1, tmp.t+60});
        }
    }

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        
        int v = t / 60;
        int r = t % 60;
        struct _time tmp = value[r];
        tmp.p_60 += v;
        std::cout << tmp.p_60 << " " << tmp.p_10 << " " << tmp.m_10 
                            << " " << tmp.p_1 << " " << tmp.m_1 << std::endl;
    }
}