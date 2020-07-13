class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> all;
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            const char ch = s[i];
            if (v.count(ch)) all.push_back(ch);
        }
        reverse(all.begin(), all.end());
        
        int ptr = 0;
        for (int i = 0; i < N; i++) {
            const char ch = s[i];
            if (v.count(ch)) s[i] = all[ptr++];
        }
        return s;
    }
};