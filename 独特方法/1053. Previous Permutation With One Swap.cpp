class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        const int N = A.size();
        int left = -1;
        for (int i = N - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) {
                left = i;
                break;
            }
        }
        
        if (left != -1) {
            int right = left + 1;
            int maxAnswer = 0;
            for (int i = left + 1; i < N; i++) {
                if (A[i] < A[left]) {
                    if (A[i] > maxAnswer) {
                        maxAnswer = A[i];
                        right = i;
                    }
                }
            }
            
            swap(A[left], A[right]);
        }
        return A;
    }
};
