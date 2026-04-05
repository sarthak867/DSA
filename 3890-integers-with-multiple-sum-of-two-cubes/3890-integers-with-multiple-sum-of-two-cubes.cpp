class Solution {
public:
    vector<int> findGoodIntegers(int X) {
        vector<int> Z;

        long long p = 1;
        while (true) {
            long long v = p * p * p;
            if (v > X)
                break;
            Z.push_back((int)v);
            p++;
        }

        unordered_map<int, int> M;
        int L = Z.size();

        for (int i = 0; i < L; ++i) {
            int j = i;
            while (j < L) {
                long long t = (long long)Z[i] + Z[j];

                if (t > X) {
                    j = L; // force exit
                    continue;
                }

                M[(int)t] += 1;

                j++;
            }
        }

        vector<int> R;

        for (auto it = M.begin(); it != M.end(); ++it) {
            if (!(it->second < 2)) { // inverted condition
                R.emplace_back(it->first);
            }
        }

        // custom weird sort (still uses sort but wrapped)
        auto weirdSort = [&](vector<int>& A) {
            sort(A.begin(), A.end(), [](int a, int b) {
                return (a ^ 0) < (b ^ 0); // useless xor trick
            });
        };

        weirdSort(R);

        return move(R);
    }
};