class Solution {
public:
    /**
     * @param s: string need to be transformed
     * @param k: minimum char can be transformed in one operation
     * @return: minimum times to transform all char into '1'
     */
    int perfectString(string &s, int k) {
        vector<int> conse;
        int cur = 0, answer = 0;
        const int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cur++;
            } else {
                if (cur > 0) {
                    conse.push_back(cur);
                    cur = 0;
                }
            }
        }
        
        if (cur > 0) conse.push_back(cur);
        for (int i : conse) {
            answer += i / k;
            if (i % k) answer++;
        }
        
        return answer;
    }
};
