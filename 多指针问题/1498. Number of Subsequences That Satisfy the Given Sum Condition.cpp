class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        
        long long answer = 0;
        int l = 0, r = N - 1;
        while (l <= r) {
            if (nums[l] + nums[r] > target) r--;
            else {
                answer += fastPow(2, r - l);
                answer %= MOD;
                
                l++;
            }
        }
        return answer;
    }
private:
    const int MOD = 1e9+7;
    long long fastPow(int a, int b) {
        long long answer = 1, base = a;
        while (b) {
            if (b & 1) {
                answer *= base;
                answer %= MOD;
            }
            
            base *= base;
            base %= MOD;
            b >>= 1;
        }
        return answer;
    }
};