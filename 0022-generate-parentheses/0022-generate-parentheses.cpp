class Solution
{
    private:

        bool isvalid(string str)
        {
            if (str.empty())
                return true;

            int count = 0;

            for (char ch: str)
            {
                if (ch == '(')
                    count += 1;
                else if (ch == ')' && count != 0)
                    count -= 1;
            }

            return count == 0;
        }

        void solve(int index, string str, vector<string> &result)
        {
            if (index >= str.size())
            {
                if (isvalid(str))
                    result.push_back(str);
                str.clear();
                return;
            }

            for (int i = index; i < str.size(); i++)
            {
                if (i != index && str[i] == str[i - 1])
                    continue;

                swap(str[index], str[i]);
                solve(index + 1, str, result);
                swap(str[i], str[index]);
            }
        }

    public:

        vector<string> generateParenthesis(int n)
        {
            string str = "";
            for (int i = 0; i < n; i++)
                str += "(";
            for (int i = 0; i < n; i++)
                str += ")";

            vector<string> result;
            solve(0, str, result);

            return result;
        }
};