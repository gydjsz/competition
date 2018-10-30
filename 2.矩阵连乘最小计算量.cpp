/*题目内容：
 n个矩阵A1,A2,...,An, ，如果其维度分别为d0xd1, d1xd2, ...dn-1xdn,则可以进行连乘运算A1A2A3..An . 
连乘运算可以采取不同的顺序进行，如(A1A2)A3 和 A1(A2A3),这两种顺序的消耗乘法计算量是不同的,前者是
d0.d1.d2+d0.d2.d3，后者d0.d1.d3+d1.d2.d3.

第1步选择哪两个，第2步又选择哪两个，一直到最后算出结果需要做n-1次决定。其中有一种计算顺序使得
A1A2A3..An总的乘法计算量最小。
输入描述
第一行输入n
第二行输入维度向量d0,d1,...dn

输出描述
输出所需的最少乘法次数。

输入样例
4
2 3 2 4 3

输出样例
48
*/
//https://www.cnblogs.com/crx234/p/5988453.html
#include <iostream>
using namespace std;
const int MAX = 100;
int n;
int m[MAX][MAX], p[MAX];
void matrix(){
	int i, j, k;
	for(i = 0; i < n; i++)
		m[i][i] = 0;
	for(i = 2; i <= n; i++)
		for(j = 0; j < n - i + 1; j++){
			m[j][j + i - 1] = MAX;
			for(k = 0; k < i - 1; k++){
				m[j][j + i - 1] = min(m[j][j + i - 1], m[j][j + k] + m[j + k + 1][j + i - 1] + p[j] * p[j + k + 1] * p[j + i]);
			}
		}
	cout << m[0][n - 1] << endl;
}
int main(){
	cin >> n;
	for(int i = 0; i <= n; i++)
		cin >> p[i];
	matrix();
	return 0;
}

