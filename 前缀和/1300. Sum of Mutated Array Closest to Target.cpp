class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        const int N = arr.size();

        sort(arr.begin(), arr.end());
        vector<long long> prefixSum(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }

        long long delta = 9999999, answer = 0;
        for (int i = 0; i <= 1e5 + 1; i++) {
            int index = lower_bound(arr.begin(), arr.end(), i) - arr.begin();

            long long sum = 0;
            if (index == N) {
                sum = prefixSum[N];
            } else if (index == 0) {
                sum = N * i;
            } else {
                const long long smallSum = prefixSum[index];
                const long long bigSum = (N - index) * i;

                sum = smallSum + bigSum;
            }

            if (abs(sum - target) < delta) {
                answer = i;
                delta = abs(sum - target);
            }

        }

        return answer;
    }
};