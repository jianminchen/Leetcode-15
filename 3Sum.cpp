class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        vector<vector<int> > ret;
        for(int i = 0 ;i < num.size() ; i ++)
        {
            for(int j = i + 1 ; j < num.size() - 1; j ++)
            {
                if(binary_search(num.begin() + j + 1 , num.end(), - num[i] - num[j]  ))
                {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(-num[i]-num[j]);
                    ret.push_back(tmp);
                }
            }
        }
        sort(ret.begin(),ret.end());
        ret.erase(unique(ret.begin(),ret.end()),ret.end());
        return ret;
    }
};