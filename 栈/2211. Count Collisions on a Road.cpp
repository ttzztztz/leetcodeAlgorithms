class Solution {
public:
    int countCollisions(string directions) {
        // RRRRL
        int ans = 0;
        
        vector<char> stk;
        const int n = directions.size();
        for (int i = 0; i < n; i++) {
            const char d = directions[i];

            if (d == 'L') {
                bool crash = false;
                while (!stk.empty() && (stk.back() == 'R' || stk.back() == 'S')) {
                    if (crash && stk.back() == 'S') break;
                    
                    if (stk.back() == 'R' && !crash) ans += 2;
                    else ans++;
                    
                    stk.pop_back();
                    crash = true;
                }
                
                if (crash) stk.push_back('S');
                else stk.push_back('L');
            } else if (d == 'R') {
                stk.push_back('R');
            } else if (d == 'S') {
                bool crash = false;
                while (!stk.empty() && stk.back() == 'R') {
                    stk.pop_back();
                    ans++;
                    crash = true;
                }
                
                stk.push_back('S');
            }
        }
        return ans;
    }
};
