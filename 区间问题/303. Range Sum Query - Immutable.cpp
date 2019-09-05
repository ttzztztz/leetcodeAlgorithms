class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        int currentSum = 0, index = 0;
        for (int number : nums) {
            currentSum += number;
            prefixSum[index ++] = currentSum;
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return prefixSum[j];
        } else {
            return prefixSum[j] - prefixSum[i - 1];
        }
    }
};