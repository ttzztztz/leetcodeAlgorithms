class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        const int n = digits.size();
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) {
            if (i == j || j == k || i == k) continue;
            
            string t;
            t += '0' + digits[i];
            t += '0' + digits[j];
            t += '0' + digits[k];
            
            if (t[0] != '0' && (t.back() - '0') % 2 == 0) {
                ans.insert(stoi(t));
            } 
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
