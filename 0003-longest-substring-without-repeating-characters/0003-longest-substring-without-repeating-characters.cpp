class Solution
{
    public:
        int lengthOfLongestSubstring(string str)
        {
            int len = 0, n = str.size();
            map<char, int> hash;
            for (int left = 0, right = 0; right < n; right++)
            {
                char ch = str[right];
                if (hash.find(ch) != hash.end())
                {
                    left = max(left, hash[ch] + 1);
                }
                hash[ch] = right;
                len = max(len, right - left + 1);
            }
            return len;
        }
};