class Solution
{
    public:
        bool halvesAreAlike(string str)
        {
            int count = 0;
            int left = 0, right = str.size() - 1;
            while (left <= right)
            {
                char ch = str[left++];
                switch (ch)
                {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        count++;
                }
                ch = str[right--];
                switch (ch)
                {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        count--;
                }
            }
            return count == 0;
        }
};