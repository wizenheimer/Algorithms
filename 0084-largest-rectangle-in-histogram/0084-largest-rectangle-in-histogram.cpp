class Solution {
private:
    int SIZE;
    vector<int> createNSL(vector<int> &heights) {        
        stack<pair<int, int>> Stack;
        vector<int> result(SIZE, -1);
        
        for(int i = 0; i < SIZE; i++) {
            while(!Stack.empty() && Stack.top().first >= heights[i])
                Stack.pop();
            if(!Stack.empty())
                result[i] = Stack.top().second;
            // else
            //     result[i] = -1;
            Stack.push({heights[i], i});
        }
        
        return result;
    }
    vector<int> createNSR(vector<int> &heights) {
        // int SIZE = heights.size();
        stack<pair<int, int>> Stack;
        vector<int> result(SIZE, SIZE);
        
        for(int i = SIZE - 1; i >= 0; i--) {
            while(!Stack.empty() && Stack.top().first >= heights[i])
                Stack.pop();
            if(!Stack.empty())
                result[i] = Stack.top().second;
            // else
            //     result[i] = SIZE;
            Stack.push({heights[i], i});
        }
        
        return result;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        SIZE = heights.size();
        vector<int> NSR = createNSR(heights);
        vector<int> NSL = createNSL(heights);
        vector<int> width;
        // int SIZE = heights.size();
        
        int maxV = INT_MIN;
        for(int i = 0; i < SIZE; i++)
        {
            maxV = max(maxV, (NSR[i] - NSL[i] - 1)*heights[i]);
        }
        
        return maxV;        
    }
};