class Solution {
public:
    string largestOddNumber(string num) {
        // find the odd character and generate the substring from start
        string result = "";
        for(int i = num.size() - 1; i >= 0; i--) {
            if(num[i] % 2 != 0) {
                result = num.substr(0, i+1);
                break;
            }
        }        
        return result;
    }
};