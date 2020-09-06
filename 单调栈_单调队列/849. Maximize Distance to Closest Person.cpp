class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();
        vector<int> f(N + 5, -999999), g(N + 5, 999999);
        int answer = 0;
        
        vector<int> stk;
        for (int i = 0; i < N; i++) {
            if (!stk.empty() && seats[stk.back()] <= seats[i]) stk.pop_back();
            if (!stk.empty()) f[i] = stk.back();
            stk.push_back(i);
        }
        
        stk.clear();
        for (int i = N - 1; i >= 0; i--) {
            if (!stk.empty() && seats[stk.back()] <= seats[i]) stk.pop_back();
            if (!stk.empty()) g[i] = stk.back();
            stk.push_back(i);
        }
        
        for (int i = 0; i < N; i++) {
            if (seats[i] == 1) continue;
            answer = max(answer, min(g[i] - i, i - f[i]));
        }
        return answer;
    }
};