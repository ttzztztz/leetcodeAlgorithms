class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int answer = 0;
        const int n = arr.size();
        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i++) {
                for (int k = 0; k < len; k++) {
                    answer += arr[i + k];
                }
            }
        }
        return answer;
    }
};
