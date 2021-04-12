class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for (int i = 1, j = n; i <= j;) {
            if (k > 1) {
                if (k % 2 == 0) {
                    ans.push_back(j);
                    j--;
                } else {
                    ans.push_back(i);
                    i++;
                }
                k--;
            } else {
                ans.push_back(i);
                i++;
            }
        }
        return ans;
    }
};
