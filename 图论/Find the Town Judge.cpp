class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> inDegree(N + 1, 0), outDegree(N + 1, 0);
        
        for (const auto& p : trust) {
            outDegree[p[0]]++;
            inDegree[p[1]]++;
        }
        
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == N - 1 && outDegree[i] == 0) return i;
        }
        return -1;
    }
};
