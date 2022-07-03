class Solution {
public:
    void reverse(string &str, int left, int right)
    {
        while(left <= right)
            swap(str[left++], str[right--]);
    }
    string reverseWords(string str) 
    {
        int left = 0;
        int right = -2;
        str += ' ';
        for(int i = left + 1; i < str.size(); i++)
        {
            if(str[i] == ' ')
            {
                left = right+2;
                right = i-1;
                
                reverse(str, left, right);
            }
        }
        str.pop_back();
        return str;
    }
};