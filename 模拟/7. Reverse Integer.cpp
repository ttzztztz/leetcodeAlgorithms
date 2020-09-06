class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;
        string s = to_string(x);
        if (negative) s.erase(s.begin());
        
        ::reverse(s.begin(), s.end());
        
        long long t = stol(s);
        if (negative) t *= -1;
        
        if (t > numeric_limits<int>::max() || t < numeric_limits<int>::min()) return 0;
        
        return t;
    }
};