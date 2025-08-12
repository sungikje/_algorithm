#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<std::pair<int, int>> vec;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e;
        std::cin >> s >> e;
        vec.push_back(std::make_pair(s, e));
    }

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });

    std::priority_queue<int, std::vector<int>, std::greater<int>> rooms;
    for(int i = 0; i < vec.size(); i++) {
        if (rooms.empty()) {
            rooms.push(vec[i].second);
        } else {
            if (rooms.top() <= vec[i].first) {
                rooms.pop();
            }
            rooms.push(vec[i].second);
        }     
    }
    std::cout << rooms.size();
}

/*
최초 실패하던 로직은 아래와 같다.
    list를 이용해 회의실(pair)을 순회하며 겹치지 않는 회의들을 그룹화해서 그룹이 몇 개인지 체크
    이는 회의 진행을 병렬로 고려한 것이 아니라 직렬로 고려한 로직
        같은 날의 동시에 진행이되는 경우도 고려해야되는데 그룹들이 서로 다른 날 진행되는 것처럼 구함

회의가 동시에 진행될 수 있게끔 로직을 수정
    pq로 회의실 갯수를 관리하며 진행 
    1. 회의 시작, 종료 시각은 vector로 받아 시작 시각이 빠른 순서로 정렬
    2. 회의 시작, 종료 시각을 순회하면서 현재 진행 중인 회의 종료 시각이 시작 시각보다 작은 경우 pop, 그 외는 새로운 회의실 추가

*/