#include <iostream>
#include <vector>

void update(int x, int y, std::vector<std::vector<int>>& distance, std::vector<std::vector<int>> dire) {
    int idx = 0;
    int dist = 1;
    int new_x = x, new_y = y;
    while (true) {
        new_x += dire[idx][0];
        new_y += dire[idx][1];
        if (!(0 <= new_x && new_x < distance.size() && 0 <= new_y && new_y < distance[0].size())) {
            new_x -= dire[idx][0];
            new_y -= dire[idx][1];
            idx++;
            if (idx >= dire.size()) {
                break;
            }
            continue;
        }

        if (distance[new_x][new_y] > dist) {
            distance[new_x][new_y] = dist;
        }
        dist++;

        if (new_x == x && new_y == y) {
            break;
        }
    }
}

void change_format(int* a, int* b, int x_max, int y_max) {
    if (*a == 1) {
        *a = 0;
    } else if (*a == 2) {
        *a = x_max; 
    } else if (*a == 3) {
        *a = *b;
        *b = 0;
    } else {
        *a = *b;
        *b = y_max;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x_max, y_max, n;
    std::cin >> y_max >> x_max;
    int max_v = x_max > y_max ? x_max : y_max;
    std::vector<std::vector<int>> distance(x_max+1, std::vector<int>(y_max+1, max_v*4));

    std::cin >> n;
    std::vector<std::vector<int>> stores;
    for(int i = 0 ; i < n; i ++) {
        int a, b;
        std::cin >> a >> b;
        change_format(&a, &b, x_max, y_max);
        stores.push_back({a, b});
    }

    std::vector<std::vector<int>> forward_w_o = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<std::vector<int>> backward_w_o = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    std::vector<std::vector<int>> forward_w_u = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    std::vector<std::vector<int>> backward_w_u = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    std::vector<std::vector<int>> forward_h_l = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    std::vector<std::vector<int>> backward_h_l = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::vector<std::vector<int>> forward_h_r = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    std::vector<std::vector<int>> backward_h_r = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    int x, y;
    std::cin >> x >> y;
    change_format(&x, &y, x_max, y_max);

    if (x == 0 || x == x_max) {
        update(x, y, distance, forward_w_o);
        update(x, y, distance, backward_w_o);
        update(x, y, distance, forward_w_u);
        update(x, y, distance, backward_w_u);
    } else {
        update(x, y, distance, forward_h_l);
        update(x, y, distance, backward_h_l);
        update(x, y, distance, forward_h_r);
        update(x, y, distance, backward_h_r);
    }

    int total = 0;
    for(auto& s : stores) {
        total += distance[s[0]][s[1]];
    }
    std::cout << total;
}