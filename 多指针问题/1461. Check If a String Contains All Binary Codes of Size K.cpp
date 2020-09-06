class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> all;
        
        string cur = s.substr(0, k);
        all.insert(cur);
        
        for (int i = k; i < s.size(); i++) {
            cur.erase(cur.begin());
            cur.push_back(s[i]);
            
            all.insert(cur);
        }
        
        return all.size() == (1 << k);
    }
};
