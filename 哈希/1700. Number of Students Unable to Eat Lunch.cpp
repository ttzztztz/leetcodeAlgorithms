class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> cnt(2, 0);
        for (int i : students) {
            cnt[i]++;
        }
        
        const int n = sandwiches.size();
        int k = 0;
        for (; k < n && cnt[sandwiches[k]] > 0; k++) {
            cnt[sandwiches[k]]--;
        }
        return n - k;
    }
};
