class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        const int n = nums.size();
        long long l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0ll);
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (solve(nums, mid) <= m) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    int solve(const vector<int> &nums, int k) {
        int answer = 0, cur = 0;
        for (int i : nums) {
            cur += i;
            if (cur > k) {
                answer++;
                cur = i;
            }
        }
        return answer + (cur != 0);
    }
};
