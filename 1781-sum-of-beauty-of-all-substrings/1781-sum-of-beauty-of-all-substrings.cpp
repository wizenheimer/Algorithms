class Solution
{
    public:
    int beautySum(string s)
    {
        int n = s.size(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> hash;
            hash[s[i]]++;
            for (int j = i + 1; j < n; j++)
            {
                hash[s[j]]++;
                int maxF = 0, minF = INT_MAX;
                for (auto itr: hash)
                {
                    maxF = max(maxF, itr.second);
                    minF = min(minF, itr.second);
                }
                sum += maxF - minF;
            }
        }
        return sum;
    }
};