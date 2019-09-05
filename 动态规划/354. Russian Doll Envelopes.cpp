class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0) {
            return 0;
        }
        if (envelopes.size() == 1) {
            return 1;
        }

        std::sort(envelopes.begin(), envelopes.end(), [](const vector<int>& $1, const vector<int>& $2) -> bool {
            if ($1[0] == $2[0]) {
                return $1[1] > $2[1];
            } else {
                return $1[0] < $2[0];
            }
        });

        std::vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++) {
            int first = envelopes[i][0];
            int second = envelopes[i][1];

            if (second > temp.back()) {
                temp.push_back(envelopes[i][1]);
            } else {
                auto it = std::lower_bound(temp.begin(), temp.end(), second);
                *it = second;
            }
        }

        return temp.size();
    }
};