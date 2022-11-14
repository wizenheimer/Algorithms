class Solution {
public:
    void rev(int i, vector<char>& str) {
        int n = str.size();
        if(i >= n/2) return;
        swap(str[i], str[n - 1 - i]);
        rev(i+1, str);        
    }
    void reverseString(vector<char>& str) {
        rev(0, str);
    }
};