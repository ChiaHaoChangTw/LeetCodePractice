class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = 0;
        int pos2 = 0;
        while (pos1 < version1.size() || pos2 < version2.size()) {
            string ver1Str = getNextSubVersion(version1, pos1);
            string ver2Str = getNextSubVersion(version2, pos2);
            int ver1 = ver1Str.size() ? stoi(ver1Str) : 0;
            int ver2 = ver2Str.size() ? stoi(ver2Str) : 0;

            if (ver1 > ver2) {
                return 1;
            } else if (ver2 > ver1) {
                return -1;
            }

            pos1 += ver1Str.size() + 1;
            pos2 += ver2Str.size() + 1;
        }
        return 0;
    }

private:
    string delimiter = ".";
    string getNextSubVersion(string& version, int pos) {
        if (pos >= version.size()) {
            return "";
        }
        return version.substr(pos, version.find(delimiter, pos) - pos);
    }
};

// string
// time O(max(m, n))
// space O(max(m, n))

