class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty()) return -1;

        ll l = 1, r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            const ll mid = (l + r) / 2;

            if (solve(piles, mid) <= h) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
private:
    typedef long long ll;
    ll solve(const vector<int>& piles, int speed) {
        ll ans = 0;
        for (int i : piles) {
            ans += i / speed;
            if (i % speed > 0) ans++;
        }
        return ans;
    }
};