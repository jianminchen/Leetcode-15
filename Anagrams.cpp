class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string,string> cache;
        map<string,bool> add;
        vector<string> ret;
        for(int i = 0 ; i < strs.size(); i ++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());
            if(cache.count(s))
            {
                add[s] = true;
                ret.push_back(strs[i]);
            }
            else
            {
                cache[s] = strs[i];
                add[s] = false;
            }
        }
        for(map<string,string>::iterator it = cache.begin(); it != cache.end() ; ++ it)
        {
            if(add[it->first] == true)
            {
                ret.push_back(it->second);
            }
        }
        return ret;
    }
};