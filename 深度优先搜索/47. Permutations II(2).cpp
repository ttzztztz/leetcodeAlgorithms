class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        visited = vector<bool>(N, false);
        dfs(nums, 0);
        return answer;
    }
private:
    vector<vector<int>> answer;
    vector<int> tmp;
    vector<bool> visited;
    
    void dfs(const vector<int>& nums, int i) {
        if (tmp.size() == nums.size()) {
            answer.push_back(tmp);
            return;
        }
        if (i > nums.size()) return;
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            
            if (i >= 1 && (!visited[i - 1] && nums[i - 1] == nums[i])) continue;
            
            visited[i] = true;
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
            visited[i] = false;
        }
    }
};
