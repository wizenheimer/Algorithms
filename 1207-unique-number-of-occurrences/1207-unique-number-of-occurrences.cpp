class Solution
{
    private:
        int mod = 1e9;
    public:
        bool uniqueOccurrences(vector<int> &arr)
        {
            sort(arr.begin(), arr.end());
            int n = arr.size();

            if (n > 1)
                arr.push_back((arr[n - 1] + 1) % mod);
            else
                arr.push_back((arr[0] + 1) % mod);
            n += 1;
            map<int, int> hash;

            for (int left = 0, right = 0; right < n; right++)
            {
                if (arr[left] != arr[right])
                {
                    if (hash.find(right - left) != hash.end())
                        return false;
                    hash[right - left] = arr[left];
                    left = right;
                }
            }

            return true;
        }
};