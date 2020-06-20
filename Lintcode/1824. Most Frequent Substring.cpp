class Solution {
public:
    /**
     * @param s: string s
     * @param minLength: min length for the substring
     * @param maxLength: max length for the substring
     * @param maxUnique: max unique letter allowed in the substring
     * @return: the max occurrences of substring
     */
    int getMaxOccurrences(string &s, int minLength, int maxLength, int maxUnique) {
        int answer = 0;
        answer = max(answer, solve(s, minLength, maxUnique));
        return answer;
    }
private:
    int solve(const string& s, int len, int maxUnique) {
        int answer = 0;
        vector<char> memo(26, 0);
        int cnt = 0;
        unordered_map<string, int> app;
        string cur;
        for (int r = 0; r < len; r++) {
            memo[s[r] - 'a']++;
            if (memo[s[r] - 'a'] == 1) cnt++;
            cur.push_back(s[r]);
        }
        
        if (cnt <= maxUnique) {
            app[cur]++;
            answer = max(answer, app[cur]);
        }
        for (int r = len; r < s.size(); r++) {
            int l = r - len;
            
            memo[s[r] - 'a']++;
            if (memo[s[r] - 'a'] == 1) cnt++;
            memo[s[l] - 'a']--;
            if (memo[s[l] - 'a'] == 0) cnt--;
            
            cur.push_back(s[r]);
            cur.erase(cur.begin());
            
            if (cnt <= maxUnique) {
                app[cur]++;
                answer = max(answer, app[cur]);
            }
        }
        return answer;
    }
};
