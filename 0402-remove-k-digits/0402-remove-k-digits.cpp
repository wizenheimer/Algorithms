class Solution
{
    public:
        string removeKdigits(string num, int k)
        {
            stack<int> Stack;
            for (auto ch: num)
            {
                int digit = ch - '0';
                while (!Stack.empty() && Stack.top() > digit && k > 0)
                {
                    k--;
                    Stack.pop();
                }
                Stack.push(digit);
                if(Stack.size() == 1 && digit == 0)
                    Stack.pop();
            }
            // 1234
            while (!Stack.empty() && k > 0)
            {
                Stack.pop();
                k--;
            }
            
            // building resulting string
            string result = "";
            
            while(!Stack.empty())
            {
                result += Stack.top() + '0';
                Stack.pop();
            }
            
            if(result.size() == 0)
                return "0";
            
            reverse(result.begin(), result.end());
            
            return result;
        }
};