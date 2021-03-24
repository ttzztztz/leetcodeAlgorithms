// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         std::next_permutation(nums.begin(), nums.end());
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int n = nums.size();
        int i = n - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) break;
            else i--;
        }
        
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0) {
                if (nums[i] < nums[j]) break;
                else j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};