class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int incr = 0;
        unordered_map<string, int> email_to_id;
        vector<string> id_to_person;
        vector<string> id_to_email;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string email = accounts[i][j];
                if (!email_to_id.count(email)) {
                    email_to_id[email] = incr;
                    id_to_person.push_back(accounts[i][0]);
                    id_to_email.push_back(email);

                    incr++;
                }
            }
        }

        init(incr);
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 2; j < accounts[i].size(); j++) {
                const int id1 = email_to_id[accounts[i][j]];
                const int id2 = email_to_id[accounts[i][j - 1]];

                merge(id1, id2);
            }
        }

        unordered_map<int, set<string>> parent_to_account;
        for (int i = 0; i < incr; i++) {
            const int u = find_parent(i);
            parent_to_account[u].insert(id_to_email[i]);
        }

        vector<vector<string>> ans;
        for (auto& [k, v] : parent_to_account) {
            vector<string> row = { id_to_person[k] };
            
            for (const string& str : v) {
                row.push_back(str);
            }

            ans.push_back(row);
        }
        return ans;
    }
private:
    vector<int> parent;

    void init(int n) {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void merge(int x, int y) {
        const int parent_x = find_parent(x);
        const int parent_y = find_parent(y);

        if (parent_x != parent_y) {
            parent[parent_x] = parent_y;
        }
    }

    int find_parent(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find_parent(parent[i]);
    }
};