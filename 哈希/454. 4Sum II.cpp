class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int answer = 0;
        unordered_map<int, int> table;
        const int N = A.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                table[A[i] + B[j]]++;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer += table[-(C[i] + D[j])];
            }
        }
        return answer;
    }
};