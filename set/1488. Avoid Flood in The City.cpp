class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int N = rains.size();
        vector<int> answer(N);
        set<int> chance;
        
        unordered_map<int, int> used;
        for (int i = 0; i < N; i++) {
            const int rain = rains[i];
            
            if (rain > 0) {
                if (used.count(rain)) {
                    if (!chance.empty()) {
                        const int k = used[rain];
                        
                        auto it = chance.lower_bound(k);
                        if (it == chance.end()) return vector<int>{};
                        const int top = *it;
                        chance.erase(it);
                        
                        answer[top] = rain;
                        used[rain] = i;
                    } else {
                        return vector<int>{};
                    }
                } else {
                    used[rain] = i;
                }
                answer[i] = -1;
            } else {
                chance.insert(i);
            }
        }
        
        for (int top : chance) {
            answer[top] = 1;
        }
        
        return answer;
    }
};
