class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        typedef long long ll;
        ll mi = numeric_limits<ll>::max(), sum = 0;
        int neg_cnt = 0;
        const int n = matrix.size();
        
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (matrix[i][j] <= 0) {
                neg_cnt++;
            }
            mi = min<ll>(mi, abs(matrix[i][j]));
            sum += abs(matrix[i][j]);
        }
        
        if (neg_cnt % 2 == 0) return sum;
        else return sum - 2 * mi;
    }
};