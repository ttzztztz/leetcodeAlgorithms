class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int n = binary.size();
        const int mod = 1e9+7;
        typedef long long ll;
        
        ll end0 = 0, end1 = 0, has0 = 0;
        for (int i = 0; i < n; i++) {
            const int cur = binary[i] == '1' ? 1 : 0;
            
            if (cur == 1) {
                end1 = (end0 + end1 + 1) % mod;
            } else {
                end0 = (end0 + end1) % mod;
                has0 = 1;
            }
        }
        return (end0 + end1 + has0) % mod;
    }
};