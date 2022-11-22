class Solution
{
    public:
        int calculate(string str)
        {
            stack<pair<int, int>> Stack;
            int result = 0, sign = 1;
            for (int i = 0; i < str.size(); i++)
            {
                if (isdigit(str[i]))
                {
                    long long num = 0;
                    while (isdigit(str[i]) && i < str.size())
                    {
                        num = (num *10) + (str[i] - '0');
                        i++;
                    }
                    i--;
                    result += (num *sign);
                    sign = 1;
                }
                else if (str[i] == '(')
                {
                    Stack.push({ result,
                        sign });
                    result = 0;
                    sign = 1;
                }
                else if (str[i] == ')')
                {
                    result = Stack.top().first + (Stack.top().second *result);
                    Stack.pop();
                }
                else if (str[i] == '-')
                {
                    sign = -1;
                }
            }
            return result;
        }
};