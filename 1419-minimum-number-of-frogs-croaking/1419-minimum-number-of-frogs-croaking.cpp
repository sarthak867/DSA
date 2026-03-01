class Solution {
public:
    int minNumberOfFrogs(string cf) {
        int c = 0, r = 0, o = 0, a = 0, k=0;
        int active = 0, maxFrogs = 0;

        for (char ch : cf) {
            switch (ch) {
                case 'c':
                    c++;
                    active++;
                    maxFrogs = max(maxFrogs, active);
                    break;
                case 'r':
                    r++;
                    if (r > c) return -1;
                    break;
                case 'o':
                    o++;
                    if (o > c || o>r) return -1;
                    break;
                case 'a':
                    a++;
                    if (a > o|| a>c || a>r) return -1;
                    break;
                case 'k':
                    k++;
                    if (k>c || k> r || k>o || k>a ) return -1;
                    active--;
                    break;
                default:
                    return -1;
            }
        }

        if (c == r && r == o && o == a && a==k && active == 0)
            return maxFrogs;
        return -1;
    }
};