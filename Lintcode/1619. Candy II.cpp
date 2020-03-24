class Solution {
public:
    /**
     * @param ratings: rating value of each child
     * @return: Return the minimum candies you must give.
     */
    int candyII(vector<int> &ratings) {
        int answer = 0;
        const int N = ratings.size();
        if (N == 0) return answer;
        
        vector<int> f(N), g(N);
        f[0] = 1;
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i - 1]) f[i] = f[i - 1] + 1;
            else if (ratings[i] == ratings[i - 1]) f[i] = f[i - 1];
            else f[i] = 1;
        }
        
        g[N - 1] = 1;
        for (int i = N - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) g[i] = g[i + 1] + 1;
            else if (ratings[i] == ratings[i + 1]) g[i] = g[i + 1];
            else g[i] = 1;
        }
        
        for (int i = 0; i < N; i++) {
            answer += max(f[i], g[i]);
        }
        return answer;
    }
};
