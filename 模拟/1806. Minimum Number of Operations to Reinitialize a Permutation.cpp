class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> p;
        for (int i = 0; i < n; i++) p.push_back(i);
        vector<int> origin = p;
        
        int ans = 0;
        do {
            vector<int> arr(n);
            ans++;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    arr[i] = p[i / 2];
                } else {
                    arr[i] = p[n / 2 + (i - 1) / 2];
                }
            }
            p = arr;
        } while (origin != p);
        return ans;
    }
};
