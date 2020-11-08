class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        
        unordered_map<char, int> freq;
        for (const char ch : s) freq[ch]++;
        
        multiset<int> vec;
        for (const auto& p : freq) {
            vec.insert(p.second);
        }
        
        while (!vec.empty()) {
            auto it = --vec.end();
            int val = *it;
            
            vec.erase(it);
            if (vec.count(val)) {
                if (val - 1 > 0) vec.insert(val - 1);
                ans++;
            }
        }
        return ans;
    }
};
