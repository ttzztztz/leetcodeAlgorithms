class Solution {
public:
    /**
     * @param trees: the positions of trees.
     * @param d: the minimum beautiful interval.
     * @return: the minimum number of trees to remove to make trees beautiful.
     */
    int treePlanning(vector<int> &trees, int d) {
        int answer = 0;
        
        const int n = trees.size();
        int prev = trees[0];
        for (int i = 1; i < n; i++) {
            if (trees[i] - prev < d) {
                answer++;
            } else {
                prev = trees[i];
            }
        }
        
        return answer;
    }
};
