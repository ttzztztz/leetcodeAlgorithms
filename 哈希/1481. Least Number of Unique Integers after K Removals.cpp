class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> a;
        for (int i : arr) a[i]++;
        
        vector<int> t;
        for (auto& [k, v] : a) t.push_back(v);
        sort(t.begin(), t.end());
        
        int ans = t.size();
        for (int i = 0; i < t.size(); i++) {
            k -= t[i];
            if (k < 0) break;
            ans--;
        }
        
        return ans;
    }
};