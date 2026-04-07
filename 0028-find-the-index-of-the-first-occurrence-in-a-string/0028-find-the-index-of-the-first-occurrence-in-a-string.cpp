class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t foundPos1 = haystack.find(needle);  
        if (foundPos1 != std::string::npos){
            return foundPos1 ;
        } else return -1;
    }
};