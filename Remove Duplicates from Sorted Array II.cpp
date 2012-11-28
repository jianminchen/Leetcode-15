class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        int i = 1 , j = 0, k = 1;
        while ( i < n )
        {
            if(A[i] == A[j])
            {
                if(k < 2)
                {
                    j ++;
                    A[j] = A[i];
                    i ++;
                }
                else
                {
                    i ++;
                }
                k ++;
                continue;
            }
            else
            {
                k = 1;
                j ++;
                A[j] = A[i];
                i ++;
            }
            
        }
        return j + 1;
    }
};