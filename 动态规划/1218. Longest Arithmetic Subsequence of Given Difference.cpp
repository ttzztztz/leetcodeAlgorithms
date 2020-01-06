class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int answer = 0;
        unordered_map<int, int> dp;
        
        for (int i = 0; i < arr.size(); i++) {
            const int num = arr[i];
            
            dp[num] = 1 + dp[num - difference];
            answer = max(answer, dp[num]);
        }
        return answer;
    }
};
