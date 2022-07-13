class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int min = 0;
        int max = 0;
        int result = 0;
        
        while(max < time)
        {
//             get a window
            for(int i = 0; i < clips.size(); i++)
            {
                int lb = clips[i][0], rb = clips[i][1];
                
                if(lb <= min && rb > max)
                {
                    max = rb;
                }
            }
//             check if we have atleast one clip selected
            if(min == max)
                return -1;
//             increment result
            result++;
            min = max;
        }
        
        return result;
    }
};