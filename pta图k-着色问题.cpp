#include<bits/stdc++.h>

const int MAX = 21;
int k;//k����ɫ 
int n;//������
int m;//����
int matrix[MAX][MAX];//�ڽӾ���
int sum = 0;//�����ܼ�
int color[MAX];//��ɫ
 
int detection(int pos,int i){
	for (int j = 1; j <= n; j++) {
		if (matrix[pos][j]==1 && color[j] == i)return 0;//���ڱ����õ�ͬһ����ɫ
	}return 1;
}
 
//�����ʼ��
void Initialize() {
// 	printf("�м������㣿:");
	scanf("%d",&n);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			matrix[i][j] = 0;
//		}
//	}
// 	printf("�м����ߣ�:");
	scanf("%d",&m);
	scanf("%d", &k);
	int v1, v2;
	for (int i = 1; i <= m; i++) {
// 		printf("�����������ڵ�������:");
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
 
//��=1 ��=2 ��=3
//��ɫ����
void colorProblem(int pos) {
	if (pos == n + 1) {//֤�����һ�������Ѿ���ɫ��
		sum++;//�����ܼ�
// 		printf("�ⷨ%d:",sum);
// 		for (int i = 1; i <= n; i++) {
// 			printf("%d",color[i]);
// 		}printf("\n");
		return;
	}
	for (int i = 1; i <= k; i++) {//������ɫ
		if (detection(pos, i)) {
			color[pos] = i;
			colorProblem(pos + 1);
			color[pos] = 0;//����
		}
	}
 
 
}
 
int main() {
	Initialize();
	colorProblem(1);
// 	printf("%d��ɫ������%d�ֽⷨ",m,sum);
    printf("%d", sum);
	return 0;
}
