/*
题目内容：
 在一个nxn的棋盘上，某人站在方格(0, 0)，他只能向下或者向右，而且只能在棋盘的上三角中行走，问他走到(n-1, n-1)有多少种走法。
输入描述
棋盘大小n

输出描述
从（0,0）走到（n-1,n-1）的走法数

输入样例
6

输出样例
42
*/
#include <iostream>
using namespace std;
int sumStep(int i, int j, int n, int &sum){
	if(i == n && j == n){
		sum += 1;
	}
	if(j < i){
		sumStep(i, j + 1, n, sum);
	}
	if(i < n){
		sumStep(i + 1, j, n, sum);
	}
	return sum;
}
int main(){
	int n;
	cin >> n;
	int sum = 0;
	cout << sumStep(0, 0, n - 1, sum) << endl;
	return 0;
}

