class Solution {
public:
    string getPermutation(int n, int k) 
    {
//      build factorial and number vector
        int factorial = 1;
        vector<int> number;
        for(int i = 1; i < n ; i++)
        {
            number.push_back(i);
            factorial *= i;
        }
        number.push_back(n);
//      
        string ans;
        k = k - 1;
        do
        {
            ans += to_string(number[k/factorial]);
            number.erase(number.begin() + k/factorial);
            k %= factorial;
            if(number.size() == 0) break;
            factorial /= number.size();
        } while(true);
        return ans;
    }
};