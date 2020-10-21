class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        const int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            const int t = asteroids[i];
            
            if (t > 0) ans.push_back(t);
            else { // t < 0
                bool add = true;
                while (!ans.empty() && ans.back() > 0) {
                    if (-t == ans.back()) { // both remove
                        ans.pop_back();
                        add = false;
                        break;
                    } else if (-t < ans.back()) { // remove t
                        add = false;
                        break;
                    } else { // remove ans
                        ans.pop_back();
                    }
                }
                
                if (add) ans.push_back(t);
            }

        }
        
        return ans;
    }
};
