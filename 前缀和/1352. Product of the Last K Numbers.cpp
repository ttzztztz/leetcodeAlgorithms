class ProductOfNumbers {
public:
    vector<long long> data;
    vector<long long> prefix;
    set<int> zeroPos;
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            zeroPos.insert(prefix.size());
            data.push_back(num);
            prefix.push_back(1);
        } else {
            prefix.push_back(num * (*prefix.rbegin()));
        }
    }
    
    int getProduct(int k) {
        const int N = prefix.size();
        const int last = N - 1, begin = N - k - 1;
        auto it = zeroPos.lower_bound(begin + 1);
        if (it != zeroPos.end()) {
            return 0;
        } else {
            return prefix[last] / prefix[begin];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
