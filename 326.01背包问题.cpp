/*
题目内容：
    物品集合U=｛u1,u2…un｝，体积分别为s1,s2…..sn，价值分别为v1,v2….vn；容量C的背包。设计算法实现放入背包的物品价值最大。
输入描述
第一行输入物品数n,第二行输入每个物品体积，第三行输入每个物品的价值，第四行输入背包的容量C

输出描述
输出最大价值数。

输入样例
3
3 4 5
4 5 6
10

输出样例
11*/
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n, c;
    cin >> n;
    int w[n], v[n];
    for(int i = 1; i <= n; i++)
	cin >> w[i];
    for(int i = 1; i <= n; i++)
	cin >> v[i];
    cin >> c;
    int a[n + 1][c + 1];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
	for(int j = 0; j <= c; j++){
	    if(j < w[i])
		a[i][j] = a[i - 1][j];
	    else
		a[i][j] += max(a[i - 1][j], a[i - 1][j - w[i]] + v[i]);
	}
    cout << a[n][c] << endl;
    return 0;
}
