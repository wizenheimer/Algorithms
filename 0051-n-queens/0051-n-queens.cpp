class Solution
{
    private:
        bool check(int row, int col, int n, vector<string> board)
        {
           	// check upper element
            int duprow = row;
            int dupcol = col;

            while (row >= 0 && col >= 0)
            {
                if (board[row][col] == 'Q')
                    return false;
                row--;
                col--;
            }

            col = dupcol;
            row = duprow;
            while (col >= 0)
            {
                if (board[row][col] == 'Q')
                    return false;
                col--;
            }

            row = duprow;
            col = dupcol;
            while (row < n && col >= 0)
            {
                if (board[row][col] == 'Q')
                    return false;
                row++;
                col--;
            }
            return true;
        }

    void solve(int col, int n, vector<string> board, vector<vector< string>> &result)
    {
        if (col == n)
        {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (check(row, col, n, board))
            {
                board[row][col] = 'Q';
                solve(col + 1, n, board, result);
                board[row][col] = '.';
            }
        }
    }
    public:
        vector<vector < string>> solveNQueens(int n)
        {
            vector<vector < string>> result;
            vector<string> board(n, string(n, '.'));
            solve(0, n, board, result);
            return result;
        }
};