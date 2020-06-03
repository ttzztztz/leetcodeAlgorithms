class Solution {
public:
    int calculate(string s) {
        vector<long long> stk;
        const int N = s.size();
        
        long long lastVal = 0;
        char opt = 0;
        
        auto calc = [&]() -> void {
            long long tmp = lastVal;
            if (opt == '+') {
                tmp = lastVal;
            } else if (opt == '-') {
                tmp = -lastVal;
            } else if (opt == '*') {
                const int f = stk.back();
                stk.pop_back();
                tmp = f * lastVal;
            } else if (opt == '/') {
                const int f = stk.back();
                stk.pop_back();
                tmp = f / lastVal;
            }
            stk.push_back(tmp);
        };
        
        for (int i = 0; i < N; i++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                lastVal = lastVal * 10 + s[i] - '0';
                continue;
            }
            
            calc();
            lastVal = 0;
            opt = s[i];
        }
        
        calc();
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
