class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int result = 0;
        for(char ch : s) {
            if(ch == '(') {
                stk.push(ch);
                result = result > stk.size() ? result : stk.size();
            } else if(ch == ')') {
                stk.pop();
            }
        }
        return result;
    }
};