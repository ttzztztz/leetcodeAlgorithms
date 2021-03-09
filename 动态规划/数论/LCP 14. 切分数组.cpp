const int maxn = 1e6;
int f[maxn + 10], g[maxn + 10];

class Solution {
public:
    int splitArray(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> h;
        init();

        for (int i = 0; i < n; i++) {
            if (i >= 1) f[i] = f[i - 1] + 1;
            else f[i] = 1;

            int t = nums[i];
            while (t > 1) {
                const int factor = g[t];
                if (h.count(factor)) {
                    if (h[factor] >= 1) f[i] = min(f[i], f[h[factor] - 1] + 1);
                    else f[i] = min(f[i], 1);
                } else {
                    h[factor] = i;
                }

                if (f[i] < f[h[factor]]) {
                    h[factor] = i;
                }
                t /= factor;
            }
        }

        return f[n - 1];
    }
private:
    void init() {
        memset(f, 0, sizeof f);
        memset(g, 0xff, sizeof g);

        for (int i = 2; i <= maxn; i++) {
            if (g[i] != -1) continue;

            for (int j = i; j <= maxn; j += i) {
                g[j] = i;
            }
        }
    }
};
