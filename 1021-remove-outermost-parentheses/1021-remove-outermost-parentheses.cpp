class Solution
{
    public:
        string removeOuterParentheses(string str)
        {
           	// using stack ~ 9ms
           	//             stack<char> para;
           	//             string build = "", result = "";
           	//             for (char ch: str)
           	//             {
           	//                	// build string
           	//                 build.push_back(ch);

           	//                	// handle the stack
           	//                 if (ch == '(')
           	//                     para.push('(');
           	//                 else
           	//                     para.pop();

           	//                	// release the build
           	//                 if (para.empty())
           	//                 {
           	//                     if(build.size() > 2)
           	//                         result += build.substr(1, build.size() - 2);
           	//                     build = "";
           	//                 }   
           	//             }

           	// without using stacks ~ 0ms
            int count = 0;
            string result = "";

            for (auto ch: str)
            {
                if (ch == '(')
                {
                    if (count++) result.push_back(ch);
                }
                else
                {
                    if (--count) result.push_back(ch);
                }
            }
            return result;
        }
};