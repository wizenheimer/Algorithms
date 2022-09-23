class Solution
{
    public:
        int subarraySum(vector<int> &nums, int k)
        {
            int count = 0, sum = 0;
            map<int, int> hash;
            hash[sum] = 1;
            
            for (auto itr : nums)
            {
                sum += itr;
                
                if (hash.find(sum - k) != hash.end())
                {
                    count += hash[sum - k];
                }
                
                hash[sum]++;
            }
            return count;
        }
};