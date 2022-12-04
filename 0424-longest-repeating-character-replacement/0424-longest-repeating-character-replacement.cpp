class Solution
{
    public:
        int characterReplacement(string str, int k)
        {
            map<char, int> hash;
            int result = 0;
            int maxCount = 0;
            int n = str.size();
            for (int left = 0, right = 0; right < n; right++)
            {
                hash[str[right]]++;
                maxCount = max(maxCount, hash[str[right]]);
                while ((right - left + 1 - maxCount) > k)
                {
                    hash[str[left]]--;
                   	left++;
                }
                result = max(result, right - left + 1);
            }
            return result;
        }
};