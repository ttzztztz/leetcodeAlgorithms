class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) {
        const int N = array.size();
        vector<int> next(N + 2, 0);
        next[0] = -1, next[1] = 0;
        
        int i = 1, j = 0;
        while (i <= N) {
            if (j == -1 || array[i] == array[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        
        return N - next[N];
    }
};
