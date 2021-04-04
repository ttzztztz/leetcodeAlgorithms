class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        typedef long long ll;
        ll ans = 0;
        const int mod = 1e9+7;
        unordered_map<int, int> h;
        
        for (int i : nums) {
            const int t = i - rev(i);
            ans = (ans + h[t]) % mod;
            h[t]++;
        }
        return ans;
    }
private:
    int rev(int t) {
        string a = to_string(t);
        reverse(a.begin(), a.end());
        return stoi(a);
    }
};
