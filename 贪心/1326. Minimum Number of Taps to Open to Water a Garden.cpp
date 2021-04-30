class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int N = ranges.size();
        vector<vector<int>> range;
        
        for (int i = 0; i < ranges.size(); i++) {
            range.push_back(vector<int>{i - ranges[i], i + ranges[i]});
        }
        sort(range.begin(), range.end());
        
        int answer = 0;
        for (int i = 0, left = 0, right = 0; right < n; left = right, answer++) {
            for (; i < N && range[i][0] <= left; i++) {
                right = max(right, range[i][1]);
            }
            
            if (right == left) {
                return -1;
            }
        }
        return answer;
    }
};
