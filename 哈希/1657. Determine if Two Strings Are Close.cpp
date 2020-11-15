class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> a1, a2;
        for (const char ch : word1) a1[ch]++;
        for (const char ch : word2) a2[ch]++;
        
        if (a1 == a2) return true;
        vector<int> v1, v2;
        vector<char> c1, c2;
        for (const auto& p : a1) v1.push_back(p.second), c1.push_back(p.first);
        for (const auto& p : a2) v2.push_back(p.second), c2.push_back(p.first);
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        return v1 == v2 && c1 == c2;
    }
};
