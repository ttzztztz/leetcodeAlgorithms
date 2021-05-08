class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0, sum = 0;
        
        const int n = light.size();
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum += f[i];
            
            if (light[i - 1] <= i) sum++;
            else f[light[i - 1]]++;
            
            if (sum == i) ans++;
        }
        return ans;
    }
};