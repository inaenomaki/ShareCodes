#include"longer_int.h"
#include<iostream>

int main(void) {
	const int ary_num = 5;
	longer_int hoge[ary_num];

	hoge[0] = "10";

	hoge[1] = "2.5f";

	hoge[2] = 5.9;

	int huga = 4;

	hoge[3] = 4;

	hoge[4] = hoge[2] / hoge[3];


	for (int i = 0; i < ary_num; i++) {
		int foo = hoge[i];
		std::cout << foo << std::endl;
	}
}