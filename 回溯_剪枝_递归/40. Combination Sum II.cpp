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
            dfs(candidates, i + 1, sum - candidate);
            current.pop_back();

            while (i + 1 < candidates.size() && candidates[i + 1] == candidates[i]) {
                i++;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        dfs(candidates, 0, target);
        return answer;
    }
};