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

	
//	b1 = b2;//�G���[
//	std::cout << "b1 = b2 : " << b1.x_ << std::endl;
//
//	b1 = d;//�G���[
//	std::cout << "b1 = d : " << b1.x_ << std::endl;

	d = b2;//delete����Ă���̂͂����܂�base�N���X�ɂ��ĂȂ̂ł��炽��derived�Œ�`���Ă����Ȃ�
	std::cout << "d = b2 : " << d.x_ << std::endl;

}