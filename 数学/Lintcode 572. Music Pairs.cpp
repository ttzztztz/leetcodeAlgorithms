class Solution {
public:
    /**
     * @param musics: the musics
     * @return: calc the number of pair of music
     */
    long long musicPairs(vector<int> &musics) {
        typedef long long ll;
        ll ans = 0;
        const int n = musics.size();
        
        unordered_map<int, ll> f;
        ll cnt30 = 0, cnt60 = 0;
        for (int i : musics) {
            if (i == 30) cnt30++;
            else if (i == 60) cnt60++;
            else f[i]++;
        }
        
        
        for (int i : musics) {
            if (i >= 30) continue;
            const int d = 60 - i;
            ans += f[d];
        }
        
        ans += cnt30 * (cnt30 - 1) / 2;
        ans += cnt60 * (cnt60 - 1) / 2;
        return ans;
    }
};
