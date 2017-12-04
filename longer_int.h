#pragma once

#include<string>

//
//----------------------------------------------------------------------------------------
//longer_int
//----------------------------------------------------------------------------------------
//

//����̂Ȃ������^
class longer_int {
private:
	std::string num_str;//�����̎���
public:
	longer_int();
	longer_int(const int& num);
	longer_int(const std::string& num);
	longer_int(const longer_int& num);

	//�R�s�[��Ԃ�(���ۂɂ�const�Q��)
	const std::string& get_num_cpy() const;
	//�Q�Ƃ�Ԃ�
	std::string& get_num_ref();

	void set_num(std::string num);

	//���Z�q�I�[�o�[���[�h
	//

	//"longer_int" and "int"
	operator int() const;

	//"longer_int"
	longer_int operator+() const;
	longer_int operator-() const;

	longer_int operator++();//�O�u�C���N�������g
	longer_int operator++(int);//��u�C���N�������g

	longer_int operator--();//�O�u�f�N�������g
	longer_int operator--(int);//��u�f�N�������g

	//"longer_int" and "longer_int"

	//(a=b)=c���o����悤�ɕԂ�l��const�t���Ȃ��B
	//�l�̕ύX������̂Ŋ֐��̌�ɂ�const�t���Ȃ��B
	longer_int& operator =(const longer_int& obj);
	longer_int& operator += (const longer_int& obj);
	longer_int& operator -= (const longer_int& obj);
	longer_int& operator /= (const longer_int& obj);
	longer_int& operator *= (const longer_int& obj);
	longer_int& operator %= (const longer_int& obj);


	//"longer_int" and "int"

	//(a=b)=c���o����悤�ɕԂ�l��const�t���Ȃ��B
	//�l�̕ύX������̂Ŋ֐��̌�ɂ�const�t���Ȃ��B
	longer_int& operator =(const int& num);
	longer_int& operator += (const int& obj);
	longer_int& operator -= (const int& obj);
	longer_int& operator *= (const int& obj);
	longer_int& operator /= (const int& obj);
	longer_int& operator %= (const int& obj);

	//"longer_int" and "std::string"

	//(a=b)=c���o����悤�ɕԂ�l��const�t���Ȃ��B
	//�l�̕ύX������̂Ŋ֐��̌�ɂ�const�t���Ȃ��B
	longer_int& operator =(const std::string& num);
	longer_int& operator += (const std::string& obj);
	longer_int& operator -= (const std::string& obj);
	longer_int& operator *= (const std::string& obj);
	longer_int& operator /= (const std::string& obj);
	longer_int& operator %= (const std::string& obj);
};

//
//���E�̍��������̉��Z�q�͕��ʂ̊֐��Ƃ��Ē�`�����ق����ǂ�
//

//(a+b)=c���R���p�C���G���[�ɂȂ�悤�ɖ߂�l��const
//move semantics���g�����Ƃ��l����Ɩ߂�l�͔�const�̕����ǂ��H

//"longer_int" and "longer_int"

//�l�����Z
const longer_int operator +(const longer_int& a, const longer_int& b);
const longer_int operator -(const longer_int& a, const longer_int& b);
const longer_int operator *(const longer_int& a, const longer_int& b);
const longer_int operator /(const longer_int& a, const longer_int& b);
const longer_int operator %(const longer_int& a, const longer_int& b);

//��r���Z�q
const bool operator ==(const longer_int& a, const longer_int& b);
const bool operator !=(const longer_int& a, const longer_int& b);
const bool operator >(const longer_int& a, const longer_int& b);
const bool operator >=(const longer_int& a, const longer_int& b);
const bool operator <(const longer_int& a, const longer_int& b);
const bool operator <=(const longer_int& a, const longer_int& b);

//"longer_int" and "int"

//�l�����Z
const longer_int operator +(const longer_int& a, const int& b);
const longer_int operator -(const longer_int& a, const int& b);
const longer_int operator *(const longer_int& a, const int& b);
const longer_int operator /(const longer_int& a, const int& b);
const longer_int operator %(const longer_int& a, const int& b);

//��r���Z�q
const bool operator ==(const longer_int& a, const int& b);
const bool operator !=(const longer_int& a, const int& b);
const bool operator >(const longer_int& a, const int& b);
const bool operator >=(const longer_int& a, const int& b);
const bool operator <(const longer_int& a, const int& b);
const bool operator <=(const longer_int& a, const int& b);

//"int" and "longer_int" 

//�l�����Z
const longer_int operator +(const int& a, const longer_int& b);
const longer_int operator -(const int& a, const longer_int& b);
const longer_int operator *(const int& a, const longer_int& b);
const longer_int operator /(const int& a, const longer_int& b);
const longer_int operator %(const int& a, const longer_int& b);

//��r���Z�q
const bool operator ==(const int& a, const longer_int& b);
const bool operator !=(const int& a, const longer_int& b);
const bool operator >(const int& a, const longer_int& b);
const bool operator >=(const int& a, const longer_int& b);
const bool operator <(const int& a, const longer_int& b);
const bool operator <=(const int& a, const longer_int& b);

//"longer_int" and "std::string"

//�l�����Z
const longer_int operator +(const longer_int& a, const std::string& b);
const longer_int operator -(const longer_int& a, const std::string& b);
const longer_int operator *(const longer_int& a, const std::string& b);
const longer_int operator /(const longer_int& a, const std::string& b);
const longer_int operator %(const longer_int& a, const std::string& b);

//��r���Z�q
const bool operator ==(const longer_int& a, const std::string& b);
const bool operator !=(const longer_int& a, const std::string& b);
const bool operator >(const longer_int& a, const std::string& b);
const bool operator >=(const longer_int& a, const std::string& b);
const bool operator <(const longer_int& a, const std::string& b);
const bool operator <=(const longer_int& a, const std::string& b);

//"int" and "longer_int" 

//�l�����Z
const longer_int operator +(const std::string& a, const longer_int& b);
const longer_int operator -(const std::string& a, const longer_int& b);
const longer_int operator *(const std::string& a, const longer_int& b);
const longer_int operator /(const std::string& a, const longer_int& b);
const longer_int operator %(const std::string& a, const longer_int& b);

//��r���Z�q
const bool operator ==(const std::string& a, const longer_int& b);
const bool operator !=(const std::string& a, const longer_int& b);
const bool operator >(const std::string& a, const longer_int& b);
const bool operator >=(const std::string& a, const longer_int& b);
const bool operator <(const std::string& a, const longer_int& b);
const bool operator <=(const std::string& a, const longer_int& b);
