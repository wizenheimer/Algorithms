class Solution {
public:
    int maxDepth(string s) {
        // stack<char> stk;
        // int result = 0;
        // for(char ch : s) {
        //     if(ch == '(') {
        //         stk.push(ch);
        //         result = result > stk.size() ? result : stk.size();
        //     } else if(ch == ')') {
        //         stk.pop();
        //     }
        // }
        int result = 0, count = 0;
        for(char ch : s) {
            switch(ch) {
                case '(':
                    result = result > ++count ? result : count;
                    break;
                case ')':
                    count--;
                    break;
            }
        }
        return result;
    }
};