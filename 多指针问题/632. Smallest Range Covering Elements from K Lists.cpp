class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int left = 0, right = 0;
        set<tuple<int, int, int>> numberSet;
        const int K = nums.size();

        for (int i = 0; i < K; i++) {
            numberSet.emplace(nums[i][0], i, 0);
        }
        left = get<0>(*numberSet.begin()), right = get<0>(*numberSet.rbegin());

        while (numberSet.size() == K) {
            int currentLeft = get<0>(*numberSet.begin()), currentRight = get<0>(*numberSet.rbegin());
            int leftIndex = get<1>(*numberSet.begin());
            int leftOffset = get<2>(*numberSet.begin());

            if (currentRight - currentLeft < right - left || (currentRight - currentLeft == right - left && currentLeft < left)) {
                left = currentLeft, right = currentRight;
            }

            numberSet.erase(numberSet.begin());
            if (leftOffset + 1 < nums[leftIndex].size()) {
                numberSet.emplace(nums[leftIndex][leftOffset + 1], leftIndex, leftOffset + 1);
            }
        }

        return vector<int>{left, right};
    }
};