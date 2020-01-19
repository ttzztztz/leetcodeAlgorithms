class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        const int N = clips.size();
        sort(clips.begin(), clips.end(), [](const vector<int>& $1, const vector<int>& $2)->bool {
            return $1[0] < $2[0];
        });
        
        int answer = 0;
        for (int i = 0, left = 0, right = 0; right < T; answer++, left = right) {
            for (; i < N && clips[i][0] <= left; i++) {
                right = max(right, clips[i][1]);
            }
            
            if (left == right) return -1;
        }
        return answer;
    }
};
