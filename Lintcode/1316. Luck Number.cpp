class Solution {
public:
    /**
     * @param arr: the arr
     * @return: the sum of the luck number
     */
    int luckNumber(vector<int> &arr) {
        int answer = 0;
        
        const int N = arr.size();
        vector<int> f(N), g(N);
        vector<bool> existF(N, false), existG(N, false);
        
        set<int> left;
        for (int i = 0; i < N; i++) {
            auto it = left.upper_bound(arr[i]);
            if (it != left.end()) {
                existF[i] = true;
                f[i] = *it;
            }
            left.insert(arr[i]);
        }
        
        set<int> right;
        for (int i = N - 1; i >= 0; i--) {
            auto it = right.lower_bound(arr[i]);
            if (i != N - 1 && it != right.begin()) {
                it--;
                
                existG[i] = true;
                g[i] = *it;
            }
            
            right.insert(arr[i]);
        }
        
        for (int i = 1; i < N - 1; i++) {
            if (!existF[i] || !existG[i]) continue;
            if (f[i] % g[i] == 0) answer++;
        }
        
        return answer;
    }
};
