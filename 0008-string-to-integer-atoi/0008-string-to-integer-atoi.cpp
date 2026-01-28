class Solution {
public:
    int myAtoi(string s) {
        long long n = 0;
        int neg = 0;
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        if(s[i]=='-'|| s[i]=='+'){
            if (s[i]=='-'){
                neg =1;
            }
            i++;
        }

        for (; i < s.size(); i++) {
            if (isdigit(s[i])) {
                n = n * 10 + (s[i] - '0');

                if (!neg && n > INT_MAX)
                    return INT_MAX;
                if (neg && -n < INT_MIN)
                    return INT_MIN;
            } else
                break;
        }

        return neg ? -n : n;
    }
};