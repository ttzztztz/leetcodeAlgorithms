class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        const int lowbit = ans & (-ans);

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & lowbit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return vector<int>{a, b};
    }
};