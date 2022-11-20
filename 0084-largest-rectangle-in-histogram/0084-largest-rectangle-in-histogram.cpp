class Solution {
private:
    vector<int> createNSL(vector<int> &heights) {
        stack<pair<int, int>> Stack;
        vector<int> result(heights.size(), 0);
        
        for(int i = 0; i < heights.size(); i++) {
            while(!Stack.empty() && Stack.top().first >= heights[i])
                Stack.pop();
            if(!Stack.empty())
                result[i] = Stack.top().second;
            else
                result[i] = -1;
            Stack.push({heights[i], i});
        }
        
        return result;
    }
    vector<int> createNSR(vector<int> &heights) {
        stack<pair<int, int>> Stack;
        vector<int> result(heights.size(), 0);
        
        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!Stack.empty() && Stack.top().first >= heights[i])
                Stack.pop();
            if(!Stack.empty())
                result[i] = Stack.top().second;
            else
                result[i] = heights.size();
            Stack.push({heights[i], i});
        }
        
        return result;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSR = createNSR(heights);
        vector<int> NSL = createNSL(heights);
        vector<int> width;
        
        for(int i = 0; i < heights.size(); i++)
        {
            width.push_back(NSR[i] - NSL[i] - 1);
        }
        
        int maxV = INT_MIN;
        for(int i = 0; i < heights.size(); i++)
        {
            maxV = max(maxV, width[i]*heights[i]);
        }
        
        return maxV;        
    }
};