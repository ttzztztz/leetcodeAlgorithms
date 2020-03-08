class Solution {
public:
    string sortString(string s) {
        string answer;
        
        sort(s.begin(), s.end());
        multiset<char> q;
        for (const char ch : s) q.insert(ch);
        
        while (!q.empty()) {
            char ch = *q.begin();
            q.erase(q.begin());
            answer += ch;
            while (true) {
                auto it = q.upper_bound(ch);
                if (it == q.end()) break;
                answer += *it;
                ch = *it;
                q.erase(it);
            }
            
            if (q.empty()) break;
            
            auto it = q.end();
            it--;
            ch = *it;
            q.erase(it);
            answer += ch;
            while (true) {
                auto it = q.lower_bound(ch);
                if (it == q.begin()) break;
                it--;
                
                answer += *it;
                ch = *it;
                q.erase(it);
            }
        }
        
        return answer;
    }
};
