/*
题目内容：
欧几里得原理：
用GCD(A,B)表示两个正整数A和B的最大公约数(GCD是最大公约数的英文Greatest Common Divisor的简写)。
不妨认为A>B,那么GCD(A,B) =GCD（A-B,B）。 也就是把其中较大的一个数变为两数之差后，最大公约数不会变。
例如 GCD（36，14）= GCD (36-14， 14）=GCD（22，14）
现要求利用欧几里得原理，设计一个程序，求两个整数的最大公约数。
输入描述
输入两个整数A,B,  中间用空格间隔。

输出描述
输出A和B的最大公约数

输入样例
14 8

输出样例
2
*/

#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
