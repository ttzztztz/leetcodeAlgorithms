class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        const int len1 = encoded1.size(), len2 = encoded2.size();
        vector<vector<int>> ans;

        for (int ptr1 = 0, ptr2 = 0; ptr2 < len2; ptr2++) {
            const int val2 = encoded2[ptr2][0];
            int freq2 = encoded2[ptr2][1];

            while (freq2 > 0) {
                const int val1 = encoded1[ptr1][0];
                const int freq1 = encoded1[ptr1][1];

                const int product = val1 * val2;
                const int cur_freq = min(freq1, freq2);

                if (!ans.empty() && ans.back()[0] == product) ans.back()[1] += cur_freq;
                else ans.push_back(vector<int>{ product, cur_freq });

                if (cur_freq >= freq1) ptr1++;
                else encoded1[ptr1][1] -= cur_freq;
                freq2 -= cur_freq;
            }
        }

        return ans;
    }
};