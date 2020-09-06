class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, vector<int>>> _mat;
        for (int i = 0; i < mat.size(); i++) {
            _mat.emplace_back(i, mat[i]);
        }
        
        sort(_mat.begin(), _mat.end(), [&](const pair<int, vector<int>>& $1, const pair<int, vector<int>>& $2)->bool {
            int _1 = 0, _2 = 0;
            for (int i = 0; i < $1.second.size(); i++) {
                if ($1.second[i] == 1) _1++;
                if ($2.second[i] == 1) _2++;
            }
            
            if (_1 == _2) {
                return $1.first < $2.first;
            }
            return _1 < _2;
        });
        
        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(_mat[i].first);
        }
        return answer;
    }
};
