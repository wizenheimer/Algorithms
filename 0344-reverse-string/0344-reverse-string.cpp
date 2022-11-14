class Solution {
public:
    void rev(int i, int j, vector<char>& str) {
        if(i > j) return;
        swap(str[i], str[j]);
        rev(i+1, j-1, str);        
    }
    void reverseString(vector<char>& str) {
        rev(0, str.size()-1, str);
    }
};