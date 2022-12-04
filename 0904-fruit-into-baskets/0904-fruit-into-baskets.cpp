class Solution
{
    public:
        int totalFruit(vector<int> &fruits)
        {
            int n = fruits.size();
            int result = 0;
            map<int, int> hash;
            for (int left = 0, right = 0; right < n; right++)
            {
                int fruit = fruits[right];
                hash[fruit]++;
                
                if(hash.size() <= 2)
                {
                    int count = 0;
                    for(auto it: hash) {
                        count += it.second;
                    }
                    result = max(count, result);
                }
                
                while (hash.size() > 2)
                {
                    fruit = fruits[left];
                    hash[fruit]--;
                    if (hash[fruit] == 0)
                        hash.erase(fruit);
                    left++;
                }
            }
            return result;
        }
};