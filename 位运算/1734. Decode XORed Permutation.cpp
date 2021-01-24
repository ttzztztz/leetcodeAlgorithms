class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        const int m = encoded.size();
        
        int ttl = 0;
        for (int i = 1; i <= m + 1; i++) ttl ^= i;
        int a = 0;
        for (int i = 1; i < encoded.size(); i += 2) a ^= encoded[i];
        
        vector<int> ans(m + 1);
        ans[0] = ttl ^ a;
        
        for (int i = 1; i <= m; i++) {
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }
        
        return ans;
    }
};
