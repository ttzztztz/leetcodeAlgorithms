class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> a;
        for (int i : nums) a[i]++;
        
        map<int, set<int>> f;
        for (auto& p : a) f[p.second].insert(p.first);
        
        for (auto& p : f) {
            for (auto it = p.second.rbegin(); it != p.second.rend(); it++) {
                for (int k = 0; k < p.first; k++) {
                    ans.push_back(*it);
                }
            }
        }
        
        return ans;
    }
};
