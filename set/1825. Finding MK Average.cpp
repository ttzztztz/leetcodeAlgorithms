class MKAverage {
public:
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
    }
    
    void addElement(int num) {
        data.push_back(num);
        
        if (!mis.empty() && num <= *mis.rbegin()) mis.insert(num);
        else if (!mxs.empty() && *mis.begin() <= num) mxs.insert(num);
        else candidate.insert(num), sum_middle += num;
        
        while (mis.size() > k) {
            sum_middle += *mis.rbegin();
            shift_right(mis, candidate);
        }
        while (mxs.size() > k) {
            sum_middle += *mxs.begin();
            shift_left(candidate, mxs);
        }
        
        if (data.size() > m) {
            const int t = data.front();
            data.pop_front();
            
            if (mis.find(t) != mis.end()) mis.erase(mis.find(t));
            else if (candidate.find(t) != candidate.end()) candidate.erase(candidate.find(t)), sum_middle -= t;
            else mxs.erase(mxs.find(t));
         }
        
        if (data.size() >= m) {
            while (mis.size() < k) {
                sum_middle -= *candidate.begin();
                shift_left(mis, candidate);
            }
            while (mxs.size() < k) {
                sum_middle -= *candidate.rbegin();
                shift_right(candidate, mxs);
            }
        }
    }
    
    int calculateMKAverage() {
        if (data.size() < m) return -1;

        ll b = m - 2 * k;
        return sum_middle / b;
    }
private:
    int m, k;
    deque<int> data;
    multiset<int> mxs, mis, candidate;
    typedef long long ll;
    ll sum_middle = 0;
    
    void shift_left(multiset<int>& l, multiset<int>& r) {
        l.insert(*r.begin());
        r.erase(r.begin());
    }
    
    void shift_right(multiset<int>& l, multiset<int>& r) {
        r.insert(*l.rbegin());
        l.erase(--l.end());
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */