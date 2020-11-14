class Solution {
public:
    /**
     * @param a: the array you need to operate.
     * @param b: the target array.
     * @return: return the minimum number of operations.
     */
    int minimumInsertion(vector<int> &a, vector<int> &b) {
        // write your code here.
        const int n = a.size();
        
        unordered_map<int, int> app;
        for (int i = 0; i < n; i++) app[b[i]] = i;
        for (int& i : a) i = app[i];
        
        int answer = 0, cur = 1;
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && a[i] > a[i - 1]) cur++;
            else cur = 1;
            
            answer = max(answer, cur);
        }
        return n - answer;
    }
};