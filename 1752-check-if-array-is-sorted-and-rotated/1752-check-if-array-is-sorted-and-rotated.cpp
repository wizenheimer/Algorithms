class Solution {
public:
    bool check(vector<int>& arr) 
    {
        int breakpoint = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > arr[(i + 1) % arr.size()])
                breakpoint++;
            
            if(breakpoint > 1)
                return false;
        }
        if(breakpoint <= 1)
            return true;
        else
            return false;
    }
};