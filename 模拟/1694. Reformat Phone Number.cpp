class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] >= '0' && number[i] <= '9') s += number[i];
        }
        
        string ans;
        const int n = s.size();
        vector<string> a;
        for (int i = 0; i < n; i++) {
            if (a.empty()) {
                a.push_back(string{s[i]});
            } else {
                if (a.back().size() < 3) a.back() += s[i];
                else a.push_back(string{s[i]});
            }
        }
        
        if (a.size() >= 2 && a.back().size() == 1) {
            string str = a.back();
            a.pop_back();
            
            str = a.back().back() + str;
            a.back().pop_back();
            a.push_back(str);
        }
        for (const string& str : a) ans += str + "-";
        ans.pop_back();
        return ans;
    }
};
