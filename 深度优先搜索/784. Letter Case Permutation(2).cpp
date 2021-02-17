class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> cur = {""};
        
        const int n = S.size();
        for (int i = 0; i < n; i++) {
            if (S[i] >= '0' && S[i] <= '9') {
                for (string& s : cur) s += S[i];
            } else {
                vector<string> nxt = cur;
                for (string& s : nxt) s += S[i];
                for (const string& s : cur) nxt.push_back(s + transform(S[i]));
                cur = nxt;
            }
        }
        
        return cur;
    }
private:
    char transform(const char ch) {
        if (ch >= 'a' && ch <= 'z') {
            const int idx = ch - 'a';
            return idx + 'A';
        } else {
            const int idx = ch - 'A';
            return idx + 'a';
        }
    }
};
