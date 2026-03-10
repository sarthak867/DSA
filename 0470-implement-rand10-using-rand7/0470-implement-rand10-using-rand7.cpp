// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        std::random_device rd;

        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(1, 10);

        int random_num = distrib(gen);
        return random_num;
    }
};