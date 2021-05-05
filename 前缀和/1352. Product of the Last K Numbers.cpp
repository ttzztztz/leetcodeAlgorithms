class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            last_zero = n;
            pref.push_back(1);
        } else {
            pref.push_back(pref.back() * num);
        }
        n++;
    }
    
    int getProduct(int k) {
        const int l = n - k;
        if (l <= last_zero) return 0;
        return pref.back() / pref[l];
    }
private:
    vector<int> pref = {1};
    int last_zero = -1, n = 0;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */