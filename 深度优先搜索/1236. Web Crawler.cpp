/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * function HtmlParser() {
 *
 *		@param {string} url
 *     	@return {string[]}
 *     	this.getUrls = function(url) {
 *      	...
 *     	};
 * };
 */

/**
 * @param {string} startUrl
 * @param {HtmlParser} htmlParser
 * @return {string[]}
*/
var crawl = function(startUrl, htmlParser) {
    const ans = new Set();
    ans.add(startUrl);
    const hostname = new URL(startUrl).hostname;
    
    const dfs = (url, parser) => {
        const urls = parser.getUrls(url).filter(item => new URL(item).hostname === hostname);
        
        urls.forEach(item => {
            if (!ans.has(item)) {
                ans.add(item);
                dfs(item, parser);
            }
        });
    };
    
    dfs(startUrl, htmlParser);
    return [...ans];
};
