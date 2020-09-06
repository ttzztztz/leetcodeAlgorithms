class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& $1, const vector<int>& $2)->bool {
           if ($1[0] == $2[0]) {
               return $1[1] < $2[1];
           } else {
               return $1[0] > $2[0];
           }
        });
        
        vector<vector<int>> answer;
        for (const vector<int>& p : people) {
            answer.insert(answer.begin() + p[1], p);
        }
        return answer;
    }
};
