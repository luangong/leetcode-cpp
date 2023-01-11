// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char tmp[4];
        while (total_bytes_read < n) {
            int bytes_read = read4(tmp);
            if (total_bytes_read + bytes_read < n) {
                copy(tmp, tmp + bytes_read, buf + total_bytes_read);
                total_bytes_read += bytes_read;
                if (bytes_read < 4)
                    return total_bytes_read;
            } else {
                copy(tmp, tmp + n - total_bytes_read, buf + total_bytes_read);
                return n;
            }
        }
    }
};
