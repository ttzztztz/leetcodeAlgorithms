class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        const int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int abs = numeric_limits<int>::max();
        for (int i = 0, j = 1; j < n; i++, j++) {
            if (arr[j] - arr[i] == abs) {
                ans.push_back(vector<int>{ arr[i], arr[j] });
            } else if (arr[j] - arr[i] < abs) {
                abs = arr[j] - arr[i];
                ans = { { arr[i], arr[j] } };
            }
        }
        
        return ans;
    }
};
