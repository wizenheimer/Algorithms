class Solution
{
    public:
        bool isValid(string str)
        {
            stack<char> st;
            for (auto ch: str)
            {
                if (ch == '(')
                    st.push(')');
                else if (ch == '{')
                    st.push('}');
                else if (ch == '[')
                    st.push(']');
                else
                {
                    if(st.empty())
                        return false;
                    char topchar = st.top();
                    if(topchar == ch)
                        st.pop();
                    else
                        return false;
                }
            }
            return st.empty();
        }
};