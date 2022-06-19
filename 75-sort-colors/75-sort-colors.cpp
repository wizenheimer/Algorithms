class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int MaxRed = 0, MaxBlue = 0, MaxWhite = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            switch(nums[i])
            {
                case 0:
                    MaxRed += 1;
                    break;
                case 1:
                    MaxBlue += 1;
                    break;
                case 2:
                    MaxWhite += 1;
                    break;
            }
        }
        
        MaxBlue += MaxRed;
        MaxWhite += MaxBlue;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(i < MaxRed)
                nums[i] = 0;
            else if(i < MaxBlue)
                nums[i] = 1;
            else if(i < MaxWhite)
                nums[i] = 2;                   
        }
        
        
    }
};