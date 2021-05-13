class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        const int n = s.size();
        vector<string> ans;
        for (int i = 1; i + 2 < n; i++) {
            vector<string> set1 = solve(s.substr(1, i)), set2 = solve(s.substr(i + 1, n - i - 2));
            for (string& a : set1) for (string& b : set2) {
                ans.push_back("(" + a + ", " + b + ")");
            }
        }
        return ans;
    }
private:
    vector<string> solve(const string& str) {
        vector<string> ans;
        const int n = str.size();
        if (valid(str)) {
            ans.push_back(str);
        }
        for (int i = 1; i < n; i++) {
            const string component1 = str.substr(0, i), component2 = str.substr(i);
                
            string tmp = component2;
            reverse(tmp.begin(), tmp.end());
            if (valid(component1) && valid(tmp) && tmp != "0") {
                ans.push_back(component1 + "." + component2);
            }
        }
        return ans;
    }
    bool valid(const string& str) {
        if (str.size() <= 1) return true;
        return str[0] != '0';
    }
};