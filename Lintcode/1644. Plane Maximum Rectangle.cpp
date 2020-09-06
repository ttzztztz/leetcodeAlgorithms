class Solution {
public:
    /**
     * @param a: the points
     * @return: return the maximum rectangle area
     */
    int getMaximum(vector<vector<int>> &a) {
        const int N = a.size();
        unordered_set<string> pointSet;
        for (const auto& p : a) pointSet.insert(hash(p));
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            const int x1 = a[i][0], y1 = a[i][1];
            for (int j = i + 1; j < N; j++) {
                const int x2 = a[j][0], y2 = a[j][1];
                
                if (pointSet.count(hash(vector<int>{x1, y2})) && pointSet.count(hash(vector<int>{x2, y1}))) {
                    answer = max(answer, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }
        return answer;
    }
private:
    string hash(const vector<int>& point) {
        string answer;
        answer += to_string(point[0]);
        answer += ',';
        answer += to_string(point[1]);
        return answer;
    }
};
