class Solution {
public:
    int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (divisor == 1) return dividend;

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    long long d = llabs((long long)dividend);  // safe abs
    long long v = llabs((long long)divisor);  // safe abs
    long long res = d / v;  // still using / (your logic)

    return sign * res;
}

};