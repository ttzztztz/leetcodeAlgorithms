class Solution {
public:
    /**
     * @param A: the array A
     * @param B: the array B
     * @return: returns an alternate array of arrays A and B.
     */
    vector<int> interleavedArray(vector<int> &A, vector<int> &B) {
        // Interleaved Array
        const int N = A.size();
        vector<int> answer;
        for (int i = 0; i < N; i++) answer.push_back(A[i]), answer.push_back(B[i]);
        return answer;
    }
};
