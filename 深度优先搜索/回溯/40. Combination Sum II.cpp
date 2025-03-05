class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(const vector<int>& candidates, int target, int i) {
        if (target < 0) return;

        if (i == candidates.size()) {
            if (target == 0) {
                ans.push_back(cur);
            }
            return;
        }

        // pick
        cur.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i + 1);
        cur.pop_back();

        // don't pick
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++;
        dfs(candidates, target, i + 1);
    }
};