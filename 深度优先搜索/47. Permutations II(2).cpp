class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        n = nums.size();
        visited = vector<bool>(n, false);
        finalState = vector<bool>(n, true);
        dfs();
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur, nums;
    int n;
    vector<bool> visited, finalState;
    
    void dfs() {
        if (visited == finalState) {
            ans.push_back(cur);
            return;
        }
        
        for (int k = 0; k < n; k++) {
            if (visited[k]) continue;

            if (k - 1 >= 0 && !visited[k - 1] && nums[k] == nums[k - 1]) continue;
            cur.push_back(nums[k]);
            visited[k] = true;
            dfs();
            visited[k] = false;
            cur.pop_back();
        }
    }
};
