class Solution {
public:
    /**
     * @param A: an array
     * @return: the number of arithmetic subsequence slices in the array A
     */
    int numberOfArithmeticSlices(vector<int> &A) {
        const int n = A.size();
        if (n <= 1) return 0;
        typedef long long ll;
        ll answer = 0;
        
        unordered_map<long long, long long> f[1005];
        f[1][A[1] - A[0]] = 1;
        
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll d = A[i] - A[j];
                
                f[i][d] += f[j][d] + 1;
                answer += f[j][d];
            }
        }
        
        return answer;
    }
};
