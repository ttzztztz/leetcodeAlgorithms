class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        const int n = A.size();
        
        int d = numeric_limits<int>::max(), len = 0;
        for (int i = 1; i < n; i++) {
            const int cur_d = A[i] - A[i - 1];
            
            if (cur_d == d) {
                len++;
                ans += len - 2;
            } else {
                len = 2;
                d = cur_d;
            }
        }
        return ans;
    }
};
