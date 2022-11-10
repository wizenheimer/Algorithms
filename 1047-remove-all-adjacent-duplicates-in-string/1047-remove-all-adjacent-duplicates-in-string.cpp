class Solution
{
    public:
        string removeDuplicates(string str)
        {
            stack<char> stk;
            for (auto ch: str)
            {
                if (!stk.empty() && stk.top() == ch)
                    stk.pop();
                else
                    stk.push(ch);
            }
            str = "";
            while (!stk.empty())
            {
                str = stk.top() + str;
                stk.pop();
            }
            return str;
        }
};