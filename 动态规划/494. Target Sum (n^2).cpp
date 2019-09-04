class Solution {
public:
    int answer, maxDeep, target;
    int memory[25][2005];

    int dfs(vector<int>& nums, int deep, int total) {
        if (deep == maxDeep){
            if (total == target) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (memory[deep][total + 1000] != -999999) {
                return memory[deep][total + 1000];
            } else {
                int answer = 0;

                answer += dfs(nums, deep + 1, total + nums[deep]);
                answer += dfs(nums, deep + 1, total - nums[deep]);

                return memory[deep][total + 1000] = answer;
            }

        }
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        for (int i = 0; i <= nums.size(); i++) {
            for (int j = 0; j < 2005; j++) {
                memory[i][j] = -999999;
            }
        }
        maxDeep = nums.size();
        target = S;

        return dfs(nums, 0, 0);
    }
};