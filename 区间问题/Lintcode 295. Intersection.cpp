class Solution {
public:
    /**
     * @param a: first sequence
     * @param b: second sequence
     * @return: return ans
     */
    vector<vector<int>> Intersection(vector<vector<int>> &a, vector<vector<int>> &b) {
        // write your code here
        vector<vector<int>> ans;
        const int n = a.size(), m = b.size();
        
        for (int i = 0, j = 0; i < n && j < m;) {
            if (max(a[i][0], b[j][0]) <= min(a[i][1], b[j][1])) {
                const int l = max(a[i][0], b[j][0]);
                const int r = min(a[i][1], b[j][1]);

                ans.push_back(vector<int>{ i, j });
            }

            if (a[i][1] < b[j][1]) i++;
            else j++;
        }
        
        return ans;
    }
};
