class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto x : m)
        {
            q.push({x.second,x.first});
        }
        vector<int>v;
        for(int i=0;i<k;i++)
        {
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};