class Solution
{
    private:
        void solve(int index, string &digit, string combination,
            vector<string> &result, unordered_map<int, string> &hash)
        {
            if (index >= digit.size())
            {
                result.push_back(combination);
                combination.clear();
                return;
            }

            int dg = digit[index] - '0';
            string st = hash[dg];

            for (int i = 0; i < st.size(); i++)
            {
                combination.push_back(st[i]);
                solve(index + 1, digit, combination, result, hash);
                combination.pop_back();
            }
        }
    public:
        vector<string> letterCombinations(string digits)
        {            
            vector<string> result;
            if(digits.empty()) 
                return result;
            
            unordered_map<int, string> hash = {
		{
                    2, "abc" },
                {
                    3, "def" },
                {
                    4, "ghi" },
                {
                    5, "jkl" },
                {
                    6, "mno" },
                {
                    7, "pqrs" },
                {
                    8, "tuv" },
                {
                    9, "wxyz" }
            };

            string combination;

            solve(0, digits, combination, result, hash);

            return result;
        }
};