class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        const int n = S.size();
        vector<int> ans(n, 0);
        vector<int> offset;
        for (int i = 0; i < n; i++) {
            if (S[i] == C) offset.push_back(i);
        }
        
        for (int i = 0, ptr = 0; i < n; i++) {
            if (S[i] == C) {
                ptr++;
                ans[i] = 0;
            } else {
                int cur = numeric_limits<int>::max();
                if (ptr < offset.size()) cur = min(cur, abs(offset[ptr] - i));
                if (ptr - 1 >= 0) cur = min(cur, abs(offset[ptr - 1] - i));
                
                ans[i] = cur;
            }
        }
        
        return ans;
    }
};
