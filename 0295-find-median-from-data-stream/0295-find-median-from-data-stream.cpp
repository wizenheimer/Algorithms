class MedianFinder
{
    public:
       	// first -> max heap
       	// second -> min heap
        priority_queue<int> first;
    priority_queue<int, vector < int>, greater < int>> second;

    MedianFinder() {}

    void addNum(int num)
    {
       	// check which half does 'num' belong to
        if (first.empty() || first.top() > num)
        {
            first.push(num);
        }
        else
        {
            second.push(num);
        }

       	// rebalance
        if (first.size() > (second.size() + 1))
        {
            second.push(first.top());
            first.pop();
        }
        else if (first.size() + 1 < second.size())
        {
            first.push(second.top());
            second.pop();
        }
    }

    double findMedian()
    {
        // even
        if (first.size() == second.size()) {
            if (first.empty())
                return 0;
            else 
                return (first.top() + second.top())/2.0;
        } // odd 
        else {
            if (first.size() > second.size())
                return first.top();
            else 
                return second.top();
        }
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */