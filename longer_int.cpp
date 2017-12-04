#include"longer_int.h"
#include"myFunc.h"

#include<cassert>

//
//----------------------------------------------------------------------------------------
//longer_int
//----------------------------------------------------------------------------------------
//

//constructer

longer_int::longer_int() {
	this->set_num("");
}

longer_int::longer_int(const int& num) {
	this->set_num(std::to_string(num));
}

longer_int::longer_int(const std::string& num) {
	this->set_num(num);
}

longer_int::longer_int(const longer_int& num) {
	this->set_num(num.get_num_cpy());
}

//�A�N�Z�T

const std::string& longer_int::get_num_cpy() const {
	return num_str;
}

std::string& longer_int::get_num_ref() {
	return num_str;
}

void longer_int::set_num(std::string num) {
	num_str = num;

	//�l���X�V���ꂽ�ۂɂ��̍œK�����s��
	adjust_str(num_str);
}

//"longer_int" and "int"

longer_int::operator int() const {
	assert(num_str != "");//�󕶎���͕ϊ��ł��Ȃ��̂ő�����邩����������
	return std::stoi(get_num_cpy());
}

//"longer_int"

longer_int longer_int::operator+() const {
	return *this;
}

longer_int longer_int::operator-() const {
	//���̒l��������
	if (this->get_num_cpy()[0] == '-') {
		//�ꕶ���ڂ��폜��������(=���̒l)��Ԃ�
		longer_int reverse_val(get_num_cpy());
		reverse_val.get_num_ref().erase(reverse_val.get_num_ref().begin());
		return reverse_val;
	}
	//���̒l��������
	else {
		return longer_int("-" + this->get_num_cpy());
	}
}

//�O�u�C���N�������g
longer_int longer_int::operator++() {
	//���l���C���N�������g
	set_num(std::to_string(std::stoi(this->get_num_cpy()) + 1));
	return *this;
}

//��u�C���N�������g
longer_int longer_int::operator++(int) {

	//���Ƃ̒l���Ƃ��Ă���
	longer_int old(*this);

	//���Z����
	++(*this);

	//���Ƃ̒l��Ԃ�
	return old;
}


//�O�u�f�N�������g
longer_int longer_int::operator--() {
	//���l���f�N�������g
	set_num(std::to_string(std::stoi(this->get_num_cpy()) - 1));
	return *this;
}

//��u�f�N�������g
longer_int longer_int::operator--(int) {

	//���Ƃ̒l���Ƃ��Ă���
	longer_int old(*this);

	//���Z����
	--(*this);

	//���Ƃ̒l��Ԃ�
	return old;
}

//"longer_int" and "longer_int"

longer_int& longer_int::operator=(const longer_int& obj) {
	set_num(obj.get_num_cpy());
	return *this;
}

longer_int& longer_int::operator += (const longer_int& obj) {
	//���������̂�������
	(*this) = (*this) + obj;

	//�Ԃ�
	return *this;
}

longer_int& longer_int::operator -= (const longer_int& obj) {
	//-�̒l��+=����
	return (*this) += (-obj);
}

longer_int& longer_int::operator *= (const longer_int& obj) {
	//�������l��������
	(*this) = (*this) * obj;

	return  (*this);
}

longer_int& longer_int::operator /= (const longer_int& obj) {
	//�������l��������
	(*this) = (*this) / obj;

	return  (*this);
}

longer_int& longer_int::operator %= (const longer_int& obj) {
	//�]������߂��l��������
	(*this) = (*this) % obj;

	return  (*this);
}
//"longer_int" and "int"


longer_int& longer_int::operator =(const int& num) {
	set_num(std::to_string(num));
	return *this;
}

longer_int& longer_int::operator +=(const int& num) {
	return *this += std::to_string(num);
}

longer_int& longer_int::operator -=(const int& num) {
	return *this -= std::to_string(num);
}

longer_int& longer_int::operator *=(const int& num) {
	return *this *= std::to_string(num);
}

longer_int& longer_int::operator /=(const int& num) {
	return *this /= std::to_string(num);
}

longer_int& longer_int::operator %=(const int& num) {
	return *this %= std::to_string(num);
}

//"longer_int" and "std::string"


longer_int& longer_int::operator =(const std::string& num) {
	set_num(num);
	return *this;
}

longer_int& longer_int::operator +=(const std::string& num) {
	return *this += longer_int(num);
}

longer_int& longer_int::operator -=(const std::string& num) {
	return *this -= longer_int(num);
}

