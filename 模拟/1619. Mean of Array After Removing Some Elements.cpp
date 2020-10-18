class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        const int n = arr.size();
        const int remove = 0.05 * n;
        for (int i = 0; i < remove; i++) arr.pop_back(), arr.erase(arr.begin());
        int cnt = accumulate(arr.begin(), arr.end(), 0);
        
        return 1.0 * cnt / (n - 2 * remove);
    }
};
