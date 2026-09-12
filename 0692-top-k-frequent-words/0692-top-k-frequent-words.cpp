class Solution {
public:
    struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if(a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;

        for(auto &x : words)
            mp[x]++;

        priority_queue<pair<int,string>,
                       vector<pair<int,string>>, cmp> q;

        for(auto &x : mp)
            q.push({x.second, x.first});

        vector<string> ans;

        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};