class Solution
{
    public:
        vector<vector < int>> findWinners(vector<vector < int>> &matches)
        {
            map<int, int> wins, loss;
            for (auto match: matches)
            {
                int winner = match[0];
                int looser = match[1];

                wins[winner]++;
                loss[looser]++;
            }
            vector<vector < int>> result(2);
            
           	// iterate through the winners
            for (auto itr: wins)
            {
               	// find the ones who haven't lost any match
                if (loss.find(itr.first) == loss.end())
                {
                    result[0].push_back(itr.first);
                }
            }
            
           	// iterate through the loosers
            for (auto itr: loss)
            {
                if(itr.second == 1)
                result[1].push_back(itr.first);
            }
            
            return result;
        }
};