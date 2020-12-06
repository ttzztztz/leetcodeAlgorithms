class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        
        int ans = 0;
        for (int i = 0, last = 0; i < A.size(); i++) {
            if (last <= A[i]) {
                last = A[i] + 1;
            } else {
                const int cost = last - A[i];
                ans += cost;
                last = A[i] + cost + 1;
            }
        }
        return ans;
    }
};
