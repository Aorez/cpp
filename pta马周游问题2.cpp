#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
 
const int WIDTH = 8, HEIGHT = 8;
 
class Point {
public:
    int x;
    int y;
    int outDegree;
 
};
 
int move_x[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int move_y[] = { -2, 2, 1, -1, 2, -2, 1, -1 };
 
bool visited[WIDTH + 2][HEIGHT + 2];
bool solved;
int route[WIDTH * HEIGHT];
void calculateXY(const int position, int &x, int &y);
bool dfs(Point p, int count);
bool comp(const Point &p1, const Point &p2);
bool isvalid(const Point &p);
 
int main() {
    int startPosition;
    Point p;
    while (cin >> startPosition && startPosition != -1) {
        solved = false;
        memset(visited, false, sizeof(visited));
        calculateXY(startPosition, p.x, p.y);
        route[0] = startPosition;
        visited[p.x][p.y] = true;
        dfs(p, 1);
    }
    return 0;
}
 
void calculateXY(const int position, int &x, int &y) {
    x = (position - 1) / 8 + 1;
    y = position - ((x - 1) * 8);
}
bool dfs(Point p, int count){
    //Pre: Given a Point and the count of Points that have been found.
    //Post:If there is a route, print it and return true, else return false.
 
    if(count == WIDTH * HEIGHT){//print route
        cout << route[0];
        for (int i = 1; i < WIDTH * HEIGHT; ++i) {
            cout << " " << route[i];
        }
        cout << endl;
        return true;
    }
    else{//从当前点可以访问到的点找到出度最小那个继续搜索
        Point temp;
        vector<Point>nexts;
        for (int i = 0; i < 8; ++i) {
            temp.x = p.x + move_x[i];
            temp.y = p.y + move_y[i];
            temp.outDegree = 0;
            if(isvalid(temp)){
                Point tempNext;
                for (int j = 0; j < 8; ++j) {
                    tempNext.x = temp.x + move_x[j];
                    tempNext.y = temp.y + move_y[j];
                    if(isvalid(tempNext))
                        temp.outDegree++;
                }
                nexts.push_back(temp);
            }
        }
        sort(nexts.begin(), nexts.end(), comp);//按照出度的大小排序，出度小的优先访问
        for (unsigned int i = 0; i < nexts.size(); ++i) {
            visited[nexts[i].x][nexts[i].y] = true;
            route[count] = (nexts[i].x - 1) * WIDTH + nexts[i].y;
            if(dfs(nexts[i], count + 1))
                return true;
            visited[nexts[i].x][nexts[i].y] = false;
        }
    return false;
    }
}
bool comp(const Point &p1, const Point &p2){
    return p1.outDegree < p2.outDegree;
}
 
bool isvalid(const Point &p){
    //判断一个点是否可以访问
    return (p.x >= 1 && p.x <= 8 && p.y >= 1 && p.y <= 8 && !visited[p.x][p.y]);
}
