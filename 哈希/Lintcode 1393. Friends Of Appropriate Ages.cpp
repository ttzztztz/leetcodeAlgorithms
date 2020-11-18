class Solution {
public:
    /**
     * @param ages: 
     * @return: nothing
     */
    int numFriendRequests(vector<int> &ages) {
        unordered_map<int, int> v;
        for (int a : ages) v[a]++;
        
        int ans = 0;
        for (auto& p1 : v) {
            for (auto& p2 : v) {
                if (ok(p1.first, p2.first)) {
                    ans += (p1.second - (p1.first == p2.first)) * p2.second;
                }
            }
        }
        return ans;
    }
private:
    bool ok(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};
