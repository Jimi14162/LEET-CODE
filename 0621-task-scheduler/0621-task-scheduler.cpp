class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(char x : tasks) m[x]++;

        priority_queue<int> pq;
        for(auto x : m) pq.push(x.second);

        queue<pair<int,int>> q; // {remaining, available time}
        int time = 0;

        while(!pq.empty() || !q.empty()) {

            // task becomes available
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()) {
                int x = pq.top();
                pq.pop();
                x--;

                if(x > 0)
                    q.push({x, time + n + 1});
            }

            time++;
        }

        return time;
    }
};