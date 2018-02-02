#include<iostream>
#include"myFunc.h"

int main(void) {
	int ary[5];
	int hoge = 5;
	int* hoge_p = &hoge;


	//以下簡易表示用マクロ
	cout_instant(ary);//array's name is read as pointer to the head of the array. But,ary is pointer to array that has 5 elements.
	cout_instant(&ary[0]);//&ary[0] is pointer to ary's initial element.But,ary is pointer to int.

	cout_instant(sizeof(ary));//ary is pointer to array that has 5 elements.
	cout_instant(sizeof(&ary[0]));//ary is pointer to int.

	cout_instant(sizeof(hoge));//hoge is int.
	cout_instant(sizeof(hoge_p));// hoge_p is pointer to int.


}