class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool top = false;
        const int N = A.size();
        for (int i = 1; i < N; i++) {
            if (A[i] == A[i - 1]) return false;
            if (!top) {
                if (A[i - 1] < A[i]) continue;
                else {
                    if (i >= 2) top = true;
                    else return false;
                }
            } else {
                if (A[i - 1] > A[i]) continue;
                else return false;
            }
        }
        return top;
    }
};
