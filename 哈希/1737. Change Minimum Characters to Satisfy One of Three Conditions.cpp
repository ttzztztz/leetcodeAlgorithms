class Solution {
public:
    int minCharacters(string a, string b) {
        return min(max_occurrence(a) + max_occurrence(b), min(change(a, b), change(b, a)));
    }
private:
    int max_occurrence(const string& s) {
        const int len = s.size();
        int mx = 0;
        
        unordered_map<char, int> appear;
        for (const char ch : s) appear[ch]++;
        
        for (auto [k, v] : appear) mx = max(mx, v);
        return len - mx;
    }
    
    int change(const string& a, const string& b) {
        unordered_map<char, int> aa, ab;
        for (const char ch : a) aa[ch]++;
        for (const char ch : b) ab[ch]++;
        
        int ans = numeric_limits<int>::max();
        for (char i = 'a'; i + 1 <= 'z'; i++) {
            int cur = 0;
            for (char x = 'a'; x <= i; x++) {
                cur += ab[x];
            }
            for (char x = 'z'; x >= i + 1; x--) {
                cur += aa[x];
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
