class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_multiset<string> all(strings.begin(), strings.end());
        
        vector<vector<string>> ans;
        for (const string& str : strings) {
            if (!all.count(str)) continue;
            vector<string> cur;
            for (int k = 0; k < 26; k++) {
                string nxt = str;
                for (char& ch : nxt) {
                    const int d = ch - 'a';
                    ch = 'a' + (d + k) % 26;
                }

                while (all.count(nxt)) {
                    all.erase(all.find(nxt));
                    cur.push_back(nxt);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
