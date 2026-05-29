class Solution {
public:
    void addSol(vector<string>&board,vector<vector<string>>&ans,int n){
        /*vector<string>temp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }*/
        ans.push_back(board);
    }
    bool isSafe(int row,int col,vector<string>&board,int n){
        int x =row;
        int y = col;
        //column is already sorted
        //check row
        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }
        x = row;
        y=col;
        //check diagonal top
        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        //check diagonal bottom
        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }

        return true;

    }
    void solve(int col,vector<vector<string>>&ans, vector<string>&board,int n ){
        //base cond
        if(col == n){
            addSol(board,ans,n);
            return;
        }

        //place one queen in a column and let recursion handle the rest
        for(int row=0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1, ans, board,n);
                //backtrack and make queen 0 again
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;

        solve(0,ans,board,n);
        return ans;
        
    }
};
