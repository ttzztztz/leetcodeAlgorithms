class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(const vector<int>& candidates, int idx, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        if (target < 0 || idx >= candidates.size()) return;

        dfs(candidates, idx + 1, target);

        cur.push_back(candidates[idx]);
        dfs(candidates, idx, target - candidates[idx]);
        cur.pop_back();
    }
};