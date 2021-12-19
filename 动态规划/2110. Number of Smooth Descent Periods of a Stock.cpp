class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        typedef long long ll;
        const int n = prices.size();
        
        ll ans = 0, last = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (i >= 1 && prices[i] == prices[i - 1] - 1) {
                last++;
            } else {
                last = 1;
            }
            // cout << i << "," << last << endl;
            ans += last;
        }
        // cout << endl;
        return ans;
    }
};
