class Solution {
public:
    unordered_map<int, int> solve(vector<int>& rods, unordered_map<int, int>& answer) {
        vector<pair<int, int>> temp;

        temp.emplace_back(0, 0);
        for (int rod : rods) {
            const int N = temp.size();
            for (int i = 0; i < N; i++) {
                temp.emplace_back(temp[i].first + rod, temp[i].second);
                temp.emplace_back(temp[i].first, temp[i].second + rod);
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            answer[temp[i].first - temp[i].second] = temp[i].first;
        }
        return answer;
    }
    int tallestBillboard(vector<int>& rods) {
        const int N = rods.size();
        vector<int> v1, v2;
        for (int i = 0; i < rods.size(); i++) {
            if (i < N / 2) {
                v1.push_back(rods[i]);
            } else {
                v2.push_back(rods[i]);
            }
        }

        unordered_map<int, int> m1, m2;
        solve(v1, m1), solve(v2, m2);

        int answer = 0;
        for (const pair<int, int>& p : m1) {
            if (m2.count(-p.first)) {
                answer = std::max(answer, p.second + m2[-p.first]);
            }
        }
        return answer;
    }
};