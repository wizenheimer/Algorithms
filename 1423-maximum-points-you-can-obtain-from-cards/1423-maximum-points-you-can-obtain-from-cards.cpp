class Solution
{
    public:
        int maxScore(vector<int> &cardPoints, int k)
        {
            int n = cardPoints.size();
            int right = k, left = n, sum = 0;

            vector<int> prefix;
            prefix.push_back(0);
            for (int i = 0; i < n; i++)
            {
                sum += cardPoints[i];
                prefix.push_back(sum);
            }

            vector<int> suffix;
            suffix.push_back(0);
            sum = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                sum += cardPoints[i];
                suffix.push_back(sum);
            }
            reverse(suffix.begin(), suffix.end());

            int result = 0;
            while (right >= 0)
            {
                result = max(result, prefix[right] + suffix[left]);
                right--;
                left--;
            }

            return result;
        }
};