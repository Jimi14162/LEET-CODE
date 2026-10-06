class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        for(char i : s)
        {
            if(i=='(')
            {
                st.push('(');
            }
            else
            {
                if(st.empty())
                {
                    count++;
                }
                else
                {
                    while(!st.empty() && st.top()!='(')
                    {
                        st.pop();
                    }
                    st.pop();
                }
            }
        }
            return count+st.size();
    }
};