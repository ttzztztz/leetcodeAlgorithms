class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int i : left) ans = max(ans, i);
        for (int i : right) ans = max(ans, n - i);
        return ans;
    }
};