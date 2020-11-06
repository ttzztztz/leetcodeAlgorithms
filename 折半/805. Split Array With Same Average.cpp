class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        const int n = A.size();
        for (int i = 0; i < n; i++) {
            if (i < (n / 2)) A1.push_back(A[i]);
            else A2.push_back(A[i]);
        }
        
        s = accumulate(A.begin(), A.end(), 0);
        enumerate2();
        return decide();
    }
private:
    vector<int> A1, A2;
    unordered_map<int, unordered_set<int>> s2;
    int s;
    
    bool decide() {
        const int n = A1.size();
        const int m = A1.size() + A2.size();
        
        const int mask = (1 << n) - 1;
        for (int state = 0; state <= mask; state++) {
            int sum = 0, k = 0;
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) {
                    sum += A1[i], k++;
                }
            }
            
            for (int len = k + 1; len < m; len++) {
                if (s2.count(len - k) && s2[len - k].count(s * len - sum * m)) return true;
            }
        }
        
        return false;
    }
    void enumerate2() {
        const int m = A1.size() + A2.size();
        
        const int n = A2.size();
        const int mask = (1 << n) - 1;
        for (int state = 1; state <= mask; state++) {
            int sum = 0, k = 0;
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) {
                    sum += A2[i], k++;
                }
            }
            
            s2[k].insert(sum * m);
        }
    }
};
