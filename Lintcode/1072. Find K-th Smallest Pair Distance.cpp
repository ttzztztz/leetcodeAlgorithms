class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param k: a integer
     * @return: return a integer
     */
    int solve(const vector<int>& nums, int k) {
        int answer = 0;
        int left = 0, right = 0;
        const int N = nums.size();
        
        while (left < N) {
            while (right < N && nums[right] - nums[left] <= k) right++;
            
            answer += max(0, right - left - 1);
            left++;
        }
        
        return answer;
    }
    int smallestDistancePair(vector<int> &nums, int k) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums[N - 1] - nums[0];
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            if (solve(nums, mid) >= k) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};
