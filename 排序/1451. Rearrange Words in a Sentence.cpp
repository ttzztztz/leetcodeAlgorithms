class Solution {
public:
    string arrangeWords(string text) {
        if (text.empty()) return "";
        vector<string> splitted = split(text);
        splitted[0][0] = splitted[0][0] - 'A' + 'a';
        
        stable_sort(splitted.begin(), splitted.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return lhs.size() < rhs.size();
        });
        
        splitted[0][0] = splitted[0][0] - 'a' + 'A';
        string ans;
        for (int i = 0; i < splitted.size(); i++) {
            if (i != 0) ans += " ";
            ans += splitted[i];
        }
        return ans;
    }
private:
    vector<string> split(const string& str) {
        vector<string> ans;
        
        string tmp;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                ans.push_back(tmp);
                tmp.clear(); // forgot ... 
            } else {
                tmp += str[i];
            }
        }
        
        ans.push_back(tmp);
        return ans;
    }
};