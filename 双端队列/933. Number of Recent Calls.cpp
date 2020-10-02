class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push_back(t);
        while (!q.empty() && q.front() < t - 3000) q.pop_front();
        return q.size();
    }
private:
    deque<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
