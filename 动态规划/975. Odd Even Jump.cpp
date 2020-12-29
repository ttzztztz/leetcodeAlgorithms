class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        if (A.empty()) return 0;
        vector<int> nxt_pos_odd(A.size(), -1);
        vector<int> nxt_pos_even(A.size(), -1);
        
        set<int> numbers(A.begin(), A.end());
        unordered_map<int, deque<int>> all_occur;
        for (int i = 0; i < A.size(); i++) all_occur[A[i]].push_back(i);
        
        const int n = A.size();
        for (int i = 0; i < n - 1; i++) {
            all_occur[A[i]].pop_front();
            if (all_occur[A[i]].empty()) numbers.erase(A[i]);
            
            auto it1 = numbers.lower_bound(A[i]);
            if (it1 != numbers.end()) {
                nxt_pos_odd[i] = all_occur[*it1].front();
            }
            
            if (it1 != numbers.begin() && 
                (it1 == numbers.end() || *it1 > A[i])) {
                it1--;
            }
            
            if (A[i] >= *it1) {
                nxt_pos_even[i] = all_occur[*it1].front();
            }
        }
        vector<vector<int>> f(A.size(), vector<int>(2, 0));
        f[n - 1][1] = f[n - 1][0] = 1;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nxt_pos_odd[i] != -1) {
                f[i][1] |= f[nxt_pos_odd[i]][0];
            }
            
            if (nxt_pos_even[i] != -1) {
                f[i][0] |= f[nxt_pos_even[i]][1];
            }
            
            if (f[i][1]) ans++;
        }
        return ans;
    }
};
