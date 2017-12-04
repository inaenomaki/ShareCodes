#include"longer_int.h"
#include<iostream>

int main(void) {
	const int ary_num = 5;
	longer_int hoge[ary_num];

	hoge[0] = "10";

	hoge[1] = "2.5f";

	hoge[2] = 5.9;

	int huga = 4;

	hoge[3] = "2951";

	hoge[4] = hoge[2];


	for (int i = 0; i < ary_num; i++) {
		std::cout << hoge[i].str() << std::endl;
	}
	int foo = hoge[3].digit_from_right(4);
	std::cout << foo << std::endl;
}