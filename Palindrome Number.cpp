class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char tmp[20];
        sprintf(tmp,"%d",x);
        int len = strlen(tmp);
        for(int i = 0 , j = len - 1 ; i < j ; i ++ , j --)
        {
            if(tmp[i] != tmp[j]) return false;
        }
        return true;
    }
};