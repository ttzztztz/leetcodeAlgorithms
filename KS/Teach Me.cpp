#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string my_hash(const vector<int>& v) {
    string ans;
    for (int i : v) {
        ans += std::to_string(i);
        ans += ',';
    }
    return ans;
}

int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int N, S;
        long long answer = 0l;
        cin >> N >> S;

        unordered_map<string, int> skillMap;
        vector<vector<int>> skills(N, vector<int>{});
        for (int i = 0; i < N; i++) {
            int C;
            cin >> C;

            vector<int> peopleSkills;
            for (int j = 0; j < C; j++) {
                int skill = 0;
                cin >> skill;

                peopleSkills.push_back(skill);
                skills[i].push_back(skill);
            }

            sort(peopleSkills.begin(), peopleSkills.end());
            sort(skills[i].begin(), skills[i].end());
            skillMap[my_hash(peopleSkills)]++;
        }

        for (int i = 0; i < N; i++) {
            long long temp = 0;

            const vector<int>& skill = skills[i];
            const int M = skill.size();

            const int mask = (1 << M) - 1;
            for (int state = 0; state <= mask; state++) {
                vector<int> cur;

                for (int k = 0; k < M; k++)
                    if (state & (1 << k))
                        cur.push_back(skill[k]);

                temp += skillMap[my_hash(cur)];
            }

            answer += N - temp;
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}