class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            const int shop = entry[0], movie = entry[1], price = entry[2];
            pair<int, int> data = {shop, movie};
            
            initm[data] = price;
            hm[movie][price].insert(shop);
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        auto& s = hm[movie];
        
        auto it = s.begin();
        while (ans.size() < 5) {
            if (it == s.end()) break;
            
            auto [price, shops] = *it;
            for (int shop : shops) {
                ans.push_back(shop);
                if (ans.size() == 5) break;
            }
            it++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        pair<int, int> data = {shop, movie};
        const int price = initm[data];
        
        r[price].insert(data);
        hm[movie][price].erase(shop);
    }
    
    void drop(int shop, int movie) {
        pair<int, int> data = {shop, movie};
        const int price = initm[data];
        
        r[price].erase(data);
        hm[movie][price].insert(shop);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        
        auto it = r.begin();
        while (ans.size() < 5) {
            if (it == r.end()) break;
            
            auto [price, datas] = *it;
            for (auto [shop, movie] : datas) {
                ans.push_back(vector<int>{shop, movie});
                if (ans.size() == 5) break;
            }
            it++;
        }
        
        return ans;
    }
private:
    typedef set<pair<int, int>> DataSet;
    map<pair<int, int>, int> initm; // [shop, movie] -> price
    
    map<int, DataSet> r; // price -> set< [shop, movie] >
    unordered_map<int, map<int, set<int>>> hm; // movie -> map<price, set[shop]>
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */