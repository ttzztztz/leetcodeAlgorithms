class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int& num : nums) {
            num %= 2;
        }
        const int N = nums.size();
        for (int i = 1; i < N; i++) {
            nums[i] += nums[i - 1];
        }
        int answer = 0;
        vector<int> binSearch;
        binSearch.push_back(0);

        for (int i = 0; i < N; i++) {
            auto it1 = upper_bound(binSearch.begin(), binSearch.end(), nums[i] - k);
            auto it2 = lower_bound(binSearch.begin(), binSearch.end(), nums[i] - k);

            answer += it1 - it2;
            binSearch.push_back(nums[i]);
        }
        return answer;
    }
};