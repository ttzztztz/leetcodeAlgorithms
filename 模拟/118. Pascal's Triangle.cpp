class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        if (numRows == 0) return answer;
        answer = {{1}};
        for (int i = 1; i < numRows; i++) {
            const vector<int>& prev = answer[i - 1];
            vector<int> cur;
            for (int k = 0; k <= i; k++) {
                const int a = k >= prev.size() ? 0 : prev[k];
                const int b = k - 1 >= 0 ? prev[k - 1] : 0;
                
                cur.push_back(a + b);
            }
            answer.push_back(cur);
        }
        
        return answer;
    }
};