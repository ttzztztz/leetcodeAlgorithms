class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return test1(A) || test2(A);
    }
private:
    bool test1(vector<int>& A) {
        const int N = A.size();
        for (int i = 1; i < N; i++) {
            if (A[i] < A[i - 1]) return false;
        }
        return true;
    }
    
    bool test2(vector<int>& A) {
        const int N = A.size();
        for (int i = 1; i < N; i++) {
            if (A[i] > A[i - 1]) return false;
        }
        return true;
    }
};
