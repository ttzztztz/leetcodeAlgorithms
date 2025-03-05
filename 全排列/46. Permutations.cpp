class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        do {
            answer.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return answer;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        dfs(nums, 0);
        return ans;
    }
private:
    vector<int> tmp;
    vector<bool> visited;
    vector<vector<int>> ans;

    void dfs(const vector<int>& nums, int depth) {
        if (depth == nums.size()) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            visited[i] = true;
            tmp.push_back(nums[i]);
            dfs(nums, depth + 1);
            tmp.pop_back();
            visited[i] = false;
        }
    }
};
