class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> answer;
        vector<int> data;
        for (int i = 0; i < m; i++) data.push_back(i + 1);
        
        for (int i : queries) {
            auto it = find(data.begin(), data.end(), i);
            answer.push_back(it - data.begin());
            
            int tmp = *it;
            data.erase(it);
            data.insert(data.begin(), tmp);
        }
        return answer;
    }
};
