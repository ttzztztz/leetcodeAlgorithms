class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        typedef long long ll;
        ll m1 = memory1, m2 = memory2;
        ll bound = m1 + m2 + 1;
        vector<int> ans(3, 0);
        for (ll i = 1; i <= bound; i++) {
            if (m1 >= m2) {
                if (m1 < i) {
                    ans = vector<int>{ (int) i, (int) m1, (int) m2 };
                    return ans;
                } else {
                    m1 -= i;
                }
            } else {
                if (m2 < i) {
                    ans = vector<int>{ (int) i, (int) m1, (int) m2 };
                    return ans;
                } else {
                    m2 -= i;
                }
            }
            
        }
        return ans;
    }
};