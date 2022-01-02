class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long all = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int m : asteroids) {
            if (m <= all) {
                all += m;
            } else {
                return false;
            }
        }
        return true;
    }
};
