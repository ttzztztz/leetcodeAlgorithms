#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        int N = 0, M = 0, P = 0;
        cin >> N >> M >> P;
        int sum[101][2];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= P; j++) {
                if (s[j - 1] == '0') {
                    sum[j][0]++;
                } else {
                    sum[j][1]++;
                }
            }
        }

        vector<string> disabled;
        for (int i = 1; i <= M; i++) {
            string temp;
            cin >> temp;
            disabled.emplace_back(temp);
        }

        vector<pair<string, int>> plans;
        plans.emplace_back("", 0);
        for (int i = 1; i <= P; i++) {
            vector<pair<string, int>> tempPlan;

            for (const pair<string, int> &plan: plans) {
                const string oldStr = plan.first;
                const int dissatisfaction = plan.second;

                tempPlan.emplace_back(oldStr + "0", dissatisfaction + N - sum[i][0]);
                tempPlan.emplace_back(oldStr + "1", dissatisfaction + N - sum[i][1]);
            }

            sort(tempPlan.begin(), tempPlan.end(),
                 [](const pair<string, int> &$1, const pair<string, int> &$2) -> bool {
                     return $1.second < $2.second;
                 });
            int size = std::min((int) tempPlan.size(), 101);
            tempPlan.resize(size);

            plans.resize(size);
            std::copy(tempPlan.begin(), tempPlan.end(), plans.begin());
        }

        int answer = 0;
        for (const pair<string, int> &plan : plans) {
            if (find(disabled.begin(), disabled.end(), plan.first) != disabled.end()) {
                continue;
            } else {
                answer = plan.second;
                break;
            }
        }
        printf("Case #%d: %d \n", _, answer);
    }

    return 0;
}