/*
  Id:[637]	
  二分-跳过去 (10分)
  题目内容:
  “跳过去”比赛将在一条河中进行，河中分布着一些大石头。组委会选择了两块石头作为比赛起点和终点。在起点和终点之间，
  有 N 块石头（不含起点和终 点的岩石）。比赛时选手们将从起点出发，每一步跳向下一块石头，直到终点。
  为了提高比赛难度，组委会计划移走一些石头，使得选手们在比赛过程中的最短跳跃距离尽可能长。由于预算限制，组委会至多
  从起点和终点之间移走 M 块石头（不能移走起点和终点的石头）。
  输入描述:
  输入第一行包含3个整数 L,N，M，表示起点和终点的距离，之间的岩石数，以及组委会至多移走的岩石数。
  接下来 N 行，每行一个整数，第 i 行的整数0<d​[i]<L, 表示中间依次的每块石头与起点的距离，保证
  d[i]<d[i+1]

  其中L<=10^9, M<N-2<=10^5
  输出描述:
  最短跳跃距离的最大值
  输入样例:
  25 5 2
  2
  11
  14
  17
  21
  输出样例:
  4
*/

#include <iostream> 

#include <cstdio>
using namespace std;
int a[100010];
int main(){
	int length, number, move;
	cin >> length >> number >> move;
	for(int i = 1; i <= number; i++)
		cin >> a[i];
	a[number + 1] = length;
	int first, last = 0;
	int left = 0, right = length;
	int isMove = 0;
	while(left <= right){
		int mid = (left + right) / 2;
		isMove = 0;
		last = 0;
		for(first = 1; first <= number + 1; first++){
			if(a[first] - last >= mid){
				last = a[first];	
			}
			else{
				isMove++;   //2 11 14 17 21
			}
		}
		if(isMove == move){
			left = mid + 1;
		}
		else if(isMove > move){
			right = mid - 1;	
		}
		else{
			left = mid + 1;
		}
	}
	cout << right << endl;
	return 0;
}
