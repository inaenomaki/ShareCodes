#include<iostream>

//基本ベースクラス
class Base {
public:
	int n;
	Base() {
		std::cout << "constructor() of base" << std::endl;
	}
	Base(int n) {
		this->n = n;
		std::cout << "constructor(int) of base" << std::endl;
	}

	~Base() {
		std::cout << "destructor() of base" << std::endl;
	}
};

//仮想デストラクタをもったベースクラス
class VBase {
public:
	int n;
	VBase() {
		std::cout << "constructor() of v_base" << std::endl;
	}
	VBase(int n) {
		this->n = n;
		std::cout << "constructor(int) of v_base" << std::endl;
	}

	virtual ~VBase() {
		std::cout << "destructor() of v_base" << std::endl;
	}
};

//基本ベースクラスの派生クラス
class Derived :public Base {
public:
	int flag = 0;
	Derived()
	{
		std::cout << "constructor() of derived" << std::endl;
	}

	~Derived() {
		std::cout << "destructor() of derived" << std::endl;
	}
};

//仮想デストラクタをもったベースクラスの派生クラス
class VDerived :public VBase {
public:
	int flag = 0;
	VDerived()
	{
		std::cout << "constructor() of v_derived" << std::endl;
	}

	~VDerived() {
		std::cout << "destructor() of v_derived" << std::endl;
	}
};

int main(void) {
	std::cout << "[Base Class Test]" << std::endl;

	Base* p;
	p = new Derived();

	delete p;

	std::cout << std::endl << "[Virtual Base Class Test]" << std::endl;

	VBase* v_p;
	v_p = new VDerived();

	delete v_p;


	//result

	//[Base Class Test]
	//constructor() of base
	//	constructor() of derived
	//	destructor() of base

	//	[Virtual Base Class Test]
	//constructor() of v_base
	//	constructor() of v_derived
	//	destructor() of v_derived
	//	destructor() of v_base

}