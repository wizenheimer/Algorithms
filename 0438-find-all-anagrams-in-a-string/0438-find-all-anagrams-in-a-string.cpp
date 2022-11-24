class Solution
{
    public:
        vector<int> findAnagrams(string str, string ptn)
        {
            int SIZE = str.size();
            int WINDOW = ptn.size();
            unordered_map<char, int> hash;
            unordered_map<char, int> whash;
            
           	// build out a base hash map
            for (auto ch: ptn)
            {
                hash[ch]++;
            }
            // store indices
            vector<int> result;
            
            // iterate right to end
            for (int left = 0, right = 0; right < SIZE; right++)
            {
                char ch = str[right];
                // build out target hash map
                whash[ch]++;
                
                if (right - left + 1 == WINDOW)
                {
                    bool flag = true;
                    
                    for (auto itr: hash)
                    {
                        if (whash.find(itr.first) == whash.end() || whash[itr.first] != itr.second)
                        {
                            flag = false;
                            break;
                        }
                    }
                    
                    if (flag)
                        result.push_back(left);
                    
                    whash[str[left]]--;
                    left++;
                }
            }
            return result;
        }
};