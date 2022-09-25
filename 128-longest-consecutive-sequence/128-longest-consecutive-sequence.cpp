class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            // TLE
            unordered_map<int,int> hash;
            for (auto itr: nums)
            {
                hash[itr]++;
            }

            int lenMax = 0;
            for (auto itr: nums)
            {
                // if there's a larger sequence skip the lookup
                if (!(hash.find(itr - 1) != hash.end()))
                {
                    int i = itr;
                    int count = 0;
                    while (hash.find(i) != hash.end())
                    {
                        count++;
                        i++;
                    }
                    lenMax = max(lenMax, count);
                }
            }

            return lenMax;
        }
};