class Solution
{
    public:
        string longestPalindrome(string str)
        {
            string result = "";
            int n = str.size();
            if (n == 1)
            {
                return str.substr(0);
            }
            int resLen = 0;
           	// check odd length string
            for (int i = 0; i <= n; i++)
            {
                int left = i, right = i;
                while (left >= 0 && right < n)
                {
                   	// check if it's palindrome
                    if (str[left] == str[right])
                    {
                       	// check if it's greater than previous resultant length
                        if (resLen < right - left + 1)
                        {
                            resLen = right - left + 1;
                            result = str.substr(left, resLen);
                        }
                    }
                   	// it's not a palindrome
                    else
                    {
                        break;
                    }
                   	// move the pointers
                    left -= 1;
                    right += 1;
                }
            }
           	// check even length strings
            for (int i = 0; i <= n; i++)
            {
                int left = i, right = i + 1;
                while (left >= 0 && right < n)
                {
                   	// check if it's palindrome
                    if (str[left] == str[right])
                    {
                       	// check if it's greater than previous resultant length
                        if (resLen < right - left + 1)
                        {
                            resLen = right - left + 1;
                            result = str.substr(left, resLen);
                        }
                    }
                   	// it's not a palindrome
                    else
                    {
                        break;
                    }
                   	// move the pointers
                    left -= 1;
                    right += 1;
                }
            }
            return result;
        }
};