class Solution {
public:
    /**
     * @param str: the string
     * @param k: the length
     * @return: the substring with  the smallest lexicographic order
     */
    string deleteChar(string &str, int k) {
        const int N = str.size();
        if (k == N) return str;
        if (k == 0) return "";
        
        k = N - k;
        
        vector<char> stk;
        for (int i = 0; i < N; i++) {
            if (stk.empty() || stk.back() < str[i]) stk.push_back(str[i]);
            else {
                while (stk.back() > str[i] && k) {
                    k--;
                    stk.pop_back();
                }
                stk.push_back(str[i]);
            }
        }
        
        while (k) {
            k--;
            stk.pop_back();
        }
        
        return string(stk.begin(), stk.end());
    }
};
