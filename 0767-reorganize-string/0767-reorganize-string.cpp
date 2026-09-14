class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }
        int x=pq.top().first;
        pq.pop();
        int sum=0;
        while(!pq.empty())
        {
            sum+=pq.top().first;
            pq.pop();
        }
        if(sum < x-1)
        {
            return "";
        }
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }
        string st;
        while(!pq.empty())
        {
            st+=pq.top().second;
            char c=pq.top().second;
            int x=pq.top().first-1;
            pq.pop();
            int y;
            char d;
            if(!pq.empty())
            {
                st+=pq.top().second;
                y=pq.top().first-1;
                d=pq.top().second;
                pq.pop();
            }
            if(x>0)
            {
                pq.push({x,c});
            }
            if(y>0)
            {
                pq.push({y,d});
            }
        }
       return st;
    }
};