class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char target)
    {
        // char target = '0' + val;
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == target) return false;
            if(board[i][col] == target) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == target) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board) 
    {
//      iterate the entire matrix row by row & col by col
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
//              we found an empty cell
                if(board[row][col] == '.')
                {
//                    try out all possible combinations there
                    for(char val = '1'; val <= '9'; val++)
                    {
//                      if it's valid to include value at given row and col and recr
                        if(isValid(board,row,col,val))
                        {
                            board[row][col] = val;
                            
                            if(solve(board) == true)
                                return true;
                            else
                                board[row][col] = '.';
                        }
                    }
//                     if none of it is valid return
                    return false;
                }
            }
        }
//         exhausted all tries return true
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};