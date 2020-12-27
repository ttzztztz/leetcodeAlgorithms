class Solution {
public:
    bool confusingNumber(int N) {
        const unordered_set<char> kSame = {'0', '1', '8'};
        string s = to_string(N);
        
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        for (char& ch : s_rev) {
            if (kSame.count(ch)) {
                continue;
            } else if (ch == '6') {
                ch = '9';
            } else if (ch == '9') {
                ch = '6';
            } else {
                return false;
            }
        }
        
        return stoll(s) != stoll(s_rev);
    }
};
