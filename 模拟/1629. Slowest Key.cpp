class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = 0;
        int t = -1;
        
        const int n = keysPressed.size();
        for (int i = 0; i < n; i++) {
            const char ch = keysPressed[i];
            int times = releaseTimes[i];
            if (i - 1 >= 0) times -= releaseTimes[i - 1];
            
            if (times > t || (times == t && ch > ans)) {
                ans = ch;
                t = times;
            }
        }
        
        return ans;
    }
};
