class Solution {
public:
    vector<string> expand(string S) {
        vector<string> ans;
        if (S.empty()) return ans;
        ans = { "" };
        for (int i = 0; i < S.size(); i++) {
            const char ch = S[i];
            if (ch == '{') {
                vector<char> available;
                while (i < S.size()) {
                    if (S[i] >= 'a' && S[i] <= 'z') {
                        available.push_back(S[i]);
                    } else if (S[i] == '}') {
                        break;
                    }
                    i++;
                }
                
                vector<string> nxt_ans;
                for (const char ch : available) {
                    for (const string& str : ans) {
                        nxt_ans.push_back(str + ch);
                    }
                }
                ans = nxt_ans;
            } else { // ch is character
                for (string& str : ans) str += ch;
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
