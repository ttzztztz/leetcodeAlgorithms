class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int k) {
        vector<int> B;
        while (k) {
            B.push_back(k % 10);
            k /= 10;
        }
        
        reverse(A.begin(), A.end());
        vector<int> ans(A.size() + B.size() + 1, 0);
        
        for (int i = 0, ext = 0; i < max(A.size(), B.size()) + 1; i++) {
            const int d1 = i < A.size() ? A[i] : 0;
            const int d2 = i < B.size() ? B[i] : 0;
            
            ans[i] = d1 + d2 + ext;
            ext = 0;
            if (ans[i] >= 10) ans[i] -= 10, ext++;
        }
        
        for (int i = ans.size() - 1; i > 0; i--) {
            if (ans[i] == 0) ans.pop_back();
            else break;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
