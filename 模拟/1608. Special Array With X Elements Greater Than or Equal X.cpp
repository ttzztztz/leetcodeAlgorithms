class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i <= 1000; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] >= i) cnt++;
            }
            if (i == cnt) return i;
        }
        return -1;
    }
};
