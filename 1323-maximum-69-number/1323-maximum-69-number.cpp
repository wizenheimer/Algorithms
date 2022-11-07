class Solution
{
    public:
        int maximum69Number(int num)
        {
            string n = to_string(num), str = "";
            bool flag = true;
            for (char ch: n)
            {
                if (ch == '6' && flag)
                {
                    str += '9';
                    flag = false;
                }
                else
                    str += ch;
            }
            return stoi(str);
        }
};