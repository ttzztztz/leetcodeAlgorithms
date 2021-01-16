class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (ans.empty()) ans.push_back(arr[i]);
            else {
                const int t = ans.back();
                while (!ans.empty() && ans.back() >= arr[i]) ans.pop_back();
            
                ans.push_back(max(arr[i], t));
            }
            
        }
        return ans.size();
    }
};
