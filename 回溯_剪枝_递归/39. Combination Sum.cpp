class Solution {
public:
    vector<vector<int>> answer;
    vector<int> current;
    void dfs(const vector<int>& candidates, int index, int sum) {
        if (sum == 0) {
            answer.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            const int candidate = candidates[i];

            if (candidate > sum) {
                break;
            }

            current.push_back(candidate);
            dfs(candidates, i, sum - candidate);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return answer;
    }
};