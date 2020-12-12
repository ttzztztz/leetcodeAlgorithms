class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if (A.size() <= 1) return 0;
        int ans = 0, mx = 0 + A[0];
        for (int i = 1; i < A.size(); i++) {
            ans = max(ans, mx + A[i] - i);
            mx = max(mx, i + A[i]);
        }
        return ans;
    }
};
