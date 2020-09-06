class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        alreadyCheckin[id] = {stationName, t};
    }
    
    void checkOut(int id, string outStation, int t) {
        string inStation;
        int inTime;
        tie(inStation, inTime) = alreadyCheckin[id];
        
        alreadyCheckin.erase(id);
        string routeHash = hash(inStation, outStation);
        if (!allTime.count(routeHash)) {
            allTime[routeHash] = {1, t - inTime};
        } else {
            int cnt;
            long long total;
            tie(cnt, total) = allTime[routeHash];
            
            allTime[routeHash] = {cnt + 1, total + t - inTime};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeHash = hash(startStation, endStation);
        
        int cnt;
        long long total;
        tie(cnt, total) = allTime[routeHash];
        
        return (1.0 * total) / (1.0 * cnt);
    }
private:
    unordered_map<int, pair<string, int>> alreadyCheckin;
    unordered_map<string, pair<int, long long>> allTime;
    string hash(string from, string to) {
        string answer;
        answer += from;
        answer += ',';
        answer += to;
        return answer;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
