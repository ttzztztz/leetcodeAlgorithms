class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        const int n = A.size(), m = B.size();
        vector<int> v;
        
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < n && ptr2 < m) {
            if (A[ptr1] < B[ptr2]) v.push_back(A[ptr1++]);
            else v.push_back(B[ptr2++]);
        }
        while (ptr1 < n) v.push_back(A[ptr1++]);
        while (ptr2 < m) v.push_back(B[ptr2++]);
        
        if ((n + m) % 2 == 0) {
            const double a = v[(n + m) / 2], b = v[(n + m) / 2 - 1];
            return 0.5 * (a + b);
        } else {
            return v[(n + m) / 2];
        }
    }
};
