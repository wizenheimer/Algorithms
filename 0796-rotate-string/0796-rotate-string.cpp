class Solution {
public:
    bool rotateString(string source, string target) {
        
        if(source.size() != target.size()) 
            return false;
        
        string str = source + source;
        if(str.find(target) != string::npos) 
            return true;
        else 
            return false;
    }
};