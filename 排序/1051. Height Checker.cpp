class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> right = heights;
        sort(right.begin(), right.end());
        
        int answer = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (right[i] != heights[i]) answer++;
        }
        return answer;
    }
};
