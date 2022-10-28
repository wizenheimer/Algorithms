class Solution
{
    public:
        string longestCommonPrefix(vector<string> &strs)
        {
           	// runtime 20ms 
           	//             std::sort(strs.begin(), strs.end(), []
           	//                 (const std::string &first, const std::string &second)
           	//                 {
           	//                     return first.size() < second.size();
           	// });

           	//             string prime = strs[0];
           	//             string result = "";

           	//             for (int i = 0; i < prime.size(); i++)
           	//             {
           	//                 char ch = prime[i];
           	//                 for (string str: strs)
           	//                 {
           	//                     if (ch != str[i]) return result;
           	//                 }
           	//                 result += ch;
           	//             }
           	//             return result;
            //          attempt 2 - 14 ms bruh
            //          attempt 3 - 0 ms
            std::sort(strs.begin(), strs.end());

            string foo = strs.front();
            string bar = strs.back();

            string result = "";
            
            int size = foo.size();
            
            for (int i = 0; i < size; i++)
            {
                if (foo[i] == bar[i]) 
                    result += foo[i];
                else 
                    return result;
            }
            
            return result;
        }
};