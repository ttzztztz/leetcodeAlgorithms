class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> a, b;
        for (const char ch : s) a[ch]++;
        for (const char ch : t) b[ch]++;
        
        int ans = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            ans += abs(a[ch] - b[ch]);
        }
        return ans / 2;
    }
};