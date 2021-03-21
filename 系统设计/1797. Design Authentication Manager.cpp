class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        gc(currentTime);
        exp[tokenId] = currentTime + ttl;
        remove.emplace_back(tokenId, currentTime + ttl);
    }
    
    void renew(string tokenId, int currentTime) {
        gc(currentTime);
        if (exp.count(tokenId)) {
            exp[tokenId] = currentTime + ttl;
            remove.emplace_back(tokenId, currentTime + ttl);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        gc(currentTime);
        return exp.size();
    }
private:
    int ttl;
    unordered_map<string, int> exp;
    list<pair<string, int>> remove;

    void gc(int t) {
        while (!remove.empty() && remove.front().second <= t) {
            auto [token, expire] = remove.front();
            remove.pop_front();
            
            if (exp.count(token) && exp[token] == expire) {
                exp.erase(token);
            }
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
