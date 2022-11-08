class Solution
{
    public:
        string makeGood(string str)
        {
            string result;
            for (char ch: str)
            {
                if (!result.empty() && (result.back() ^ ch) == 32)
                {
                    result.pop_back();
                }
                else
                {
                    result.push_back(ch);
                }
            }
            return result;
        }
};