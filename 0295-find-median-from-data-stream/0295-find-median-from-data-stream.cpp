class MedianFinder {
    priority_queue<int>q;
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q.empty() || num<=q.top())
            q.push(num);
        else 
            pq.push(num);

        if(q.size() > pq.size() + 1) 
        {
            pq.push(q.top());
            q.pop();
        }
        else if(pq.size() > q.size() + 1) 
        {
            q.push(pq.top());
            pq.pop();
        }
    }
    
    double findMedian() {
        if(q.size()>pq.size())
            return q.top();
        else if(q.size()<pq.size())
            return pq.top();
        return (double)(q.top()+pq.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */