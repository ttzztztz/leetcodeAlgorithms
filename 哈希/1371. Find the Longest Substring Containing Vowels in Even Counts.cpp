class Solution {
public:
    unordered_map<char, int> statics;
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    int hash() {
        int answer = 0;
        if (statics['a'] % 2 == 1) answer |= 1 << 0;
        if (statics['e'] % 2 == 1) answer |= 1 << 1;
        if (statics['i'] % 2 == 1) answer |= 1 << 2;
        if (statics['o'] % 2 == 1) answer |= 1 << 3;
        if (statics['u'] % 2 == 1) answer |= 1 << 4;
        return answer;
    }
    
    int findTheLongestSubstring(string s) {
        const int N = s.size();
        vector<int> first(1 << 5, N);
        first[0] = -1;
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            const char ch = s[i];
            if (vowel.count(ch)) statics[ch]++;
            
            first[hash()] = min(first[hash()], i);
            answer = max(answer, i - first[hash()]);
        }
        return answer;
    }
};
