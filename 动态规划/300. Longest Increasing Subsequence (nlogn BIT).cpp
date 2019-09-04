class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }

    int query(int *bitArray, int x) {
        int answer = 0;
        while (x) {
            answer = std::max(answer, bitArray[x]);
            x -= lowbit(x);
        }
        return answer;
    }

    void increment(int *bitArray, int x, int value, int maxSize) {
        while (x && x < maxSize) {
            bitArray[x] = std::max(bitArray[x], value);
            x += lowbit(x);
        }
    }


    int lengthOfLIS(std::vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxSize = nums.size() * nums.size();

        int bitArray[maxSize];
        std::memset(bitArray, 0, sizeof(bitArray));
        int uniqueArray[nums.size()];

        std::copy(nums.begin(), nums.end(), uniqueArray);
        std::sort(uniqueArray, uniqueArray + nums.size());
        int *end = std::unique(uniqueArray, uniqueArray + nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int rank = std::lower_bound(uniqueArray, end, nums[i]) - uniqueArray + 1;
            nums[i] = rank;
        }

        int answer = 0;
        for (int number: nums) {
            int count = query(bitArray, number - 1) + 1;
            increment(bitArray, number, count, maxSize);
            answer = std::max(answer, count);
        }

        return answer;
    }
};