class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> answer;
        const int n = A.size();
        
        for (int i = 0; i < n; i++) {
            const int idx = max_element(A.begin(), A.begin() + n - i) - A.begin();
            if (idx != n - i - 1) {
                if (idx > 0) answer.push_back(idx + 1);
                if (n - i - 1 > 0) answer.push_back(n - i);
                
                reverse(A.begin(), A.begin() + idx + 1);
                reverse(A.begin(), A.begin() + n - i);
            }
        }
        
        return answer;
    }
};
