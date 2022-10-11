class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int key)
        {
            // sort the array
            sort(nums.begin(), nums.end());
            
            // type covert target into long data type
            long long int target = key;
            
            vector<vector<int>> result;
            
            
            for (int i = 0; i < nums.size(); i++)
            {
                
                target -= nums[i];
                
                for (int j = i + 1; j < nums.size(); j++)
                {
                    
                    target -= nums[j];

                    int low = j + 1, high = nums.size() - 1;
                    
                    while (low < high)
                    {
                        if(target == nums[low] + nums[high])
                        {
                            result.push_back({nums[i], nums[j], nums[low], nums[high]});
                            
                            while (low < high && nums[low] == nums[low + 1] ) low++;
                            while (low < high && nums[high] == nums[high - 1]) high--;
                            
                            low++;
                            high--;
                        }
                        else if (nums[low] + nums[high] < target)
                        {
                            low++;
                        }
                        else
                        {
                            high--;
                        }
                    }
                    
                                      
                    while (j + 1 < nums.size() && nums[j] == nums[j+1]) j++;
                    
                    target += nums[j];
                    
                }
                
                while (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;         
                
                target += nums[i];
            }
            
            return result;
        }
};