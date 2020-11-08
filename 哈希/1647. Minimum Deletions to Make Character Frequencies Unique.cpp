class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        
        unordered_map<char, int> freq;
        for (const char ch : s) freq[ch]++;
        
        unordered_set<int> used;
        for (auto [ch, t] : freq) {
            while (t > 0 && used.count(t)) {
                t--;
                ans++;
            }
            
            if (t > 0) used.insert(t);
        }
        return ans;
    }
};
