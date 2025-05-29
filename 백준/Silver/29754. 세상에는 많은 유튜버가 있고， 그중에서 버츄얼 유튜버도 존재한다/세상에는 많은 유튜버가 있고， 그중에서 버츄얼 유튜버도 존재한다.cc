#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;

    std::map<std::string, std::array<std::pair<int, int>, 53>> data;

    std::cin >> n >> m;
    int all_period = m % 7 != 0 ? m / 7 + 1 : m / 7;

    for(int i = 0; i < n; i++) {
        std::string name, start_time, end_time;
        int day;
        std::cin >> name >> day >> start_time >> end_time;
        

        int period = day % 7 != 0 ? day / 7 + 1 : day / 7;

        int start_hour = std::stoi(start_time.substr(0,2));
        int start_minute = std::stoi(start_time.substr(3,2));
        int end_hour = std::stoi(end_time.substr(0,2));
        int end_minute = std::stoi(end_time.substr(3,2));

        int total_start_minute = start_hour * 60 + start_minute; 
        int total_end_minute = end_hour * 60 + end_minute;
        int minute = total_end_minute - total_start_minute;

        data[name][period].first += 1;
        data[name][period].second += minute;
    }
 
    std::vector<std::string> real_youtuber;
    for(const auto& entry : data) {
        int cnt = 0;
        for(int i = 1; i <= all_period; i++) {
            if (entry.second[i].first < 5) {
                break;
            }
            if (entry.second[i].second < 3600) {
                break;
            }
            cnt++;
        }
        if (cnt == all_period) {
            real_youtuber.push_back(entry.first);
        }
    }

    if (real_youtuber.size() == 0) {
        std::cout << -1;
    } else {
        for(const auto& name : real_youtuber) {
            std::cout << name << std::endl;
        }
    }
}

/*
초기에는 아래 구조로 풀려고 했었다.
name
    period
        total count, total minute
이 경우 모든 계층마다 자료 구조를 사용하면 map : vector : pair 순으로 구성될거고 유저 정보가 들어올 때마다 vector를 순회하면서 period(주 차)를 찾아야되는 문제 존재
=> 너무 비효율적

문제 구조상 최대 100명, 최대 52주 차, total count, minute 해도 int로 커버가 될 것 같아서 array index를 period로 간주하는 방식으로 진행
100 * (52 * (4 + 4))byte 정도여서 충분히 가능할 것 같다고 판단
*/