longer_int& longer_int::operator *=(const std::string& num) {
	return *this *= longer_int(num);
}

longer_int& longer_int::operator /=(const std::string& num) {
	return *this /= longer_int(num);
}

longer_int& longer_int::operator %=(const std::string& num) {
	return *this %= longer_int(num);
}

//public

//"longer_int" and "longer_int"

const longer_int operator +(const longer_int& a, const longer_int& b) {
	//���Z����string��Ԃ�
	return longer_int(add_str(a.get_num_cpy(), b.get_num_cpy()));
}


const longer_int operator -(const longer_int& a, const longer_int& b) {
	//���Z����string��Ԃ�
	return longer_int(sub_str(a.get_num_cpy(), b.get_num_cpy()));
}
const longer_int operator *(const longer_int& a, const longer_int& b) {
	longer_int answer = 0;
	//b��0��a�𑫂�
	for (longer_int i = 0; i < b; i++) {
		answer += a;
	}
	return answer;
}
const longer_int operator /(const longer_int& a, const longer_int& b) {
	longer_int divided = a;//�����邽�߂Ɏg����Ba��const�Q�ƂȂ̂�
	longer_int subtract_num = 0;//���Z������

	//�������0�ł͂����Ȃ�
	assert(b != 0);

	//a����b�������Ȃ��Ȃ�܂ň����Ă���
	for (; divided >= b; subtract_num++) {
		divided -= b;
	}

	return subtract_num;
}

const longer_int operator %(const longer_int& a, const longer_int& b) {
	longer_int divided = a;//�����邽�߂Ɏg����Ba��const�Q�ƂȂ̂�
	longer_int subtract_num = 0;//���Z������

								 //�������0�ł͂����Ȃ�
	assert(b != 0);


	//a����b�������Ȃ��Ȃ�܂ň����Ă���
	for (; divided > b; subtract_num++) {
		divided -= b;
	}

	//�]����������Ԃ�
	return divided;
}

const bool operator ==(const longer_int& a, const longer_int& b) {
	return a.get_num_cpy() == b.get_num_cpy();
}

const bool operator !=(const longer_int& a, const longer_int& b) {
	return !(a == b);
}

const bool operator >(const longer_int& a, const longer_int& b) {
	return greater_str(a.get_num_cpy(), b.get_num_cpy());
}

const bool operator >=(const longer_int& a, const longer_int& b) {
	return a > b || a == b;
}

const bool operator <(const longer_int& a, const longer_int& b) {
	return less_str(a.get_num_cpy(), b.get_num_cpy());
}

const bool operator <=(const longer_int& a, const longer_int& b) {
	return a < b || a == b;
}


//"longer_int" and "int"

const longer_int operator +(const longer_int& a, const int& b) {
	//���Z����string��Ԃ�
	return longer_int(add_str(a.get_num_cpy(), std::to_string(b)));
}

const longer_int operator -(const longer_int& a, const int& b) {
	//���Z����string��Ԃ�
	return longer_int(sub_str(a.get_num_cpy(), std::to_string(b)));
}

const longer_int operator *(const longer_int& a, const int& b) {
	longer_int answer = 0;
	//b��0��a�𑫂�
	for (longer_int i = 0; i < b; i++) {
		answer += a;
	}
	return answer;
}

const longer_int operator /(const longer_int& a, const int& b) {
	longer_int divided = a;//�����邽�߂Ɏg����Ba��const�Q�ƂȂ̂�
	longer_int subtract_num = 0;//���Z������

								 //a����b�������Ȃ��Ȃ�܂ň����Ă���
	for (; divided > b; subtract_num++) {
		divided -= b;
	}

	return subtract_num;
}

const longer_int operator %(const longer_int& a, const int& b) {
	longer_int divided = a;//�����邽�߂Ɏg����Ba��const�Q�ƂȂ̂�
	longer_int subtract_num = 0;//���Z������

								 //a����b�������Ȃ��Ȃ�܂ň����Ă���
	for (; divided > b; subtract_num++) {
		divided -= b;
	}
	//�]����������Ԃ�
	return divided;
}

const bool operator ==(const longer_int& a, const int& b) {
	return a.get_num_cpy() == std::to_string(b);
}

const bool operator !=(const longer_int& a, const int& b) {
	return !(a == b);
}

const bool operator >(const longer_int& a, const int& b) {
	return greater_str(a.get_num_cpy(), std::to_string(b));
}

