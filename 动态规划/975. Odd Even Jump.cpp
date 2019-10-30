class Solution {
public:
    int N = 0;
    vector<pair<int, int>> upper, lower;

    int dfs(vector<int>& A, vector<vector<int>>& dp, int step, int index) {
        if (index == N - 1) {
            return true;
        }
        if (dp[step][index] != -1) {
            return dp[step][index];
        }

        const int current = A[index];
        int answer = 0;
        if (step == 1) {
            auto it = std::lower_bound(upper.begin(), upper.end(), std::make_pair(current, 0), [](const pair<int, int>& $1, const pair<int, int>& $2)->bool{
                return $1.first < $2.first;
            });

            while (it != upper.end() && it->second <= index) {
                it++;
            }

            if (it != upper.end()) {
                answer |= dfs(A, dp, !step, it->second);
            }
        } else {
            auto it = std::upper_bound(lower.begin(), lower.end(), std::make_pair(current, 0), [](const pair<int, int>& $1, const pair<int, int>& $2)->bool{
                return $1.first < $2.first;
            });

            it--;
            while (it >= lower.begin() && it->second <= index) {
                it--;
            }

            if (it >= lower.begin()) {
                answer |= dfs(A, dp, !step, it->second);
            }
        }
        return dp[step][index] = (answer == 1);
    }
    int oddEvenJumps(vector<int>& A) {
        this->N = A.size();
        vector<vector<int>> dp(2, vector<int>(20005, -1));

        for (int i = 0; i < A.size(); i++) {
            upper.emplace_back(A[i], i);
            lower.emplace_back(A[i], i);
        }

        sort(upper.begin(), upper.end(), [](const pair<int, int>& $1, const pair<int, int>& $2)->bool {
            if ($1.first == $2.first) {
                return $1.second < $2.second;
            } else {
                return $1.first < $2.first;
            }
        });
        sort(lower.begin(), lower.end(), [](const pair<int, int>& $1, const pair<int, int>& $2)->bool {
            if ($1.first == $2.first) {
                return $1.second > $2.second;
            } else {
                return $1.first < $2.first;
            }
        });

        int answer = 0;
        for (int i = 0; i < N; i++) {
            if (dfs(A, dp, 1, i)) {
                answer++;
            }
        }
        return answer;
    }
};