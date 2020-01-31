class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the palindromic permutations (without duplicates) of it
     */
    int N;
    char middle;
    
    vector<string> generatePalindromes(string &s) {
        vector<string> answer;
        N = s.size(), middle = '\0';
        
        vector<int> appear(26, 0);
        for (char ch : s) {
            appear[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            int& cnt = appear[i];
            if (cnt % 2 == 0) continue;
            
            if (N % 2 == 1) {
                if (middle == '\0') {
                    middle = 'a' + i;
                } else {
                    return answer;
                }
            } else {
                return answer;
            }
        }
        
        string prefix;
        for (int i = 0; i < 26; i++) {
            string current(appear[i] / 2, 'a' + i);
            prefix += current;
        }
        unordered_set<string> temp;
        dfs(0, prefix, temp);
        answer = vector<string>(temp.begin(), temp.end());
        return answer;
    }
    void dfs(int i, string& s, unordered_set<string>& temp) {
        if (i == s.size()) {
            string reversed_prefix = s;
            reverse(reversed_prefix.begin(), reversed_prefix.end());
            
            string current = s;
            if (N % 2 == 1) current += middle;
            current += reversed_prefix;
            temp.emplace(current);
        }
        
        for (int start = i; i < s.size(); i++) {
            if (i != start && s[i] == s[start]) continue;
            
            swap(s[start], s[i]);
            dfs(start + 1, s, temp);
            swap(s[start], s[i]);
        }
    }
};
