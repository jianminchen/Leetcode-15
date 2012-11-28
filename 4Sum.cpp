class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        multimap< int, pair<int,int> > cache;
        
        sort(num.begin(),num.end());
        
        for(int i = 0 ;i < num.size() ; i ++)
        {
            for(int j = i + 1 ; j < num.size() ; j ++)
            {
                cache.insert( make_pair( num[i] + num[j], make_pair(i , j) ) );
            }
        }
        vector< vector<int> > ret;
        typedef multimap< int, pair<int,int> >::const_iterator IT;
        typedef pair<IT,IT> PIT;
        for(IT it = cache.begin(); it !=  cache.end() ; ++ it)
        {
            int val = target - it->first;
            PIT range = cache.equal_range(val);
            for(IT it2 = range.first ; it2 != range.second ; it2 ++)
            {
                if(it2->second.first > it->second.second)
                {
                    vector<int> tmp;
                    tmp.push_back(num[it->second.first]);
                    tmp.push_back(num[it->second.second]);
                    tmp.push_back(num[it2->second.first]);
                    tmp.push_back(num[it2->second.second]);
                    ret.push_back(tmp);
                }
            }
        }
        sort(ret.begin(),ret.end());
        ret.erase(unique(ret.begin(),ret.end()),ret.end());
        return ret;
    }
};