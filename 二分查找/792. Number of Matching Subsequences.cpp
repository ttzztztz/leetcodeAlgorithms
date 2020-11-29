class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> idx(26, vector<int>{}); // for each char, its index in S
	    const int n = S.size();
	    for (int i = 0; i < n; i++) {
		    idx[S[i] - 'a'].push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
	        const string& word = words[i];
	
	        bool ok = true;
	        for (int j = 0, last = 0; j < word.size(); j++) {
		        const char ch = word[j];
		        auto it = lower_bound(idx[ch - 'a'].begin(), idx[ch - 'a'].end(), last);
        
		        if (it == idx[ch - 'a'].end()) {
			        ok = false;
			        break;
		        } else {
			        last = *it + 1;
                }
            }
            if (ok) ans++;
            
        }
        return ans;
    }
};


