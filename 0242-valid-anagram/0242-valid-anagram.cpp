class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        for(auto chr : s) {
            hash[chr]++;
        }
        
        for(auto chr : t) {
            if(hash.find(chr) == hash.end()) 
                return false;
            else {
                hash[chr]--;
            }
        }
        
        for(auto itr : hash) {
            if (itr.second != 0) 
                return false;
        }        
        
        return true;
    }
};