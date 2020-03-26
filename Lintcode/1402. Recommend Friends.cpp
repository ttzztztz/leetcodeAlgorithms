class Solution {
public:
    /**
     * @param friends: people's friends
     * @param user: the user's id
     * @return: the person who most likely to know
     */
    int recommendFriends(vector<vector<int>> &friends, int user) {
        const int N = friends.size();
        unordered_set<int> userFriend(friends[user].begin(), friends[user].end());
        unordered_map<int, int> appear;
        for (int u : friends[user]) {
            for (int v : friends[u]) {
                if (userFriend.count(v) || v == user) continue;
                appear[v]++;
            }
        }
        
        int answer = -1, maxCount = 0;
        for (const auto& p : appear) {
            if (p.second > maxCount || (p.second == maxCount && p.first < answer)) {
                answer = p.first;
                maxCount = p.second;
            }
        }
        return answer;
    }
};
