class Solution
{
    public:
        int calculate(string str)
        {
            stack<int> nums;
            int result = 0;
            int num = 0;
            char prevCh = '+';

            for (auto ch: str)
            {
                if (ch == ' ') continue;

                if (isdigit(ch))
                {
                    num = num *10 + (ch - '0');
                }
                else
                {
                    if (prevCh == '+')
                    {
                        nums.push(num);
                    }
                    else if (prevCh == '-')
                    {
                        nums.push(-1 *num);
                    }
                    else if (prevCh == '*')
                    {
                        int prevNum = nums.top();
                        nums.pop();
                        nums.push(prevNum *num);
                    }
                    else if (prevCh == '/')
                    {
                        int prevNum = nums.top();
                        nums.pop();
                        nums.push(int(prevNum / num));
                    }
                    prevCh = ch;
                    num = 0;
                }
            }

            if (prevCh == '+')
            {
                nums.push(num);
            }
            else if (prevCh == '-')
            {
                nums.push(-1 *num);
            }
            else if (prevCh == '*')
            {
                int prevNum = nums.top();
                nums.pop();
                nums.push(prevNum *num);
            }
            else if (prevCh == '/')
            {
                int prevNum = nums.top();
                nums.pop();
                nums.push(int(prevNum / num));
            }

            while (!nums.empty())
            {
                result += nums.top();
                nums.pop();
            }

            return result;
        }
};