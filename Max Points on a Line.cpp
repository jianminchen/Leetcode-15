/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i ++)
        {
            int curAns = 0;
            int sameX = 0;
            int sameXY = 0;
            map< pair<int,int>, int > counts;
            for(int j = 0; j < points.size(); j ++)
            {
                if (i == j) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    sameXY ++;
                    continue;
                }
                if (points[i].x == points[j].x)
                {
                    sameX ++;
                    curAns = max(sameX, curAns);
                    continue;
                }
                int dy = points[i].y - points[j].y;
                int dx = points[i].x - points[j].x;
                int gcd = __gcd(abs(dy), abs(dx));
                pair<int,int> k = make_pair(dy / gcd, dx / gcd);
                counts[k] ++;
                curAns = max(counts[k], curAns);
            }
            ans = max(curAns + sameXY + 1, ans);
        }
        return ans;
    }
};