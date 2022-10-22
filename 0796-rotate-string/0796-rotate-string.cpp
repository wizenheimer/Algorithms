class Solution {
public:
    bool rotateString(string str, string goal) {
        if(str.size() != goal.size()) return false;
        
        string merged = str + str;
        if(merged.find(goal) == string::npos) 
            return false;
        else 
            return true;
    }
};