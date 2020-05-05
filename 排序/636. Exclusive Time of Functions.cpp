class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> answer(n);
        
        int lastTimeStamp = 0;
        vector<int> stk;
        for (const string& log : logs) {
            string id, type, timestamp;
            auto idx1 = log.find(':');
            auto idx2 = log.find(':', idx1 + 1);
            id = log.substr(0, idx1);
            type = log.substr(idx1 + 1, idx2 - idx1 - 1);
            timestamp = log.substr(idx2 + 1);
            
            int _id = stoi(id);
            int _timestamp = stoi(timestamp);
            if (type == "start") {
                if (!stk.empty()) {
                    answer[stk.back()] += _timestamp - lastTimeStamp;
                }
                stk.push_back(_id);
                lastTimeStamp = _timestamp;
            } else { // end
                answer[stk.back()] += _timestamp - lastTimeStamp + 1;
                stk.pop_back();
                lastTimeStamp = _timestamp + 1;
            }
            // for (int i : answer) cout << i << " ";
            // cout << endl;
        }
        
        return answer;
    }
};
