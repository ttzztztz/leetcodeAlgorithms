class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int n = arr.size();
        unordered_map<int, int> a;
        for (int i : arr) a[i]++;
        
        vector<int> b;
        for (auto& [k, v] : a) b.push_back(v);
        sort(b.begin(), b.end());
        
        int ans = 0, cur = 0;
        for (int i = b.size() - 1; i >= 0; i--) {
            cur += b[i];
            ans++;
            if (cur >= n / 2) break;
        }
        return ans;
    }
};