class Solution {
public:
//     int compute(int index, string s, map<int,int> hash) {
//         int len = s.size();
        
// //      base case
//         if(index == len)
//             return 1;
        
// //      do a look up before computing
//         if(hash.find(index) != hash.end()) {
//             return hash[index];
//         }
        
// //      in case string contains leading zero
//         if(s[index] == '0') {
//             hash[index] = 0;
//             return 0;        
//         }
            
// //      recursive calls for taking single digit
//         int result = compute(index+1, s, hash);
        
// //      recursive calls for coupling the digits 
//         if((index < len-1) && (s[index] == '1' || (s[index] == '2' && s[index+1] < '7')))
//             result += compute(index+2, s, hash);

// //      add result into map post-computation        
//         hash[index] = result;        
//         return result;
//     }
    
//    TLE
    int dp_compute(int index, string s) {
        
        int n = s.size();
        
        vector<int> dp(n+1);
        dp[n] = 1;
        
        for(int i=n-1;i>=0;i--) {
            
            if(s[i]=='0') {
                dp[i]=0;
            }
                
            else {
                dp[i] = dp[i+1];
                
                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) 
                    dp[i]+=dp[i+2];
            }
        }
        
        return s.empty()? 0 : dp[0]; 
    }
    
    int numDecodings(string s) {
        // map<int,int> hash;
        // return compute(0, s, hash);
        return dp_compute(0,s);
    }
};