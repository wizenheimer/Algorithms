class Solution
{
    public:
        string removeOuterParentheses(string str)
        {
            stack<char> para;
            string build = "", result = "";
            for (char ch: str)
            {
               	// build string
                build.push_back(ch);

               	// handle the stack
                if (ch == '(')
                    para.push('(');
                else
                    para.pop();

               	// release the build
                if (para.empty())
                {
                    if(build.size() > 2)
                        result += build.substr(1, build.size() - 2);
                    build = "";
                }   
            }
            return result;
        }
};