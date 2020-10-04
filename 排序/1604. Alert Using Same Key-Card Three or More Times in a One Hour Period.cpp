class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        set<string> ans;
        const int n = keyName.size();
        
        typedef pair<string, int> PSI;
        vector<PSI> data;
        for (int i = 0; i < n; i++) {
            data.emplace_back(keyName[i], ts(keyTime[i]));
        }
        sort(data.begin(), data.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1.second < $2.second;
        });
        
        unordered_map<string, deque<int>> lst;
        for (int i = 0; i < n; i++) {
            const string& name = data[i].first;
            const int s = data[i].second;
            
            if (lst[name].empty()) {
                lst[name].push_back(s);
            } else {
                while (!lst[name].empty() && s - lst[name].front() > 60) lst[name].pop_front();
                lst[name].push_back(s);
                
                if (lst[name].size() >= 3) ans.insert(name);
            }
        }
        
        return vector<string>(ans.begin(), ans.end());
    }
private:
    int ts(const string& str) {
        string tmp;
        tmp += str[0];
        tmp += str[1];
        const int h = stoi(tmp);
        tmp.clear();
        tmp += str[3];
        tmp += str[4];
        const int m = stoi(tmp);
        return h * 60 + m;
    }
};
