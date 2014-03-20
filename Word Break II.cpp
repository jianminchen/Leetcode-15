class Solution {
public:
    vector<string> answer;
    vector<string> dic;
    vector<int> dp;
    string gs;
    int n, m;
    
    void dfs(int cur, string print){
        if(cur == gs.size())
        {
            answer.push_back(print);
            return;
        }
        int m = dic.size();
        for(int j = 0 ; j < m ; j ++)
        {
            int k = cur + dic[j].size();
            if( k <= gs.size() && gs.substr(cur, dic[j].size()) == dic[j])
            {
                dfs(k, print+ (print.size() == 0 ? "" : " ") + dic[j] );
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        gs = s;
        for(unordered_set<string>::iterator it = dict.begin() ; it != dict.end(); it ++){
            dic.push_back(*it);
        }
        n = s.size();
        m = dic.size();
        
        dp = vector<int>(n + 1, 0);
        dp[0] = 1;
        for(int i = 0 ;i < n ; i ++)
        {
            if(dp[i] == 0) continue;
            for(int j = 0 ; j < m ; j ++)
            {
                int k = i + dic[j].size();
                if(k <= n && s.substr(i, dic[j].size()) == dic[j])
                    dp[k] = 1;
            }
        }
        if(dp[n] == 0) return answer;
        dfs(0,"");
        return answer;
    }
};