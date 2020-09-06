class Solution {
public:
    vector<vector<int>> answer;
    void dfs(const vector<int>& nums, vector<int>& temp, int index, int lastElement) {
        const int N = nums.size();
        if (index == N) {
            answer.push_back(temp);
            return;
        }

        // not add
        int nextIndex = index + 1;
        while (nextIndex < N && nums[nextIndex - 1] == nums[nextIndex]) {
            nextIndex++;
        }
        dfs(nums, temp, nextIndex, lastElement);

        // add
        temp.push_back(nums[index]);
        dfs(nums, temp, index + 1, nums[index]);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dfs(nums, temp, 0, -999999);
        return answer;
    }
};