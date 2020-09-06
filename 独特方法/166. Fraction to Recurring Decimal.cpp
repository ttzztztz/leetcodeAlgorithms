class Solution {
public:
    string fractionToDecimal(int a, int b) {
        string answer;
        string sign;
        
        long long _a = a, _b = b;
        if ((_a < 0 && _b > 0) || (_a > 0 && _b < 0)) sign = "-", _a *= -1;
        if (_a < 0 && _b < 0) _a *= -1, _b *= -1;
        int repeatIndex = -1;
        
        string _int = to_string(_a / _b);
        string _small;
        unordered_map<long long, int> appear;
        _a = _a % _b;
        int index = 0;
        while (_a) {
            if (appear.count(_a)) {
                repeatIndex = appear[_a];
                break;
            }
            
            appear[_a] = index;
            index++;
            
            _a *= 10;
            _small += to_string(_a / _b);
            _a %= _b;
        }
        
        if (repeatIndex == -1) {
            if (_small.empty()) answer = sign + _int;
            else answer = sign + _int + "." + _small;
        } else {
            answer = sign + _int + "." + _small.substr(0, repeatIndex) + "(" + _small.substr(repeatIndex) + ")";
        }
        return answer;
    }
};
