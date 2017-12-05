#include"longer_int.h"
#include<iostream>

int main(void) {
	const int ary_num = 7;
	longer_int hoge[ary_num];

	hoge[0] = 1;//int‚Ì‘ã“ü

	hoge[1] = "2";//std::string‚Ì‘ã“ü

	hoge[2] = hoge[0] + hoge[1];//longer_int + longer_int

	hoge[3] = hoge[0] + 3;//longer_int + int

	hoge[4] = 3 + hoge[0];//int + longer_int

	for (int i = 0; i < ary_num; i++) {
		std::cout << hoge[i].str() << std::endl;
	}
}