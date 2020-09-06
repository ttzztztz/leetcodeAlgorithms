class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) {
            return 0;
        }

        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] = std::min(triangle[i][j] + triangle[i - 1][j - 1], triangle[i][j] + triangle[i - 1][j]);
                }
            }
        }

        int answer = 0x7fffffff;
        for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
            answer = std::min(answer, triangle[triangle.size() - 1][i]);
        }
        return answer;
    }
};