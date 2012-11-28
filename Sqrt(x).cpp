int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0 , high = 46340 , mid , res;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(mid * mid > x)
            {
                high = mid - 1;
            }
            else
            {
                res = mid;
                low = mid + 1;
            }
        }
        return res;
    }