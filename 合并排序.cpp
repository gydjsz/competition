/*题目内容：

使用合并排序算法编程，对整数数组排序 
 输入描述

第一行输入元素个数，第二行输入要排序的数组

 输出描述

排好序的数组

 输入样例

7
2 5 4 1 3 7 6

输出样例

1 2 3 4 5 6 7
*/

#include <iostream>
using namespace std;

class Sort{
	private:
		int n;
		int number[100];
	public:
		Sort();
		void mergeSort(int left, int right);
		void setSort(int left, int right);
		void output();
};

Sort :: Sort(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> number[i];	
	}
	setSort(0, n - 1);
}

void Sort :: setSort(int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		setSort(left, mid);
		setSort(mid + 1, right);
		mergeSort(left, right);
	}
}

void Sort :: mergeSort(int left, int right){
	int array[n];
	int mid = (left + right) / 2;
	int i = left, j = mid + 1;
	int k = 0;
	while(i <= mid && j <= right){
		if(number[i] > number[j]){
			array[k++] = number[j++];
		}
		else{
			array[k++] = number[i++];	
		}
	}
	while(i <= mid){
		array[k++] = number[i++];
	}
	while(j <= right){
		array[k++] = number[j++];	
	}
	i = left;
	j = 0;
	while(i <= right){
		number[i++] = array[j++];	
	}
}

void Sort :: output(){
	int i = 0;
	while(i < n){
		cout << number[i++] << " ";
	}
}

int main(){
	Sort sort;
	sort.output();
	return 0;
}

