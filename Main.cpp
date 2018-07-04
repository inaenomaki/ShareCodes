#include<iostream>

class base {
public:
	int x_;
	const base& operator=(const base& src) = delete;
};

class derived :public base {
public:
	const base& operator=(const base& src) {
		std::cout << "called derived operator=" << std::endl;
		this->x_ += src.x_;
		return *this;
	}
};


int main(void) {
	base b1, b2;
	derived d;

	b1.x_ = 3;
	b2.x_ = 4;
	d.x_ = 5;

	
//	b1 = b2;//エラー
//	std::cout << "b1 = b2 : " << b1.x_ << std::endl;
//
//	b1 = d;//エラー
//	std::cout << "b1 = d : " << b1.x_ << std::endl;

	d = b2;//deleteされているのはあくまでbaseクラスについてなのであらたにderivedで定義しても問題ない
	std::cout << "d = b2 : " << d.x_ << std::endl;

}