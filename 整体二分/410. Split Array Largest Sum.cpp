class Solution {
public:
    int M;
    int judge(vector<int>& nums, int x) {
        int block = 0;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num > x) {
                sum = num;
                block++;
            } else {
                sum += num;
            }
        }

        if (sum > 0) {
            block++;
        }
        return block > M;
    }

    int splitArray(vector<int>& nums, int m) {
        M = m;

        long long left = 0, right = 0;
        for (int num : nums) {
            left = max(left, 1ll * num);
            right += num;
        }

        while (left <= right) {
            long long middle = (left + right) >> 1;

            if (judge(nums, middle)) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return right + 1;
    }
};