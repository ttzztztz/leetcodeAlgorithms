class Solution {
public:
    vector<int> appear;
    int sum;
    string generate() {
        bool haveNumber = false;
        for (int i : appear) if (i != 0) haveNumber = true;
        if (!haveNumber) return "";
        
        string answer;
        for (int i = 9; i >= 0; i--) {
            string t(appear[i], i + '0');
            answer += t;
        }
        while (answer.size() >= 2 && answer[0] == '0') answer.erase(answer.begin());
        return answer;
    }
    pair<bool, string> remove(int i) {
        if (appear[i]) {
            appear[i]--;
            sum -= i;
            if (sum % 3 == 0) return {true, generate()};
            else return {false, ""};
        } else {
            return {false, ""};
        }
    }
    string batchRemove(initializer_list<int> init) {
        for (int i : init) {
            auto p = remove(i);
            if (p.first) return p.second;
        }
        return "";
    }
    string largestMultipleOfThree(vector<int>& digits) {
        appear = vector<int>(10, 0);
        for (int num : digits) {
            appear[num]++;
            sum += num;
        }
        
        if (sum % 3 == 0) {
            return generate();
        } else if (sum % 3 == 1) {
            if (appear[1] || appear[4] || appear[7]) return batchRemove({1, 4, 7});
            else return batchRemove({2, 2, 5, 5, 8, 8});
            
        } else if (sum % 3 == 2) {
            if (appear[2] || appear[5] || appear[8]) return batchRemove({2, 5, 8});
            else return batchRemove({1, 1, 4, 4, 7, 7});
        }
        return "";
    }
};
