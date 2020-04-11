class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param target: an integer
     * @return: nothing
     */
    void MoveTarget(vector<int> &nums, int target) {
        const int N = nums.size();
        
        int cnt = 0, ptr = N - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] == target) {
                cnt++;
            } else {
                nums[ptr] = nums[i];
                ptr--;
            }
        }
        
        for (int i = 0; i < cnt; i++) nums[i] = target;
    }
};
