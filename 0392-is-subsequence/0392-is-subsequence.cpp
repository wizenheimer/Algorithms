class Solution
{
    private:
        int LCS(string str, string target, int i, int j)
        {
            if (i == 0 || j == 0)
                return 0;
            if (str[i - 1] == target[j - 1])
                return 1 + LCS(str, target, i - 1, j - 1);
            else
                return LCS(str, target, i, j - 1);
        }
    public:
        bool isSubsequence(string str, string target) 
        {
            return LCS(str, target, str.size(), target.size()) == str.size();
        }
};