class Solution {
public:
    void solve(int col, int n, vector<string> board, vector<vector<string>> &result,
              vector<bool> hashLeft, vector<bool> hashUp, vector<bool> hashDown) {
//         base case
        if(col >= n)
        {
            result.push_back(board);
            return;
        }
//         place the queens if it's safe
        for(int row=0; row<n; row++)
        {
            if(hashLeft[row] && hashUp[col-row+n-1] && hashDown[row+col])
            {
                board[row][col] = 'Q';
//                 mark as unsafe
                hashLeft[row] = hashUp[col-row+n-1] = hashDown[row+col] = false;
                solve(col+1, n, board, result,hashLeft,hashUp,hashDown);
                board[row][col] = '.';
//                 mark as safe
                hashLeft[row] = hashUp[col-row+n-1] = hashDown[row+col] = true;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
//      respective hash
        vector<bool> hashLeft(n,true);
        vector<bool> hashUp(2*n-1,true);
        vector<bool> hashDown(2*n-1,true);
//      solve function
        solve(0,n,board,result,hashLeft,hashUp,hashDown);
        return result;
    }
};