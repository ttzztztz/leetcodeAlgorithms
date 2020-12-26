class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 0) return ans_;
        n_ = n;
        dfs("");
        for (int i : kValid) {
            dfs(to_string(i));
        }
        
        return ans_;
    }
private:
    const unordered_set<int> kValid = { 0, 1, 8 };
    vector<string> ans_;
    int n_;
    
    bool valid(const string& str) {
        if (str.size() <= 1) return true;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0') {
                return false;
            } else {
                break;
            }
        }
        return true;
    }
    
    void dfs(const string& s) {
        if (s.size() > n_) {
            return;
        }
        if (s.size() == n_) {
            if (valid(s)) ans_.push_back(s);
            return;
        }
        
        for (int i : kValid) {
            dfs(to_string(i) + s + to_string(i));
        }
        dfs("6" + s + "9");
        dfs("9" + s + "6");
    }
};
