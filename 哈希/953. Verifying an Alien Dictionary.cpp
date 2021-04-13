class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        const int n = order.size();
        unordered_map<char, int> a;
        for (int i = 0; i < n; i++) a[order[i]] = i;
        
        for (int i = 0; i + 1 < words.size(); i++) {
            const string& l = words[i], r = words[i + 1];
            
            bool ok = false;
            for (int j = 0; j < min(l.size(), r.size()); j++) {
                if (l[j] == r[j]) continue;
                
                if (a[l[j]] > a[r[j]]) {
                    return false;
                } else {
                    ok = true;
                    break;
                }
            }
            
            if (l.size() > r.size() && !ok) return false;
        }
        return true;
    }
};