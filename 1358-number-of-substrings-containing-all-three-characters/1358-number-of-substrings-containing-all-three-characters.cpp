class Solution
{
    public:
        int numberOfSubstrings(string str)
        {
            int result = 0;
            int a = 0, b = 0, c = 0;
            int n = str.size();
            for (int left = 0, right = 0; right < n; right++)
            {
               	// increment a/b/c
                switch (str[right])
                {
                    case 'a':
                        a++;
                        break;
                    case 'b':
                        b++;
                        break;
                    case 'c':
                        c++;
                        break;
                }

               	// when all have hit non zero values
                if (a *b *c != 0)
                {

                    while (a *b *c != 0)
                    {
                       	// number of substring evaluate
                        result += n - right;
                        switch (str[left])
                        {
                            case 'a':
                                a--;
                                break;
                            case 'b':
                                b--;
                                break;
                            case 'c':
                                c--;
                                break;
                        }
                        left++;
                    }
                }
            }
            return result;
        }
};