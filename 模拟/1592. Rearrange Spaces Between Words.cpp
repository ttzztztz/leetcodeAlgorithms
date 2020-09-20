class Solution {
public:
    string reorderSpaces(string text) {
        const int n = text.size();
        string tmp;
        vector<string> lst;
        int white = 0;
        for (int i = 0; i < n; i++) {
            if (text[i] == ' ') {
                white++;
                if (!tmp.empty()) {
                    lst.push_back(tmp);
                    tmp.clear();
                }
            } else {
                tmp.push_back(text[i]);
            }
        }
        if (!tmp.empty()) lst.push_back(tmp);
        
        string ans;
        if (lst.size() == 1) {
            ans = lst[0];
            string whitespace(white, ' ');
            ans += whitespace;
            return ans;
        }
        const int avg = white / (lst.size() - 1), extra = white % (lst.size() - 1);
        for (int i = 0; i < lst.size(); i++) {
            ans += lst[i];
            
            string whitespace((i == lst.size() - 1) ? extra : avg, ' ');
            ans += whitespace;
        }
        return ans;
    }
};
