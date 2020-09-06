class Solution {
public:
    /**
     * @param str: the string
     * @return: the number of substrings 
     */
    int stringCount(string &str) {
        int answer = 0;
        const int N = str.size();
        vector<int> f(N + 1, 0);
        for (int i = N - 1; i >= 0; i--) {
            if (str[i] == '0') f[i] = f[i + 1] + 1;
            else f[i] = 0;
        }
        
        for (int i = 0; i < N; i++) answer += f[i];
        return answer;
    }
};
