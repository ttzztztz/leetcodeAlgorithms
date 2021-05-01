class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        
        typedef long long ll;
        ll a = 1;
        for (int i = 0; i <= 35; i++) {
            ll b = 1;
            for (int j = 0; j <= 35; j++) {
                if (a + b <= bound) ans.insert(a + b);
                b *= y;
                if (b > bound || a + b > bound) break;
            }
            a *= x;
            if (a > bound) break;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
