#include<bits/stdc++.h>
using namespace std;
int n,startX,startY,center;
int m[1001][1001];
int g[8][2] = {
{-2,-1},{-1,-2},{-2,1},{-1,2},
{1,-2},{2,-1},{1,2},{2,1}
};
struct node{
int sum = 0;
int pos;
int l;
node(int sum, int pos, int l) : sum(sum), pos(pos), l(l) {}
};
//判断下一步是否可行
bool check(int x,int y)
{
if(x>=1&&x<=n&&y>=1&&y<=n&&m[x][y]==0)return true;
else return false;
}
//能否到达1
bool Cycle(int x,int y)
{
for(int i=0;i<8;i++)
{
if(m[x+g[i][0]][y+g[i][1]]==1)return true;
}
return false;
}
//计算所有可达步
int Sum(int x,int y)
{
int tmp = 0;
for(int i=0;i<8;i++)
{
if(check(x+g[i][0],y+g[i][1]))tmp++;
}
return tmp;
}
//距离中心距离
int getL(int x,int y)
{
return abs(x-startX)+abs(y-startY);
}
void Print()
{
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
cout<<m[i][j]<<" ";
cout<<endl;
}
}
void dfs(int x,int y,int step)
{
if(step == n*n)
{
if(Cycle(x,y))
{
Print();
exit(0);
}
return ;
}
else
{
vector<node>tmpV;
for(int i=0;i<8;i++)
{
if(check(x+g[i][0],y+g[i][1]))
{
int sum = Sum(x+g[i][0],y+g[i][1]);
int l = getL(x+g[i][0],y+g[i][1]);
tmpV.push_back(node(sum,i,l));
}
}
//排序
sort(tmpV.begin(),tmpV.end(),[](const node& A,const node& B)->bool{
if(A.sum<B.sum)return true;
else if(A.sum==B.sum&&A.l>=B.l)return true;
else return false;
});
for(int i=0;i<tmpV.size();i++)
{
int pos = tmpV[i].pos;
m[x+g[pos][0]][y+g[pos][1]]=step+1;
dfs(x+g[pos][0],y+g[pos][1],step+1);
m[x+g[pos][0]][y+g[pos][1]]=0;
}
}
}
int main()
{
cin>>n>>startX>>startY;
m[startX][startY]=1;
dfs(startX,startY,1);
}
