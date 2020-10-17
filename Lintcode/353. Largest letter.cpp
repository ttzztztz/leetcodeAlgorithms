class Solution {
public:
    /**
     * @param s: a string
     * @return: a string
     */
    string largestLetter(string &s) {
        // write your code here
        const int n = s.size();
        unordered_set<char> a;
        for (const char ch : s) a.insert(ch);
        
        int idx = -1;
        for (const char ch : s) {
            const int offset = (ch >= 'a' && ch <= 'z') ? (ch - 'a') : (ch - 'A');
            if (a.count(offset + 'a') && a.count(offset + 'A') && offset > idx) {
                idx = offset;
            }
        }
        
        if (idx == -1) return "NO";
        else {
            const char t = 'A' + idx;
            string ans;
            ans.push_back(t);
            return ans;
        }
    }
};
