class Solution {
public:
    string decodeString(string s) {
        stack<int>s1;
        stack<string>s2;
        string s3;
        string num;
        //s2.push(s3);
        for(int i=0;i<s.length();i++)
        {
            if(s[i] >= '0' && s[i]<='9')
            {
                num+=s[i];
            }
            else if(s[i]=='[')
            {
                s1.push(stoi(num));
                s2.push(s3);
                s3="";
                num="";
            }
            else if(s[i]==']')
            {
                int x=s1.top();
                s1.pop();
                string temp2="";
                for(int i=0;i<x;i++)
                {
                    temp2+=s3;
                }
                string temp=s2.top();
                s2.pop();
                s3=temp+temp2;
            }
            else
            {
                s3+=s[i];
            }
        }
        /*if(s3.length()>0)
        {
            string temp=s2.top();
            s2.pop();
            s2.push(temp+s3);
        }*/
        return s3;
    }
};