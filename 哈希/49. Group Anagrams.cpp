class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        
        for (string str : strs) {
            const string original = str;
            sort(str.begin(), str.end());
            h[str].push_back(original);
        }
        
        vector<vector<string>> ans;
        for (auto& [_, v] : h) ans.push_back(v);
        return ans;
    }
};
