class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: A string array
     */
    vector<string> characterGrid(string &A, string &B) {
        // write your code here.
        const int N = A.size(), M = B.size();
        vector<string> answer(M, string(N, '.'));
        
        int a = -1, b = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i] == B[j]) {
                    a = i, b = j;
                    break;
                }
            }
            
            if (!(a == -1 && b == -1)) break;
        }
        
        for (int k = 0; k < M; k++) answer[k][a] = B[k];
        for (int k = 0; k < N; k++) answer[b][k] = A[k];
        
        return answer;
    }
};
