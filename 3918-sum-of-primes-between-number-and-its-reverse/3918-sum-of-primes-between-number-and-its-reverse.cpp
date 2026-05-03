class Solution {
public:
    bool p(int n) {
        if (n <= 1)
            return false; 
        if (n <= 3)
            return true; 

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }

    int rn(int n) {
        int rev = 0;
        while (n != 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        return rev;
    }

    int sumOfPrimesInRange(int n) {
        int op = rn(n);
        int s = min(op, n);
        n = max(op, n);
        int t=0;
        for(int i =s;i<=n; i++){
            if(p(i)) t+=i;
        }
        return t;
    }
};