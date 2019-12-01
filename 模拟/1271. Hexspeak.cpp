class Solution {
public:
    string toHexspeak(string num) {
        stringstream ss;
        ss << num;
        long long cur = 0;
        ss >> cur;

        char buf[15];
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%lx", cur);

        cout << buf << endl;
        cout << cur << endl;

        int offset = 0;
        string answer;
        while (buf[offset] != '\0') {
            if (buf[offset] >= '2' && buf[offset] <= '9') {
                return "ERROR";
            } else {
                if (buf[offset] == '0') {
                    buf[offset] = 'O';
                } else if (buf[offset] == '1') {
                    buf[offset] = 'I';
                } else {
                    buf[offset] += 'A' - 'a';
                }
            }

            answer.push_back(buf[offset]);
            offset++;
        }

        return answer;
    }
};