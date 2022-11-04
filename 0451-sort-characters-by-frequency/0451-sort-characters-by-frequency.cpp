class Solution
{
    public:
        string frequencySort(string s)
        {
            map<char, int> hash;
            for (auto ch: s)
            {
                hash[ch]++;
            }

            priority_queue<pair<int, char>> pq;
            for (auto itr: hash)
            {
                pq.push(make_pair(itr.second, itr.first));
            }

            string result = "";
            while (!pq.empty())
            {
                pair<int, char> pr = pq.top();
                int count = pr.first;
                char ch = pr.second;
                while (count != 0)
                {
                    result += ch;
                    count -= 1;
                }
                pq.pop();
            }

            return result;
        }
};