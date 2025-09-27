class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index =0;
        for(int i = 0; i<n; i++){
            for(int j =0 ; j<m; j++){
                if(board[i][j] == word[index]){
                    if(searchnext(board, word, n,m,index,i,j)) return true;
                }
            }
        }
        return false;
    }
    bool searchnext(vector<vector<char>>& board,string word, int n, int m, int index, int i, int j){
        if(index == word.length()) return true;
        if(i <0 || j<0 || i == n||j == m || board[i][j] != word[index] || board[i][j] == '!') return false;
        char c = board[i][j];
        board[i][j] = '!';
        bool top = searchnext(board, word,n,m,index+1,i-1,j);
        bool right = searchnext(board, word,n,m,index+1,i,j-1);
        bool bottom = searchnext(board, word,n,m,index+1,i+1,j);
        bool left = searchnext(board, word,n,m,index+1,i,j+1);
        board[i][j] = c;
        return top || right || bottom || left;
    }
};