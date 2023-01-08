#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
bool visited[1001][1001];
bool success = false;
int roate[1001];
 
struct Position{
    Position(int x_, int y_, int num): x(x_), y(y_), canMovePoisitionNum(num) { }
    int x;
    int y;
    int canMovePoisitionNum;
};
 
Position Move[] = {Position(, -), Position(, -), Position(, ), Position(, ),
                    Position(-, ), Position(-, ), Position(-, -), Position(-, -)};
 
bool isValid(int x, int y) {
    return x >=  && y >=  && x <=  && y <= ;
}
 
int getCanMovePositionNum(int x, int y) {
    int canMovePoisitionNum = ;
    for (int i = ; i != ; ++i) {
        if(isValid(x + Move[i].x, y + Move[i].y))
            canMovePoisitionNum++;
    }
    return canMovePoisitionNum;
}
 
bool cmp(const Position &a, const Position &b) {
    return a.canMovePoisitionNum < b.canMovePoisitionNum;
}
 
void search(int step, int x, int y) {
    vector<Position> poisition;
    for (int i = ; i != ; ++i) {
        int xTemp = x + Move[i].x;
        int yTemp = y + Move[i].y;
        if (isValid(xTemp, yTemp)) {
            int canMovePoisitionNum = getCanMovePositionNum(xTemp, yTemp);
            if (canMovePoisitionNum != )
                poisition.push_back(Position(xTemp, yTemp, canMovePoisitionNum));
        }
    }
    sort(poisition.begin(), poisition.end(), cmp);
    for (int i = ; i != poisition.size(); ++i) {
        if (success)
            return;
        if (step == ) {
            success = true;
            return;
        }
        if (!visited[poisition[i].x][poisition[i].y]) {
            ++step;
            roate[step] =  * poisition[i].x + poisition[i].y + ;
            visited[poisition[i].x][poisition[i].y] = true;
            search(step, poisition[i].x, poisition[i].y);
            visited[poisition[i].x][poisition[i].y] = false;
            --step;
        }
    }
}
 
int main(int argc, char *argv[])
{
    int N, x, y;
    while (scanf("%d", &N) && N != -) {
        roate[] = N;
        memset(visited, false, sizeof(visited));
        success = false;
        x = (N - ) / ;
        y = (N - ) % ;
 
        visited[x][y] = true;
        search(, x, y);
 
        for (int i = ; i != ; i++)
            printf("%d ", roate[i]);
        printf("%d\n", roate[]);
    }
 
    return ;
}
