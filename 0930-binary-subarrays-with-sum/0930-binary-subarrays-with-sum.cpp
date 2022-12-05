class Solution
{
    public:
        int numSubarraysWithSum(vector<int> &nums, int goal)
        {
            map<int, int> hash;
            hash[0] = 1;
            int prefix = 0, result = 0;
            
            for (auto num: nums)
            {    
                prefix += num;
                if (hash.find(prefix - goal) != hash.end())
                {
                   	result += hash[prefix - goal];
                }
                hash[prefix]++;
            }
            return result;
        }
};