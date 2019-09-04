class Solution {
public:
    int answer, maxDeep, target;

    void dfs(vector<int>& nums, int deep, int total) {
        if (deep == maxDeep){
            if (total == target) {
                answer++;
            }
            return;
        } else {
            dfs(nums, deep + 1, total + nums[deep]);
            dfs(nums, deep + 1, total - nums[deep]);
        }
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        answer = 0;
        maxDeep = nums.size();
        target = S;

        dfs(nums, 0, 0);
        return answer;
    }
};