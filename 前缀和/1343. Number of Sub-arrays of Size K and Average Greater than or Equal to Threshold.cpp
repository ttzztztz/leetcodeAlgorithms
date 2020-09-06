class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int answer = 0;
        const int N = arr.size();
        vector<int> prefixSum(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }
        
        for (int i = k; i <= N; i++) {
            if(prefixSum[i] - prefixSum[i - k] >= k * threshold) answer++;
        }
        return answer;
    }
};
