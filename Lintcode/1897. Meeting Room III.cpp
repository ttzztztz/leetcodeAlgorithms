class Solution {
public:
    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &intervals, int rooms, vector<vector<int>> &ask) {
        const int N = intervals.size(), M = ask.size();
        vector<int> diff(50005, 0), cnt(50005, 0);
        for (auto& p : intervals) {
            diff[p[0]]--;
            diff[p[1]]++;
        }
        
        vector<bool> answer(M, false);
        for (int i = 0; i <= 50000; i++) {
            rooms += diff[i - 1];
            
            cnt[i] = cnt[i - 1];
            if (rooms == 0) cnt[i]++;
        }
        
        for (int i = 0; i < M; i++) {
            answer[i] = cnt[ask[i][0]] == cnt[ask[i][1]];
        }
        
        return answer;
    }
};
