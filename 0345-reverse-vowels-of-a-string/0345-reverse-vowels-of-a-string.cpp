class Solution {
public:
    string reverseVowels(string s) {
        string vlw = "";
        for(char ch : s) {
            switch(ch) {
                case 'a':
                    vlw += "a";
                    break;
                case 'e':
                    vlw += "e";
                    break;
                case 'i':
                    vlw += "i";
                    break;
                case 'o':
                    vlw += "o";
                    break;
                case 'u':
                    vlw += "u";
                    break;
                case 'A':
                    vlw += "A";
                    break;
                case 'E':
                    vlw += "E";
                    break;
                case 'I':
                    vlw += "I";
                    break;
                case 'O':
                    vlw += "O";
                    break;
                case 'U':
                    vlw += "U";
                    break;
            }
        }
        reverse(vlw.begin(), vlw.end());
        string result = ""; 
        int i = 0;
        for(char ch : s) {
            switch(ch) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'A':
                    result += vlw[i++];
                    break;
                default:
                    result += ch;
                    break;
            }
        }
        return result;
    }
};