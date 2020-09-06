class Solution {
public:
    int findTheLongestSubstring(string s) {
        const int N = s.size();
        
        unordered_map<char, int> vowel = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        vector<int> first(1 << 5, N);
        first[0] = -1;
        
        int answer = 0, code = 0;
        for (int i = 0; i < N; i++) {
            const char ch = s[i];
            if (vowel.count(ch)) {
                code ^= 1 << (vowel[ch]);
            }
            first[code] = min(first[code], i);
            answer = max(answer, i - first[code]);
        }
        return answer;
    }
};
