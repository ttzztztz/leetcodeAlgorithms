class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long index = 0, miss = 1;
        int answer = 0;
        
        const int N = nums.size();
        while (miss <= n) {
            if (index < N && nums[index] <= miss) {
                miss += nums[index];
                index++;
            } else {
                miss += miss;
                answer++;
            }
        }
        return answer;
    }
};
