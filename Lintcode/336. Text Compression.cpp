class Solution {
public:
    /**
     * @param lines: the text to compress.
     * @return: return the text after compression.
     */
    vector<string> textCompression(vector<string> &lines) {
        vector<string> ans;
        for (const string& str : lines) {
            string cur, tmp;
            for (const char& ch : str) {
                if (isAlpha(ch)) tmp += ch;
                else {
                    if (!tmp.empty()) {
                        if (appear.count(tmp)){
                            cur += to_string(appear[tmp]);
                        } else {
                            appear[tmp] = ++cnt;
                            cur += tmp;
                        }
                        tmp.clear();
                    }
                    
                    cur += ch;
                }
            }
            
            if (!tmp.empty()) {
                if (appear.count(tmp)){
                    cur += to_string(appear[tmp]);
                } else {
                    appear[tmp] = ++cnt;
                    cur += tmp;
                }
                tmp.clear();
            }
            
            ans.push_back(cur);
        }
        return ans;
    }
private:
    unordered_map<string, int> appear;
    int cnt = 0;
    
    bool isAlpha(const char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};
