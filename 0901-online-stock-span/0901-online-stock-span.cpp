class StockSpanner
{
    public:
        stack<pair<int, int>> stk;
    
    StockSpanner() {}

    int next(int price)
    {
        int result = 1;
        while (!stk.empty() && stk.top().first <= price) 
        {
            result += stk.top().second;
            stk.pop();
        }
        
        stk.emplace(price, result);
        return result;
    }
};