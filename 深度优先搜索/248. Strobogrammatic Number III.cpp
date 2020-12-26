class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        low_ = low, high_ = high;
        dfs("");
        for (int i : kValid) {
            dfs(to_string(i));
        }
        return ans_;
    }
private:
    int ans_ = 0;
    const unordered_set<char> kValid = { 0, 1, 8 };
    string low_, high_;
    
    bool bigger(const string& lhs, const string& rhs) {
        // returns true if lhs > rhs
        if (lhs.size() != rhs.size()) return lhs.size() > rhs.size();
        else return lhs > rhs;
    }
    
    bool smaller_equal(const string& lhs, const string& rhs) {
        // returns true if lhs <= rhs
        if (lhs.size() != rhs.size()) return lhs.size() < rhs.size();
        else return lhs <= rhs;
    }
    
    void dfs(string str) {
        if (bigger(str, high_)) return;
        if (!str.empty() && smaller_equal(low_, str) && valid(str)) {
            ans_++;
        }
        
        for (int i : kValid) {
            dfs(to_string(i) + str + to_string(i));
        }
        dfs("6" + str + "9");
        dfs("9" + str + "6");
    }
    
    bool valid(const string& str) {
        if (str.size() <= 1) return true;
        for (const char ch : str) {
            if (ch == '0') {
                return false;
            } else {
                break;
            }
        }
        return true;
    }
};
