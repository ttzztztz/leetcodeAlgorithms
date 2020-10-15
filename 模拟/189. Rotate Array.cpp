class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            const int t = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), t);
        }
    }
};
