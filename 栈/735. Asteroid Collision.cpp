class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        const int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            const int m = asteroids[i];

            if (m > 0) {
                ans.push_back(m);
            } else if (m < 0) {
                bool explode = false;
                while (!ans.empty() && ans.back() > 0) {
                    const int u = ans.back();

                    if (abs(m) >= u) {
                        ans.pop_back();
                    }

                    if (abs(m) <= u) {
                        explode = true;
                        break; // explode
                    }
                }

                if (!explode) ans.push_back(m);
            }
        }

        return ans;
    }
};