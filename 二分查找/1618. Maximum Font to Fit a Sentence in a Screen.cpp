/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        const int len = text.size();
        int l = 0, r = fonts.size() - 1;
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            long long _h = fontInfo.getHeight(fonts[mid]);
            long long _w = 0;
            for (const char ch : text) _w += fontInfo.getWidth(fonts[mid], ch);
            
            if (_h <= h && _w <= w) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (r == -1) return -1;
        else return fonts[r];
    }
};
