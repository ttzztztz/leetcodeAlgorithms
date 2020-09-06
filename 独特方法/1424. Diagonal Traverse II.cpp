class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> answer;
        typedef tuple<int, int, int> TII;
        vector<TII> tmp;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                tmp.emplace_back(i + j, j, nums[i][j]);
            }
        }
        
        sort(tmp.begin(), tmp.end());
        for (auto& t : tmp) answer.push_back(get<2>(t));
        return answer;
    }
};
