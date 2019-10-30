const int INVALID = 5000;

class Solution {
public:
    vector<int> compress;
    int N;
    int dfs(vector<int>& arr1, set<int>& prepare, vector<vector<int>>& dp, int index, int lastNumber) {
        if (index == N) {
            return 0;
        }
        if (dp[index][lastNumber] != -1) {
            return dp[index][lastNumber];
        }

        int answer = INVALID;
        if (index == 0) {
            answer = std::min(answer, dfs(arr1, prepare, dp, index + 1, arr1[index]));

            auto it = prepare.begin();
            if (it != prepare.end()) {
                answer = std::min(answer, dfs(arr1, prepare, dp, index + 1, *it) + 1);
            }

        } else {
            if (lastNumber < arr1[index]) {
                answer = std::min(answer, dfs(arr1, prepare, dp, index + 1, arr1[index]));
            }

            auto it = prepare.upper_bound(lastNumber);
            if (it != prepare.end()) {
                answer = std::min(answer, dfs(arr1, prepare, dp, index + 1, *it) + 1);
            }
        }

        return dp[index][lastNumber] = answer;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        this->N = arr1.size();
        set<int> prepare;
        // <-- compress
        for (int number : arr1) {
            compress.push_back(number);
        }
        for (int number : arr2) {
            compress.push_back(number);
        }
        sort(compress.begin(), compress.end());
        auto endIt = unique(compress.begin(), compress.end());
        for (int& number : arr1) {
            number = lower_bound(compress.begin(), endIt, number) - compress.begin();
        }
        for (int& number : arr2) {
            number = lower_bound(compress.begin(), endIt, number) - compress.begin();
        }
        for (int number : arr2) {
            prepare.insert(number);
        }
        // <-- dp
        vector<vector<int>> dp(2005, vector<int>(4005, -1));

        int answer = dfs(arr1, prepare, dp, 0, 0);
        return answer == INVALID ? -1 : answer;
    }
};