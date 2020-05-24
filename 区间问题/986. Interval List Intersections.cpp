class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int N = A.size(), M = B.size();
        vector<vector<int>> answer;
        int i = 0, j = 0;
        while (i < N && j < M) {
            if (max(A[i][0], B[j][0]) <= min(A[i][1], B[j][1])) {
                answer.push_back(vector<int>{ max(A[i][0], B[j][0]), min(A[i][1], B[j][1]) });
            }
            
            if (A[i][1] < B[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return answer;
    }
};
