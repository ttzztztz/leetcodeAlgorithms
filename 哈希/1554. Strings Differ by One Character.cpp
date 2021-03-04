class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_set<string> h;
        
        for (const string& str : dict) {
            for (int j = 0; j < str.size(); j++) {
                string cur = str;
                for (char k = 'a'; k <= 'z'; k++) {
                    if (k == str[j]) continue;
                    
                    cur[j] = k;
                    if (h.count(cur)) return true;
                }
            }
            h.insert(str);
        }
        return false;
    }
};
