class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> datas;
        set<string> foodCount;
        for (const vector<string>& order : orders) {
            
            datas[stoi(order[1])][order[2]]++;
            foodCount.insert(order[2]);
        }
        
        vector<string> row1 = {"Table"};
        for (auto& s : foodCount) row1.push_back(s);
        
        vector<vector<string>> answer = {row1};
        for (auto& p : datas) {
            vector<string> tmp = {to_string(p.first)};
            for (auto& name : foodCount) tmp.push_back(to_string(p.second[name]));
            answer.push_back(tmp);
        }
        return answer;
    }
};
