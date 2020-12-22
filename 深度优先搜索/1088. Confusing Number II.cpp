class Solution {
public:
    int confusingNumberII(int N) {
        n_ = to_string(N);
        
        int ans = 0;
        for (int i = 1; i < kAvailableDigit.size(); i++) {
            ans += Dfs(string{kAvailableDigit[i]});
        }
        return ans;
    }
private:
    const vector<char> kAvailableDigit = {'0', '1', '6', '8', '9'};
    string n_;
    
    bool Cmp(const string& lhs, const string& rhs) {
        if (lhs.size() == rhs.size()) return lhs <= rhs;
        else return lhs.size() < rhs.size();
    }
    
    bool Judge(const string& str) {
        string str_rev = str;
        reverse(str_rev.begin(), str_rev.end());
        for (char& ch : str_rev) {
            if (ch == '6') ch = '9';
            else if (ch == '9') ch = '6';
        }
        
        return str != str_rev;
    }
    
    int Dfs(string digit) {
        if (!Cmp(digit, n_)) return 0;
        int ans = Judge(digit);
        for (char d : kAvailableDigit) {
            ans += Dfs(digit + d);
        }
        return ans;
    }
};
