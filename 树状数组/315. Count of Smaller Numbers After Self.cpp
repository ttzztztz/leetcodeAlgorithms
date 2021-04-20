class Solution {
public:
    vector<int> indexTree;
    int lowbit(int x) {
        return x & (-x);
    }
    int query(int x) {
        int answer = 0;
        while (x) {
            answer += indexTree[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void increment(int x, int val) {
        while (x && x < indexTree.size()) {
            indexTree[x] += val;
            x += lowbit(x);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        indexTree.resize((nums.size() + 1) * log2(nums.size() + 1));
        for (int i = 0; i < indexTree.size(); i++) {
            indexTree[i] = 0;
        }

        vector<int> rankNums = nums;
        std::sort(rankNums.begin(), rankNums.end());
        std::unique(rankNums.begin(), rankNums.end());
        for (int& number: nums) {
            int newNumber = std::lower_bound(rankNums.begin(), rankNums.end(), number) - rankNums.begin() + 1;
            number = newNumber;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            int number = nums[i];

            nums[i] = query(number - 1);
            increment(number, 1);
        }

        return nums;
    }
};