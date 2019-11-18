class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int N = A.size();
        int answer = 999999;

        vector<pair<long long, int>> prefixSum;
        prefixSum.emplace_back(0, 0);
        long long prefix = 0;
        for (int i = 1; i <= N; i++) {
            const long long num = A[i - 1], nextSum = prefix + num, search = nextSum - K;
            auto it = lower_bound(prefixSum.begin(), prefixSum.end(), make_pair(search, i));
            if (it == prefixSum.end() || (it != prefixSum.begin() && it->first > search)) {
                it--;
            }

            if (it != prefixSum.end() && it->first <= search) {
                const int dist = i - it->second;
                answer = min(answer, dist);
            }

            while (!prefixSum.empty() && prefixSum[prefixSum.size() - 1].first >= nextSum) {
                prefixSum.pop_back();
            }
            prefix = nextSum;
            prefixSum.emplace_back(nextSum, i);
        }
        return answer == 999999 ? -1 : answer;
    }
};