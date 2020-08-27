class Solution {
public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(vector<vector<int>> &nums) {
        int n = 0;
        for (const auto& v : nums) {
            n += v.size();
            if (!v.empty()) {
                mi = min(mi, (long long) v.front());
                ma = max(ma, (long long) v.back());
            }
        }
        
        if (n == 0) return 0;
        if (n % 2 == 1) { 
            const int t = n / 2 + 1;
            return findKth(t, nums);
        } else {
            const int t1 = n / 2;
            const long long a = findKth(t1, nums);
            const long long b = findKth(t1 + 1, nums);
            return (1.0 * a + 1.0 * b) / 2.0;
        }
    }
private:
    long long mi = numeric_limits<long long>::max(), ma = numeric_limits<long long>::min();
    long long findKth(int k, vector<vector<int>> &nums) {
        long long l = mi, r = ma;
        while (l <= r) {
            const long long mid = (l + r) >> 1;
            
            if (solve(nums, mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
    int solve(vector<vector<int>> &nums, long long k) {
        int answer = 0;
        for (auto& v : nums) {
            if (v.empty()) continue;
            answer += lower_bound(v.begin(), v.end(), k) - v.begin();
        }
        return answer;
    }
};
