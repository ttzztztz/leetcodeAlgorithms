class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int n = A.size();
        
        int ans = 0;
        for (int l = 0; l < n;) {
            int r = l;
            
            bool a = false, b = false;
            while (r + 1 < n && A[r] < A[r + 1]) a = true, r++;
            while (r + 1 < n && A[r] > A[r + 1]) b = true, r++;
            
            if (a && b) ans = max(ans, r - l + 1);
            l = max(l + 1, r);
        }
        
        return ans;
    }
};