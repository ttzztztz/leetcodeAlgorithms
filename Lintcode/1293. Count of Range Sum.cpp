class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param lower: a integer
     * @param upper: a integer
     * @return: return a integer
     */
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        const int N = nums.size();
        init(N);
        
        vector<long long> all, prefixSum;
        prefixSum.push_back(0);
        for (int i = 1; i <= N; i++) prefixSum.push_back(prefixSum[i - 1] + nums[i - 1]);
        for (int num : prefixSum) {
            all.push_back(num);
            all.push_back(num - lower);
            all.push_back(num - upper);
        }
        sort(all.begin(), all.end());
        auto endIt = unique(all.begin(), all.end());
        
        int answer = 0;
        for (int i = 0; i <= N; i++) {
            const int c = lower_bound(all.begin(), endIt, prefixSum[i]) - all.begin() + 1;
            const int l = lower_bound(all.begin(), endIt, prefixSum[i] - lower) - all.begin() + 1;
            const int u = lower_bound(all.begin(), endIt, prefixSum[i] - upper) - all.begin() + 1;
            
            answer += query(l) - query(u - 1);
            incr(c, 1);
        }
        return answer;
    }
private:
    vector<long long> bit;
    void init(int N) {
        bit = vector<long long>(N * 4, 0);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    int query(int x) {
        int answer = 0;
        while (x) {
            answer += bit[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void incr(int x, int y) {
        const int M = bit.size();
        while (x && x < M) {
            bit[x] += y;
            x += lowbit(x);
        }
    }
};
