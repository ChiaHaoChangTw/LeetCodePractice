/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int result = 0;
        int read4Return = 4;

        while (n >= 4 && read4Return) {
            read4Return = read4(buf);
            buf += read4Return;
            n -= read4Return;
            result += read4Return;
        }

        if (n > 0 && read4Return) {
            char buf4[4];
            read4Return = read4(buf4);
            for (int i = 0; i < min(read4Return, n); ++i) {
                *(buf + i) = buf4[i];
                ++result;
            }
        }

        return result;
    }
};

// OOP
// internal buffer
// no internal buffer
// time O(n)
// space O(1)

