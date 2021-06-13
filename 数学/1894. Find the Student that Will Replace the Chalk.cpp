class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        typedef long long ll;
        ll sum = accumulate(chalk.begin(), chalk.end(), 0ll);
        ll t = k % sum;
        
        const int n = chalk.size();
        for (int i = 0; i < n; i++) {
            if (t < chalk[i]) return i;
            else t -= chalk[i];
        }
        return -1;
    }
};