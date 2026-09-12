class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        k1=k;
        for(int i=0;i<k;i++)
        {
            if(nums.size()<=i)
                break;
            q.push(nums[i]);
        }
        for(int j=k;j<nums.size();j++)
        {
            if(nums[j] >= q.top())
            {
                q.pop();
                q.push(nums[j]);
            }
        }
    }
    
    int add(int val) {
        if(q.size() < k1)
        {
            q.push(val);
        }
        else if(val >= q.top() )
        {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */