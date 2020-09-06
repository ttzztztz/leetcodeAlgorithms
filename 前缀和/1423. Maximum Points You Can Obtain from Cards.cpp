class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int N = cardPoints.size();
        const int window = N - k;
        
        int answer = 0;
        vector<int> f(N + 5, 0);
        for (int i = 1; i <= N; i++) {
            f[i] = f[i - 1] + cardPoints[i - 1];
        }
        
        const int total = f[N];
        for (int i = window; i <= N; i++) {
            answer = max(answer, total - (f[i] - f[i - window]));
        }
        return answer;
    }
};
