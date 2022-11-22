class Solution
{
    public:
        int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSL(n, -1), NSR(n, n);
        stack<pair<int, int>> Stack;

        for (int i = 0; i < n; i++)
        {
            while (!Stack.empty() && arr[i] <= Stack.top().first)
                Stack.pop();
            if (Stack.empty())
                NSL[i] = -1;
            else
                NSL[i] = Stack.top().second;
            Stack.push({ arr[i],
                i });
        }

        while (!Stack.empty())
            Stack.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!Stack.empty() && arr[i] < Stack.top().first)
                Stack.pop();
            if (Stack.empty())
                NSR[i] = n;
            else
                NSR[i] = Stack.top().second;
            Stack.push({ arr[i],
                i });
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            long long left = NSL[i];
            long long right = NSR[i];
            long long temp = ((left - i) % mod) *((i - right) % mod) *(arr[i] % mod);
            result += (temp % mod);
            result = result % mod;
           	// result += ((((NSL[i] - i) % MOD) *((i - NSR[i]) % MOD)) *arr[i]) % MOD;
        }

        return result;
    }
};