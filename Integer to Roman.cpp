class Solution {
public:
    string rep(int times, char c){
        string ret;
        while(times --) ret += c;
        return ret;
    }
    string intToRoman(int num) {
        char roman10[] = "IXCM";
        char roman5[] = "VLD";
        string ans;
        for(int i = 0; num; i ++, num /= 10){
            int digit = num % 10;
            string d;
            if(digit <= 3){
                d = rep(digit, roman10[i]);
            } else if (digit == 4){
                d = (d + roman10[i]) + roman5[i];
            } else if (digit == 9){
                d = (d + roman10[i]) + roman10[i+1];   
            } else if (digit >= 5){
                d = d + roman5[i] + rep(digit - 5, roman10[i]);
            }
            ans = d + ans;
        }
        return ans;
    }
};