const bool operator >=(const longer_int& a, const int& b) {
	return a > b || a == b;
}

const bool operator <(const longer_int& a, const int& b) {
	return less_str(a.get_num_cpy(), std::to_string(b));
}

const bool operator <=(const longer_int& a, const int& b) {
	return a < b || a == b;
}


//"int" and "longer_int" 


const longer_int operator +(const int& a, const longer_int& b) {
	return b + a;
}

const longer_int operator -(const int& a, const longer_int& b) {
	return -b + a;
}

const longer_int operator *(const int& a, const longer_int& b) {
	return b * a;
}

const longer_int operator /(const int& a, const longer_int& b) {
	return  longer_int(a) / b;
}

const longer_int operator %(const int& a, const longer_int& b) {
	return longer_int(a) % b;
}

//��r���Z�q
const bool operator ==(const int& a, const longer_int& b) {
	return b == a;
}

const bool operator !=(const int& a, const longer_int& b) {
	return b != a;
}

const bool operator >(const int& a, const longer_int& b) {
	return b < a;
}

const bool operator >=(const int& a, const longer_int& b) {
	return b <= a;
}

const bool operator <(const int& a, const longer_int& b) {
	return b > a;
}

const bool operator <=(const int& a, const longer_int& b) {
	return b >= a;
}


//"longer_int" and "std::string"

const longer_int operator +(const longer_int& a, const std::string& b) {
	//���Z����string��Ԃ�
	return longer_int(add_str(a.get_num_cpy(), b));
}

const longer_int operator -(const longer_int& a, const std::string& b) {
	//���Z����string��Ԃ�
	return longer_int(sub_str(a.get_num_cpy(), b));
}

const longer_int operator *(const longer_int& a, const std::string& b) {
	longer_int answer = 0;
	//b��0��a�𑫂�
	for (longer_int i = 0; less_str(std::to_string(i), b); i++) {
		answer += a;
	}
	return answer;
}

const longer_int operator /(const longer_int& a, const std::string& b) {
	longer_int divided = a;//�����邽�߂Ɏg����Ba��const�Q�ƂȂ̂�
	longer_int subtract_num = 0;//���Z������

	//a����b�������Ȃ��Ȃ�܂ň����Ă���
	for (; greater_str(divided.get_num_cpy(), b); subtract_num++) {
		divided -= b;
	}

	return subtract_num;
}

const longer_int operator %(const longer_int& a, const std::string& b) {
	longer_int divided = a;//�����邽�߂Ɏg����Ba��const�Q�ƂȂ̂�
	longer_int subtract_num = 0;//���Z������

								//a����b�������Ȃ��Ȃ�܂ň����Ă���
	for (; greater_str(divided.get_num_cpy(), b); subtract_num++) {
		divided -= b;
	}
	//�]����������Ԃ�
	return divided;
}

const bool operator ==(const longer_int& a, const std::string& b) {
	return a.get_num_cpy() == b;
}

const bool operator !=(const longer_int& a, const std::string& b) {
	return !(a == b);
}

const bool operator >(const longer_int& a, const std::string& b) {
	return greater_str(a.get_num_cpy(), b);
}

const bool operator >=(const longer_int& a, const std::string& b) {
	return a > b || a == b;
}

const bool operator <(const longer_int& a, const std::string& b) {
	return less_str(a.get_num_cpy(), b);
}

const bool operator <=(const longer_int& a, const std::string& b) {
	return a < b || a == b;
}


//"std::string" and "longer_int" 


const longer_int operator +(const std::string& a, const longer_int& b) {
	return b + a;
}

const longer_int operator -(const std::string& a, const longer_int& b) {
	return -b + a;
}

const longer_int operator *(const std::string& a, const longer_int& b) {
	return b * a;
}

const longer_int operator /(const std::string& a, const longer_int& b) {
	return  longer_int(a) / b;
}

const longer_int operator %(const std::string& a, const longer_int& b) {
	return longer_int(a) % b;
}

//��r���Z�q
const bool operator ==(const std::string& a, const longer_int& b) {
	return b == a;
}

const bool operator !=(const std::string& a, const longer_int& b) {
	return b != a;
}

const bool operator >(const std::string& a, const longer_int& b) {
	return b < a;
}

const bool operator >=(const std::string& a, const longer_int& b) {
	return b <= a;
}

const bool operator <(const std::string& a, const longer_int& b) {
	return b > a;
}

const bool operator <=(const std::string& a, const longer_int& b) {
	return b >= a;
}