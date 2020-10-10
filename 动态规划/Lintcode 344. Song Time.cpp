class Solution {
public:
    /**
     * @param song: an array represent song'time
     * @param M: an integer represent sont time limit
     * @return: return the longest time for song
     */
    int LongestSongTime(vector<int> &song, int M) {
        sort(song.begin(), song.end());
        const int last = song.back();
        song.pop_back();
        vector<int> f(M, 0);
        
        for (int i = 0; i < song.size(); i++) {
            for (int j = M - 1; j >= song[i]; j--) {
                f[j] = max(f[j], f[j - song[i]] + song[i]);
            }
        }
        
        return f[M - 1] + last;
    }
};
