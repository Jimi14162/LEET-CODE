class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>count;
        for(int i=0;i<edges.size();i++)
        {
            for(int j=0;j<2;j++)
            {
                count[edges[i][j]]++;
            }
        }
        for(auto x : count)
        {
            if(x.second==edges.size())
            {
                return x.first;
            }
        }
        return 1;
    }
};