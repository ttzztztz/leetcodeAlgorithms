class Solution {
public:
    int numSplits(string s) {
        vector<int> emptyState(26, 0);
        vector<vector<int>> pref = {emptyState};
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            vector<int> lst = pref[i];
            lst[s[i] - 'a']++;
            pref.push_back(lst);
        }
        
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            const vector<int>& fnt = pref[i];
            vector<int> snd = pref[N];
            for (int j = 0; j < 26; j++) snd[j] -= fnt[j];
            
            int d1 = 0, d2 = 0;
            for (int j = 0; j < 26; j++) {
                if (fnt[j]) d1++;
                if (snd[j]) d2++;
            }
            
            
            if (d1 == d2) answer++;
        }
        return answer;
    }
};
