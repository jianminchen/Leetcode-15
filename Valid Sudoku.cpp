class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0 ;i < 9 ; i ++)
        {
            int state  = 0;
            for(int j = 0 ; j < 9 ; j ++)
            {
                if(board[i][j] == '.') continue;
                int k = board[i][j] - '1';
                if(state & (1 << k)) return false;
                state |= 1 << k;
            }
        }
        for(int i = 0 ;i < 9 ; i ++)
        {
            int state  = 0;
            for(int j = 0 ; j < 9 ; j ++)
            {
                if(board[j][i] == '.') continue;
                int k = board[j][i] - '1';
                if(state & (1 << k)) return false;
                state |= 1 << k;
            }
        }
        for(int i = 0 ;i < 3 ; i ++)
            for(int j = 0 ;j < 3 ; j ++)
            {
                int state = 0;
                for(int pc = i * 3 ; pc < i * 3 + 3 ; pc ++)
                {
                    for(int rp = j * 3 ; rp < j * 3 + 3 ; rp ++)
                    {
                        if(board[pc][rp] == '.') continue;
                        int k = board[pc][rp] - '1';
                        if(state & (1 << k)) return false;
                        state |= 1 << k;
                    }
                }
            }
        return true;
    }
};