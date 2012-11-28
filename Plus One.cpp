class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        digits[digits.size()-1] ++;
        vector<int> ret;
        for(int i = digits.size() - 1 ; i>= 0 ; i --)
        {
            if(digits[i] == 10)
            {
                digits[i] = 0;
                if(i - 1 >= 0)
                {
                    digits[i - 1] ++;
                    
                }
                else
                {
                    ret.push_back(1);
                }
                
            }
        }
        for(int i = 0; i < digits.size() ; i ++)
            ret.push_back(digits[i]);
        return ret;
    }
};