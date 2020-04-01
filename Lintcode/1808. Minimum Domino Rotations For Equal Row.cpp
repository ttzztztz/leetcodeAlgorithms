class Solution {
public:
    /**
     * @param A: a integer array
     * @param B: a integer array
     * @return: Return the minimum number of rotations
     */
    int minDominoRotations(vector<int> &A, vector<int> &B) {
        vector<int> appearRow(7), appearUp(7), appearDown(7);
        const int N = A.size();
        int answer = 99999999;
        for (int i = 0; i < N; i++) {
            appearUp[A[i]]++, appearDown[B[i]]++;
            
            if (A[i] == B[i]) appearRow[A[i]]++;
            else {
                appearRow[A[i]]++, appearRow[B[i]]++;
            }
        }
        
        for (int i = 1; i <= 6; i++) {
            if (appearRow[i] == N) {
                answer = min(answer, min(N - appearUp[i], N - appearDown[i]));
            }
        }
        
        if (answer == 99999999) return -1;
        else return answer;
    }
};
