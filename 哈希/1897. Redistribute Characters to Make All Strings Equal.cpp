class Solution {
public:
    bool makeEqual(vector<string>& words) {
        const int n = words.size();
        unordered_map<char, int> a;
        for (const string& word : words) for (const char ch : word) a[ch]++;
        
        for (auto&[k, v] : a) {
            if (v % n != 0) return false;
        }
        return true;
    }
};