class Solution
{
    public:
        bool isPalindrome(string str)
        {
            string clStr = "";

            for (char ch: str)
            {
                if (isalpha(ch))
                    clStr.push_back(tolower(ch));
                else if (isdigit(ch))
                    clStr.push_back(ch);
            }
            cout << clStr << endl;
            for (int i = 0, j = clStr.size() - 1; i <= j; i++, j--)
            {
                if (clStr[i] != clStr[j])
                {
                    return false;
                }
            }
            return true;
        }
};