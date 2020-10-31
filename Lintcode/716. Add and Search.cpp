class Solution {
public:
    /**
     * @param inputs: an integer array
     * @param tests: an integer array
     * @return: return true if sum of two values in inputs are in tests.
     */
    bool addAndSearch(vector<int> &inputs, vector<int> &tests) {
        unordered_set<int> memo;
        for (int i : tests) memo.insert(i);
        
        const int n = inputs.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                const int sum = inputs[i] + inputs[j];
                
                if (memo.count(sum)) return true;
            }
        }
        
        return false;
    }
};
