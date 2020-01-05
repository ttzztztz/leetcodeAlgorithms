iclass Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> answer;
        
        vector<int> friendList;
        const int N = friends.size();
        vector<bool> visited(N, false);
        deque<pair<int, int>> queue;
        visited[id] = true;
        queue.emplace_back(id, 0);
        while (!queue.empty()) {
            int _id, dist;
            tie(_id, dist) = queue.front();
            queue.pop_front();
            
            if (dist == level) friendList.push_back(_id);
            if (dist >= level) continue;
            for (int v : friends[_id]) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.emplace_back(v, dist + 1);
                }
            }
        }
        
        unordered_map<string, int> frequency;
        for (const int _id : friendList) {
            for (const string& video : watchedVideos[_id]) {
                frequency[video]++;
            }
        }
        map<int, vector<string>> reverse_frequency;
        for (const auto& f : frequency) {
            reverse_frequency[f.second].push_back(f.first);
        }
        for (const auto& r : reverse_frequency) {
            vector<string> t = r.second;
            sort(t.begin(), t.end());
            for (const string& s : t) {
                answer.push_back(s);
            }
        }
        return answer;
    }
};
