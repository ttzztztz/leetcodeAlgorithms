class Solution {
public:
    vector<vector<int>> answer;
    void dfs(vector<int>& nums, vector<int>& temp, int index) {
        const int N = nums.size();
        if (index == N) {
            answer.push_back(temp);
            return;
        }

        dfs(nums, temp, index + 1);


        temp.push_back(nums[index]);
        dfs(nums, temp, index + 1);

        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, temp, 0);

        return answer;
    }
};