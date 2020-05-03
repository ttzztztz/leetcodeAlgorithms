class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outDegree;
        unordered_set<string> city;
        
        for (auto& p : paths) {
            city.insert(p[0]);
            city.insert(p[1]);
            
            outDegree[p[0]]++;
        }
        
        for (const string& c : city) {
            if (outDegree[c] == 0) {
                return c;
            }
        }
        return "";
    }
};
