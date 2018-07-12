#include<iostream>
#include"myFunc.h"

void func(int **p) {
	int huga = 10;//discarded at end of function
	*p = &huga;
}

int main(void) {
	int	*p;//address
	int hoge = 2;//value
	p = &hoge;

	cout_instant(p);
	cout_instant(*p);
	
	{//scope test
		int bar = 4;
		p = &bar;
	}
	
	cout_instant(p);//not discarded?
	cout_instant(*p);//not discarded?

	func(&p);
	cout_instant(p);//discarded
	cout_instant(*p);//discarded

}