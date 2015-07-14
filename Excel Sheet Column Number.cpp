class Solution {
public:
    int titleToNumber(string s) {
        int value = 0;
        for(auto it = s.begin(); it != s.end(); it ++)
        {
            value = value * 26 + (*it - 'A') + 1;
        }
        return value;
    }
};
