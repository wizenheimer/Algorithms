class Solution
{
    private:
        bool solve(int i, int j, vector<vector < char>> &board, int index, string word)
        {
            if (index == word.size())
                return true;

            if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[index])
                return false;

            char temp = board[i][j];
            board[i][j] = '?';

            bool left = solve(i, j - 1, board, index + 1, word);
            bool right = solve(i, j + 1, board, index + 1, word);
            bool up = solve(i - 1, j, board, index + 1, word);
            bool down = solve(i + 1, j, board, index + 1, word);

            board[i][j] = temp;

            return left || right || up || down;
        }
    public:
        bool exist(vector<vector < char>> &board, string word) 
        {
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[0].size(); j++)
                {
                    if(solve(i, j, board, 0, word))
                        return true;
                }
            }
            return false;
        }
};