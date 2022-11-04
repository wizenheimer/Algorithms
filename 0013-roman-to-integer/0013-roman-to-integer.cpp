class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            string sub = s.substr(i,2);
            if(sub == "IV"){
                s[i] = 'O';
                s[i+1] = 'O';
                result += 4;
            } else if(sub == "IX") {
                s[i] = 'O';
                s[i+1] = 'O';
                result += 9;
            } else if(sub == "XL") {
                s[i] = 'O';
                s[i+1] = 'O';
                result += 40;
            } else if(sub == "XC") {
                s[i] = 'O';
                s[i+1] = 'O';
                result += 90;
            } else if(sub == "CD") {
                s[i] = 'O';
                s[i+1] = 'O';
                result += 400;
            } else if(sub == "CM") {
                s[i] = 'O';
                s[i+1] = 'O';
                result += 900;
            }
        }
        
        for(char ch : s) {
            switch(ch) {
                case 'I':
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }
        
        return result;
    }
};