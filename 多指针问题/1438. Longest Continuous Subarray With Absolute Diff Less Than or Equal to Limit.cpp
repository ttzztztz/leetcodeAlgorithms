class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> all;
        const int N = nums.size();
        
        int answer = 0;
        for (int left = 0, right = 0; right < N; right++) {
            all.insert(nums[right]);
            while (*all.rbegin() - *all.begin() > limit) {
                all.erase(all.lower_bound(nums[left]));
                left++;
            }
            
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};
