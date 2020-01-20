#include <iostream>
#include <vector>

using namespace std;

int N, G, M;

int go(int x, char dir) {
    if (dir == 'C') {
        x--;
    } else {
        x++;
    }

    return ((x % N) + N) % N;
}

int main() {
    int T;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        cin >> N >> G >> M;

        vector<vector<int>> clock_position(N, vector<int>{}), anti_position(N, vector<int>{});
        vector<pair<int, int>> clock_house(N, {999999, -1}), anti_house(N, {999999, -1});
        int clock_start = -1, anti_start = -1;

        for (int i = 0; i < G; i++) {
            int start;
            char dir;
            cin >> start >> dir;

            start--;
            int endPoint = 0;
            if (dir == 'C') {
                endPoint = (start + M) % N;
                if (clock_start == -1) {
                    clock_start = endPoint;
                }
                clock_position[endPoint].push_back(i);
            } else {
                endPoint = (((start - M) % N) + N) % N;
                if (anti_start == -1) {
                    anti_start = endPoint;
                }
                anti_position[endPoint].push_back(i);
            }
        }

        if (clock_start != -1) {
            int index = clock_start, distance = 0, lastIndex = 0;
            do {
                if (!clock_position[index].empty()) {
                    distance = -1;
                    lastIndex = index;
                }

                if (++distance <= M) {
                    clock_house[index] = {distance, lastIndex};
                }

                index = go(index, 'C');
            } while (index != clock_start);
        }

        if (anti_start != -1) {
            int index = anti_start, distance = 0, lastIndex = 0;

            do {
                if (!anti_position[index].empty()) {
                    distance = -1;
                    lastIndex = index;
                }

                if (++distance <= M) {
                    anti_house[index] = {distance, lastIndex};
                }

                index = go(index, 'A');
            } while (index != anti_start);
        }

        vector<int> answer(G, 0);
        for (int i = 0; i < N; i++) {
            int min_dist = min(clock_house[i].first, anti_house[i].first);
            if (min_dist >= 999999) {
                continue;
            }

            if (clock_house[i].first == min_dist) {
                for (int t : clock_position[clock_house[i].second]) {
                    answer[t]++;
                }
            }
            if (anti_house[i].first == min_dist) {
                for (int t : anti_position[anti_house[i].second]) {
                    answer[t]++;
                }
            }
        }
        printf("Case #%d:", _);
        for (int i = 0; i < G; i++) {
            printf(" %d", answer[i]);
        }
        printf("\n");
    }

    return 0;
}