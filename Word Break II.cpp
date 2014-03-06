class Solution {
public:
    vector<string> answer;
    void dfs(int cur,  string print, string& s, unordered_set<string> & dict){
        if(cur == 0){
            answer.push_back(print);
            return;
        }
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end() ; it++ )
        {
            int k = cur - it->size();
            if( k >= 0 && s.substr(k, it->size()) == *it){
                dfs(k,  *it + (print.size() == 0 ? "" : " ") + print, s, dict);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        dfs(s.size(), "", s, dict);
        return answer;
    }
};