class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<k;i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int total=x*x+y*y;
            q.push({total,{x,y}});
            
        }
        for(int i=k;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int x1=q.top().second.first;
            int y1=q.top().second.second;
            if((x*x) + (y*y) <= (x1*x1) + (y1*y1))
            {
                q.pop();
                q.push({x*x+y*y,{x,y}});
            }
        }
        vector<vector<int>>v;
        for(int i=0;i<k;i++)
        {
            int x=q.top().second.first;
            int y=q.top().second.second;
            v.push_back({x,y});
            q.pop();
        }
        return v;
    }
};