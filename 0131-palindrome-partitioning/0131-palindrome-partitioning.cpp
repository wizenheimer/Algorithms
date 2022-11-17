class Solution {
public:
//      check if the string is palindrome
    bool isPalin(string str, int start, int end)
    {
        while (start <= end) 
        {
            if (str[start++] != str[end--])
                 return false;
        }
        return true;
    }
    void solve(int index, string str, vector<string> partitions, vector<vector<string>> &result)
    {
//      exhausted all the options
        if(index >= str.size())
        {
            result.push_back(partitions);
            return;
        }
        
//      iterate throughout the string
        for(int i = index; i < str.size(); i++)
        {
            if(isPalin(str,index,i))
            {
                partitions.push_back(str.substr(index, i-index+1));
                solve(i+1, str, partitions, result);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string str) {
        vector<vector<string>> result;
        vector<string> partitions;
        solve(0,str,partitions,result);
        return result;
    }
};