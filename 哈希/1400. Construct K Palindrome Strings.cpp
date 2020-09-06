class Solution {
public:
    bool canConstruct(string s, int k) {
        const int N = s.size();
        
        if (k == N) return true;
        if (k > N) return false;
        
        unordered_map<char, int> appear;
        for (const char ch : s) appear[ch]++;
        
        int oddNumber = 0;
        for (auto& p : appear) {
            if (p.second % 2 == 1) oddNumber++;
        }
        
        if (oddNumber <= 1) return true;
        else return k >= oddNumber;
    }
};
