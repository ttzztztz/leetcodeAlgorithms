class Solution {
public:
    /**
     * @param employees: information of the employees
     * @param friendships: the friendships of employees
     * @return: return the statistics
     */
    vector<string> departmentStatistics(vector<string> &employees, vector<string> &friendships) {
        unordered_map<string, vector<string>> edge;
        unordered_map<string, string> peopleInDepart;
        unordered_map<string, int> departPeopleCount;
        unordered_map<string, vector<string>> departPeople;
        
        for (const string& s : friendships) {
            stringstream ss;
            ss << s;
            
            string a, b;
            ss >> a >> b;
            a.pop_back();
            
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        
        for (const string& employee : employees) {
            stringstream ss;
            ss << employee;
            string id, name, depart;
            ss >> id >> name >> depart;
            
            id.pop_back();
            name.pop_back();
            
            
            departPeopleCount[depart]++;
            peopleInDepart[id] = depart;
            departPeople[depart].push_back(id);
        }
        
        vector<string> answer;
        for (auto& p : departPeopleCount) {
            string depart;
            int cnt;
            tie(depart, cnt) = p;
            
            int relationCnt = 0;
            for (const string& f : departPeople[depart]) {
                bool isok = false;
                
                for (const string& q : edge[f]) {
                    if (peopleInDepart[q] != depart) {
                        isok = true;
                        break;
                    }
                }
                
                if (isok) relationCnt++;
            }
            
            string tmp = depart;
            tmp += ": ";
            tmp += to_string(relationCnt);
            tmp += " of ";
            tmp += to_string(cnt);
            answer.push_back(tmp);
        }
        return answer;
    }
};
