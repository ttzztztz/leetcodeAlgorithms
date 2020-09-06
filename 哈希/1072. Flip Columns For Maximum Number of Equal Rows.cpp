class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int answer = 1;
        const int N = matrix.size(), M = matrix[0].size();
        map<vector<int>, int> appear;
        
        for (int i = 0; i < N; i++) {
            vector<int> _1col, _0col;
            
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 1) _1col.push_back(j);
                else _0col.push_back(j);
            }
            
            if(++appear[_1col] > answer) answer = appear[_1col];
            if(++appear[_0col] > answer) answer = appear[_0col];
        }
        
        return answer;
    }
};
