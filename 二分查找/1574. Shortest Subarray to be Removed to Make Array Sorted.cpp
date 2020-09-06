class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size();
        vector<int> f = {0}, g = {n - 1};
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) f.push_back(i);
            else break;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i + 1] >= arr[i]) g.push_back(i);
            else break;
        }
        
        reverse(g.begin(), g.end());
        int answer = min(n - f.size(), n - g.size());
        
        for (int i = 0; i < f.size(); i++) {
            const int idx = f[i];
            
            auto it = upper_bound(g.begin(), g.end(), idx);
            int l = it - g.begin(), r = g.size() - 1;
            while (l <= r) {
                const int mid = (l + r) >> 1;
                const int g_idx = g[mid];
                
                if (arr[idx] <= arr[g_idx]) {
                    r = mid - 1;
                    answer = min(answer, max(0, g_idx - idx - 1));
                } else {
                    l = mid + 1;
                }
            }
        }
        return answer;
    }
};
