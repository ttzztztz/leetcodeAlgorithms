/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* flag = new PolyNode();
        PolyNode* cur = flag;
        
        while (poly1 && poly2) {
            if (poly1->power == poly2->power) {
                if (poly1->coefficient + poly2->coefficient != 0) {
                    cur->next = new PolyNode(poly1->coefficient + poly2->coefficient, poly1->power);
                    cur = cur->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->power > poly2->power) {
                cur->next = new PolyNode(poly1->coefficient, poly1->power);
                poly1 = poly1->next;
                cur = cur->next;
            } else { // poly1->power < poly2->power
                cur->next = new PolyNode(poly2->coefficient, poly2->power);
                poly2 = poly2->next;
                cur = cur->next;
            }
        }
        
        if (poly1) {
            cur->next = poly1;
        }
        if (poly2) {
            cur->next = poly2;
        }
        
        PolyNode* ans = flag->next;
        delete flag;
        return ans;
    }
};
