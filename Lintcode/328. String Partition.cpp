class Solution {
public:
    /**
     * @param s: a string
     * @return:  an array containing the length of each part
     */
    vector<int> splitString(string &s) {
        const int n = s.size();
        vector<int> answer;
        unordered_map<char, int> app;
        for (const char ch : s) app[ch]++;
        
        unordered_map<char, int> cur;
        auto ok = [&]() -> bool {
            for (auto& p : cur) {
                if (!(p.second == 0 || p.second == app[p.first])) return false;
            }
            return true;
        };
        
        for (int l = 0, r = 0; r < n; r++) {
            cur[s[r]]++;
            
            if (ok()) {
                cur.clear();
                answer.push_back(r - l + 1);
                l = r + 1;
            }
        }
        
        return answer;
    }
};
