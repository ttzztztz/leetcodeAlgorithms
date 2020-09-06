class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        long long answer = numeric_limits<long long>::min();
        long long sum = 0;
        for (int i : A) sum += i;
        
        int cur = 0;
        const int N = A.size();
        
        for (int i : A) {
            cur = max(i, cur + i);
            answer = max(answer, (long long) cur);
        }
        
        cur = 0;
        for (int i = 1; i < N - 1; i++) {
            cur = min(A[i], cur + A[i]);
            answer = max(answer, sum - cur);
        }
        
        return answer;
    }
};
