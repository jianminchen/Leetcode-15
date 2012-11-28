class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        int i = 1 , j = 0;
        while ( i < n )
        {
            if(A[i] == A[j])
            {
                i ++;
                continue;
            }
            else
            {
                j ++;
                A[j] = A[i];
                i ++;
            }
            
        }
        return j + 1;
    }
};