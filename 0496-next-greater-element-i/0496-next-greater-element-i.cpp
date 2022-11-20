class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            stack<int> Stack;
            map<int, int> hash;
            for (int i = nums2.size() - 1; i >= 0; i--)
            {
                int num = nums2[i];
                
                while (!Stack.empty())
                {
                    if (Stack.top() > num)
                    {
                        hash[num] = Stack.top();
                        Stack.push(num);
                        break;
                    }
                    else
                    {
                        Stack.pop();
                    }
                }

                if (Stack.empty())
                {
                    hash[num] = -1;
                    Stack.push(num);
                }
            }
            vector<int> result;
            for (int i = 0; i < nums1.size(); i++)
            {
                result.push_back(hash[nums1[i]]);
            }
            return result;
        }
};