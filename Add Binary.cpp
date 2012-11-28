class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s;
        if(a.size() > b.size()) swap(a,b);
        int add = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i = 0 ; i < b.size() ; i ++)
        {
            int sum = b[i] - '0' + add;
            if(i < a.size()) 
                sum += a[i] - '0';
            s += sum % 2 ? '1' : '0';
            add = sum > 1 ? 1 : 0;
        }
        if(add)
            s += '1';
        reverse(s.begin(),s.end());
        
        return s;
    }
};