class Solution {
public:
    /**
     * @param nums: The number array
     * @return: Return the single number
     */
    int getSingleNumber(vector<int> &nums) {
        const int N = nums.size();
        
        int left = 0, right = N - 1;
        while (left < right) {
            const int middle = (left + right) >> 1;
            
            if (left <= middle - 1 && nums[middle] == nums[middle - 1]) {
                if ((middle - left + 1) % 2 == 1) {
                    right = middle - 2;
                } else {
                    left = middle + 1;
                }
            } else if (middle + 1 <= right && nums[middle] == nums[middle + 1]) {
                if ((right - middle + 1) % 2 == 1) {
                    left = middle + 2;
                } else {
                    right = middle - 1;
                }
            } else {
                return nums[middle];
            }
        }
        
        return nums[left];
    }
};
