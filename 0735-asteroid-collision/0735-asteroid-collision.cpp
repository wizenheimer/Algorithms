class Solution
{
    public:
        vector<int> asteroidCollision(vector<int> &asteroids)
        {
            stack<int> Stack;
            for (auto ast: asteroids)
            {
                if (Stack.empty())
                {
                    Stack.push(ast);
                }
                else if (Stack.top() > 0 && ast < 0)
                {
                   	// collision +-
                   	// remove elements lower than ast
                    while (!Stack.empty() && Stack.top() > 0 && Stack.top() < abs(ast))
                        Stack.pop();
                   	// .
                    if (Stack.empty())
                        Stack.push(ast);
                    else if (Stack.top() + ast == 0)
                        Stack.pop();
                    else if (Stack.top() < 0)
                        Stack.push(ast);
                }
                else
                {
                   	// no collision --/++/-+
                    Stack.push(ast);
                }
            }

            vector<int> result;

            while (!Stack.empty())
            {
                result.push_back(Stack.top());
                Stack.pop();
            }
            reverse(result.begin(), result.end());

            return result;
        }
};