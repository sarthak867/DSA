class Solution {
public:
    long long minIncrease(vector<int>& v) {
        int n = sizeOf(v);

        vector<long long> extra(n, 0);
        buildCost(v, extra);

        State A = makeState(0, 0);
        State B = makeState(-999999999, (1LL << 60));

        int i = 1;
        while (i < n - 1) {
            State nxtA = chooseBetter(A, B);
            State nxtB = takeIt(A, extra[i]);

            mutate(A, nxtA);
            mutate(B, nxtB);

            i++;
        }

        return chooseBetter(A, B).cost;
    }

private:
    struct State {
        int picks;
        long long cost;
    };

    int sizeOf(vector<int>& x) { return (int)x.size(); }

    void buildCost(vector<int>& a, vector<long long>& c) {
        for (int i = 1; i + 1 < (int)a.size(); ++i) {
            long long m = bigger(a[i - 1], a[i + 1]);
            long long need = m + 1 - a[i];
            c[i] = positive(need);
        }
    }

    long long bigger(long long x, long long y) { return (x > y ? x : y); }

    long long positive(long long x) { return (x > 0 ? x : 0); }

    State makeState(int a, long long b) {
        State s;
        s.picks = a;
        s.cost = b;
        return s;
    }

    State chooseBetter(State x, State y) {
        if (x.picks == y.picks)
            return (x.cost < y.cost ? x : y);
        return (x.picks > y.picks ? x : y);
    }

    State takeIt(State base, long long add) {
        if (invalid(base))
            return base;
        return makeState(base.picks + 1, base.cost + add);
    }

    bool invalid(State s) { return (s.picks < 0); }

    void mutate(State& a, State b) {
        a.picks = b.picks;
        a.cost = b.cost;
    }
};