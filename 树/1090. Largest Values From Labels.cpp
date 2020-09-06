class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        typedef pair<int, int> PII;
        vector<PII> all;
        const int N = values.size();
        for (int i = 0; i < N; i++)
            all.emplace_back(values[i], labels[i]);
        
        sort(all.begin(), all.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1.first > $2.first;
        });
        
        int answer = 0, selected = 0;
        unordered_map<int, int> appear;
        for (int i = 0; i < N && selected < num_wanted; i++) {
            int val, lab;
            tie(val, lab) = all[i];
            
            // cout << val << ", " << lab << endl;
            if (appear[lab] + 1 <= use_limit) {
                appear[lab]++;
                selected++;
                answer += val;
            }
        }
        return answer;
    }
};
