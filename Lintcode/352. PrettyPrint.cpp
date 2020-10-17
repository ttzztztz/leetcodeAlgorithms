class Solution {
public:
    /**
     * @param text: the text to print
     * @param width: the width of the window
     * @return: return the result of pretty print.
     */
    vector<string> prettyPrint(vector<vector<string>> &text, int width) {
        vector<string> ans;
        for (const vector<string>& sentence : text) {
            string tmp;
            for (const string& str : sentence) {
                if (tmp.empty()) tmp += str;
                else if (tmp.size() + 1 + str.size() <= width) tmp += " " + str;
                else {
                    ans.push_back(tmp);
                    tmp.clear();
                    tmp += str;
                }
            }
            
            if (!tmp.empty()) ans.push_back(tmp);
        }
        
        for (auto& str : ans) {
            while (str.size() != width) str += " ";
        }
        return wrap(ans, width);
    }
private:
    vector<string> wrap(const vector<string>& t, int width) {
        vector<string> ans;
        string tail(width + 2, '*');
        ans.push_back(tail);
        for (const string& str : t) {
            string cur = "*";
            cur += str;
            cur += "*";
            ans.push_back(cur);
        }
        ans.push_back(tail);
        return ans;
    }
};
