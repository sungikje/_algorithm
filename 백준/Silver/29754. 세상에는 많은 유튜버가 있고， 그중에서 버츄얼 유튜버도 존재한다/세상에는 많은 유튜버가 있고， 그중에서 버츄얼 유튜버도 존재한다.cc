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