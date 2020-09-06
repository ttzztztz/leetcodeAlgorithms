class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int N = grid.size(), M = grid[0].size();
        int answer = 0;
        
        int ptr = M - 1;
        for (int i = 0; i < N; i++) {
            while (ptr >= 0 && grid[i][ptr] < 0) ptr--;
            answer += M - 1 - ptr;
        }
        return answer;
    }
};
