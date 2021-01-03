class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int ans = 0;
        const int mod = 1e9+7;
        vector<int> pow2;
        for (int i = 0; i <= 21; i++) pow2.push_back(1 << i);
        
        typedef long long ll;
        unordered_map<int, ll> appear;
        for (int i : deliciousness) {
            for (int j : pow2) {
                if (appear.count(j - i)) ans = (ans + appear[j - i]) % mod; 
            }
            
            appear[i]++;
        }
        
        return ans;
    }
};
