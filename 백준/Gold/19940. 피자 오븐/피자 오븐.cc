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

/*
문제를 잘못 이해하고 [60, 10, -10, 1, -1] 구성에서 횟수가 같은 경우 가장 왼쪽 요소를 우선 선택해서 진행하는 방식으로 진행함.
당연히 틀렸고 bfs 이용해서 t를 계속해서 증가시키면서 배열 요소는 오른쪽부터 더해주고 최초로 방문하는 0~60 요소들을 최신화하면서 저장.
    입력(t) 받았을 때 60으로 나눠 value[나머지]의 60 부분에 더하고 value 출력
        이 때 value를 직접 사용하면 입력이 늘어날수록 계속해서 누적되기에 입력마다 value[나머지]를 복사해 사용
*/