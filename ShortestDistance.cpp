class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int distance = 0;
        int firstCharIndex = -1;
        int lastCharIndex = -1;
        vector<int> result;
        for (int i = 0; i < s.length(); i++) {
            distance ++;
            if (s[i] == c) {
                if (firstCharIndex == -1) {
                    firstCharIndex = i;
                }
                lastCharIndex = i;
                distance = 0;
                result.push_back(0);
            } else {
                result.push_back(distance);
            }           

        }
        distance = 0;
       
        for (int i = lastCharIndex; i >= 0; i--) {
            distance++;
            if (i < firstCharIndex) {
                result[i] = distance;
                continue;
            }
            if (s[i] == c) {
                distance = 0;
                continue;
            } else {
                if (distance < result.at(i)) {
                    result[i] = distance;
                }
            }
        }
        return result;
    }
};