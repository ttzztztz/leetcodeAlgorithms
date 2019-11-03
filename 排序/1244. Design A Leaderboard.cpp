class Leaderboard {
public:
    vector<pair<int, int>> scoreList;
    Leaderboard() {}

    void addScore(int playerId, int score) {
        bool find = false;

        int i = 0;
        for (i = 0; i < scoreList.size(); i++) {
            pair<int, int>& s = scoreList[i];
            if (s.first == playerId) {
                s.second += score;
                find = true;
                break;
            }
        }

        if (!find) {
            i = scoreList.size();
            scoreList.push_back(make_pair(playerId, score));
        }

        while (i - 1 >= 0 && scoreList[i - 1].second < scoreList[i].second) {
            swap(scoreList[i - 1], scoreList[i]);
            i--;
        }

    }

    int top(int K) {
        int answer = 0;
        for (int i = 0; i < K; i++) {
            answer += scoreList[i].second;
        }
        return answer;
    }

    void reset(int playerId) {
        for (int i = 0; i < scoreList.size(); i++) {
            if (scoreList[i].first == playerId) {
                scoreList.erase(scoreList.begin() + i);
                break;
            }
        }
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */