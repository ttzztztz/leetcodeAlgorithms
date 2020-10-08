class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> a;
        for (int i : deck) a[i]++;
        
        int first = 1, ans = 0;
        for (auto& i : a) {
            if (first) first = false, ans = i.second;
            else ans = __gcd(ans, i.second);
        }
        
        return ans >= 2;
    }
};
