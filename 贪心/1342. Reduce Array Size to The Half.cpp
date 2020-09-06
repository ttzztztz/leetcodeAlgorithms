class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        vector<int> occur(100005, 0);
        for (int num : arr) {
            occur[num]++;
        }
        
        set<pair<int, int>> occur_set;
        for (int i = 0; i <= 100000; i++) {
            occur_set.emplace(occur[i], i);
        }
        
        int answer = 0, current = 0;
        for (auto it = occur_set.rbegin(); it != occur_set.rend(); it++) {
            answer++;
            current += it->first;
            
            if (current >= N / 2) {
                break;
            }
        }
        return answer;
    }
};
