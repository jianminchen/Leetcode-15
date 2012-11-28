class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        double ans = pow(x,n/2);
        if(n%2) return ans * ans * ((n > 0) ? x : 1 / x);
        else return ans * ans;
    }
};