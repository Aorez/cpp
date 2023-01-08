#include<bits/stdc++.h>

const int MAX = 21;
int k;//k种颜色 
int n;//顶点数
int m;//边数
int matrix[MAX][MAX];//邻接矩阵
int sum = 0;//方法总计
int color[MAX];//颜色
 
int detection(int pos,int i){
	for (int j = 1; j <= n; j++) {
		if (matrix[pos][j]==1 && color[j] == i)return 0;//是邻边且用的同一种颜色
	}return 1;
}
 
//矩阵初始化
void Initialize() {
// 	printf("有几个顶点？:");
	scanf("%d",&n);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			matrix[i][j] = 0;
//		}
//	}
// 	printf("有几条边？:");
	scanf("%d",&m);
	scanf("%d", &k);
	int v1, v2;
	for (int i = 1; i <= m; i++) {
// 		printf("依次输入相邻的两个点:");
		scanf("%d %d",&v1,&v2);
		matrix[v1][v2] = 1;
		matrix[v2][v1] = matrix[v1][v2];
	}
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= n; j++) {
// 			printf("%d ", matrix[i][j]);
// 		}printf("\n");
// 	}
}
 
//红=1 绿=2 黄=3
//着色问题
void colorProblem(int pos) {
	if (pos == n + 1) {//证明最后一个顶点已经着色了
		sum++;//方法总计
// 		printf("解法%d:",sum);
// 		for (int i = 1; i <= n; i++) {
// 			printf("%d",color[i]);
// 		}printf("\n");
		return;
	}
	for (int i = 1; i <= k; i++) {//三种颜色
		if (detection(pos, i)) {
			color[pos] = i;
			colorProblem(pos + 1);
			color[pos] = 0;//回溯
		}
	}
 
 
}
 
int main() {
	Initialize();
	colorProblem(1);
// 	printf("%d着色问题有%d种解法",m,sum);
    printf("%d", sum);
	return 0;
}
