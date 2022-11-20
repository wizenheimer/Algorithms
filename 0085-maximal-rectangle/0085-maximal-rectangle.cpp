class Solution
{
    private:

        int SIZE;

    vector<int> makeNSL(vector<int> &arr)
    {
        vector<int> result(SIZE, -1);
        stack<pair<int, int>> Stack;
        for (int i = 0; i < SIZE; i++)
        {
           	// remove all the larger and equal elements
            while (!Stack.empty() && Stack.top().first >= arr[i])
                Stack.pop();
            if (!Stack.empty())
                result[i] = Stack.top().second;
            Stack.push({ arr[i],
                i });
        }
        return result;
    }

    vector<int> makeNSR(vector<int> &arr)
    {
        vector<int> result(SIZE, SIZE);
        stack<pair<int, int>> Stack;
        for (int i = SIZE - 1; i >= 0; i--)
        {
           	// remove all the larger and equal elements
            while (!Stack.empty() && Stack.top().first >= arr[i])
                Stack.pop();
            if (!Stack.empty())
                result[i] = Stack.top().second;
            Stack.push({ arr[i],
                i });
        }
        return result;
    }

    int MAH(vector<int> &arr)
    {
        SIZE = arr.size();
        vector<int> NSL = makeNSL(arr);
        vector<int> NSR = makeNSR(arr);
        int result = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
            result = max(result, arr[i] *(NSR[i] - NSL[i] - 1));
        return result;
    }
    public:
        int maximalRectangle(vector<vector < char>> &matrix)
        {

            vector<int> arr(matrix[0].size(), 0);
            int result = INT_MIN;
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i][j] == '1')
                        arr[j] += 1;
                    else
                        arr[j] = 0;
                }
                result = max(result, MAH(arr));
            }
            return result;
        }
};