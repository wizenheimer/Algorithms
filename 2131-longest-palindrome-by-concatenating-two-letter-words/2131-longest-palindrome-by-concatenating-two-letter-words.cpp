class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            vector<vector<int>> arr(26,vector<int>(26,0));
            int result = 0;
            for(auto word : words) {
                // convert to int
                int a = word[0] - 'a';
                int b = word[1] - 'a';
                
                if(arr[b][a] != 0) {
                    // add to result
                    result += 4;
                    // incase we find a mirror
                    arr[b][a] -= 1;
                } else {
                    // incase we don't find a mirror
                    arr[a][b] += 1;
                }
            }
            
            for(int i = 0; i < 26; i++) {
                // iterate and check
                if(arr[i][i] != 0) {
                    result += 2;
                    break;
                }
            }
            
            return result;
        }
};