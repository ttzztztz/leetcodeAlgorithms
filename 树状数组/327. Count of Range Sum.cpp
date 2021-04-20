class Solution {
public:
    vector<int> indexTree;
    int lowbit(int x) {
        return x & (-x);
    }
    int query(int x) {
        long long answer = 0;
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

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) {
            return 0;
        }

        long long sum[nums.size() + 1];
        int answer = 0;
        sum[0] = 0;
        long long rankSum[(nums.size() + 1) * 3];
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        int rankSumOffset = 0;
        for (int i = 0; i <= nums.size(); i++) {
            rankSum[rankSumOffset++] = sum[i];
            rankSum[rankSumOffset++] = sum[i] + lower;
            rankSum[rankSumOffset++] = sum[i] + upper;
        }
        std::sort(rankSum, rankSum + rankSumOffset);
        long long* end = std::unique(rankSum, rankSum + rankSumOffset);

        indexTree.resize(((nums.size() * 3) + 1) * log2((nums.size() * 3) + 1));
        for (int i = 0; i < indexTree.size(); i++) {
            indexTree[i] = 0;
        }

        for (int i = nums.size(); i >= 0; i--) {
            long long oldNum = sum[i];
            int oldNumRank = std::lower_bound(rankSum, end, oldNum) - rankSum + 1;
            int oldNumLowerRank = std::lower_bound(rankSum, end, oldNum + lower) - rankSum + 1;
            int oldNumUpperRank = std::lower_bound(rankSum, end, oldNum + upper) - rankSum + 1;

            answer += query(oldNumUpperRank) - query(oldNumLowerRank - 1);
            increment(oldNumRank, 1);
        }

        return answer;
    }
};