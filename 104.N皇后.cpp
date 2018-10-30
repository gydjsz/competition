/*
	题目内容：
 国际象棋中的皇后可以沿着水平线，垂直线，或者斜线前进，吃掉遇到的所有棋子，如果棋盘上有八个皇后，则这八个皇后如何相安无事的
放置在棋盘上，1970年与1971年， E.W.Dijkstra与N.Wirth曾经用这个问题来讲解程式设计之技巧。
该题要求N皇后的放置结果共有多少种
输入描述
输入一个正整数N（N小于16）

输出描述
输出结果

输入样例
8

输出样例
92
*/

#include <iostream>
#include <cmath>
using namespace std;
int search(int j, int a[]){
	int i = 1;
	while(i < j){
		if(a[i] == a[j] || abs(a[i] - a[j]) == abs(i - j))	
			return 0;
		i++;
	}
	return 1;
}

int nqueen(int n, int a[]){
	int j = 1;
	a[1] = 0;
	int sum = 0;
	while(j > 0){
		a[j] = a[j] + 1;
		while(a[j] <= n && !search(j, a))
			a[j] = a[j] + 1;
		if(a[j] <= n){
			if(j == n)
				sum++;
			else{
				j++;
				a[j] = 0;
			}
		}
		else
			j--;
	}
	cout << sum << endl;
}
int main(){
	int n, a[100] = {0};
	cin >> n;
	nqueen(n, a);
	return 0;
}
