class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        int delta = 1000000000,ans ;
        int size = num.size();
        for(int i = 0 ; i <  size; i ++) {
            vector<int>::iterator last = num.end();
            for(int j = i + 1 ; j < size - 1; j ++) {
                int val = target - num[i] - num[j];
                vector<int>::iterator it = lower_bound(num.begin() + j + 1,last,val);
                if(it != num.end()) {
                    last = it;
                    if(abs(num[i] + num[j] + *it - target) < delta) {
                        delta = abs(num[i] + num[j] + *it - target);
                        ans = num[i] + num[j] + *it;
                    }
                    --it;
                    if(it >= num.begin() + j + 1) {
                        if(abs(num[i] + num[j] + *it - target) < delta) {
                            delta = abs(num[i] + num[j] + *it - target);
                            ans = num[i] + num[j] + *it;
                        }
                    }
                } else {
                    val = num[i] + num[j] + num.back();
                    if(target - val < delta) {
                        delta = target - val ;
                        ans = val;
                    }
                }

            }
        }
        return ans;
    }
};
