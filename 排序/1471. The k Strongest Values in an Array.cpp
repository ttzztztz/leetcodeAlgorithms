class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        const int N = arr.size();
        sort(arr.begin(), arr.end());
        const int m = arr[(N - 1) / 2];
        
        sort(arr.begin(), arr.end(), [&](const auto& $1, const auto& $2) -> bool{
            const int a = abs($1 - m), b = abs($2 - m);
            if (a == b) {
                return $1 > $2;
            } else {
                return a > b;
            }
        });
        
        arr.resize(k);
        return arr;
    }
};
