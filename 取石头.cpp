/*题目内容：
有一堆石子，A，B两人轮流从中取出石子，每次取出的石子数目只能为1，3，7或8，最后一枚石子谁取到就是输方。
A,B两人都足够聪明，不会做出错误的判断。现给出一定数目的石子，A先取石子，计算A最终是输是赢，赢用1表示，
输用0表示.

 输入描述
  第一行为一个整数n(0< n <=100),表示玩n局，接下来n行每行有一个整数，表示对应的局提供的石子数（不大于
10000），

 输出描述

编程输出A对应的n局是赢是输，赢输出1，输输出0.

输入样例

3
1
3
10

输出样例

0
0
1
*/


/*有一堆石子，A，B两人轮流从中取出石子，每次取出的石子数目只能为1，3，7或8，最后一枚石子谁取到就是输方。
 */

#include <iostream>
using namespace std;
class Stone{
	private:
		int n;
		int number[10000];
	public:
		Stone();
		void isSuccess(int n);
		void output();
};

Stone :: Stone(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> number[i];
}

void Stone :: isSuccess(int n){
	int f[100];
	f[0] = 0;
	f[1] = 1;
	f[2] = 0;
	f[3] = 1;
	f[4] = 0;
	f[5] = 1;
	f[6] = 1;
	f[7] = 1;
	f[8] = 1;

	for(int i = 8; i < n; i++){
		f[i] = !(f[i - 1] && f[i - 3] && f[i - 7] && f[i - 8]);
	}
	cout << f[n - 1] << endl;
}
void Stone :: output(){
	for(int i = 0; i < n; i++){
		isSuccess(number[i]);
	}
}

int main(){
	Stone stone;
	stone.output();
	return 0;
}
