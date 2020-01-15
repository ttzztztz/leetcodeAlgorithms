class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        
        array<int, 8> occurrenceA{0}, occurrenceB{0}, distinct{0};
        vector<int> maybe;

        for (int i = 0; i < N; i++) {
            occurrenceA[A[i]]++, occurrenceB[B[i]]++;
            
            for (int j = 1; j <= 6; j++) {
                if (A[i] == j || B[i] == j) distinct[j]++;
            }
        }
        
        int answer = 9999999;
        for (int i = 1; i <= 6; i++) {
            if (occurrenceA[i] + occurrenceB[i] >= N && distinct[i] == N) {
                answer = min(answer, min(N - occurrenceA[i], N - occurrenceB[i]));
            } 
        }
        
        if (answer == 9999999) {
            return -1;
        } else {
            return answer;
        }
    }
};
