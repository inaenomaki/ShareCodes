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

//アクセサ

const std::string& longer_int::get_num_cpy() const {
	return num_str;
}

std::string& longer_int::get_num_ref() {
	return num_str;
}

void longer_int::set_num(std::string num) {
	num_str = num;

	//値が更新された際にその最適化も行う
	adjust_str(num_str);
}

//"longer_int" and "int"

longer_int::operator int() const {
	assert(num_str != "");//空文字列は変換できないので代入するか初期化する
	return std::stoi(get_num_cpy());
}

//"longer_int"

longer_int longer_int::operator+() const {
	return *this;
}

longer_int longer_int::operator-() const {
	//負の値だったら
	if (this->get_num_cpy()[0] == '-') {
		//一文字目を削除したもの(=正の値)を返す
		longer_int reverse_val(get_num_cpy());
		reverse_val.get_num_ref().erase(reverse_val.get_num_ref().begin());
		return reverse_val;
	}
	//正の値だったら
	else {
		return longer_int("-" + this->get_num_cpy());
	}
}

//前置インクリメント
longer_int longer_int::operator++() {
	//数値をインクリメント
	set_num(std::to_string(std::stoi(this->get_num_cpy()) + 1));
	return *this;
}

//後置インクリメント
longer_int longer_int::operator++(int) {

	//もとの値をとっておく
	longer_int old(*this);

	//加算する
	++(*this);

	//もとの値を返す
	return old;
}


//前置デクリメント
longer_int longer_int::operator--() {
	//数値をデクリメント
	set_num(std::to_string(std::stoi(this->get_num_cpy()) - 1));
	return *this;
}

//後置デクリメント
longer_int longer_int::operator--(int) {

	//もとの値をとっておく
	longer_int old(*this);

	//減算する
	--(*this);

	//もとの値を返す
	return old;
}

//"longer_int" and "longer_int"

longer_int& longer_int::operator=(const longer_int& obj) {
	set_num(obj.get_num_cpy());
	return *this;
}

longer_int& longer_int::operator += (const longer_int& obj) {
	//足したものを代入して
	(*this) = (*this) + obj;

	//返す
	return *this;
}

longer_int& longer_int::operator -= (const longer_int& obj) {
	//-の値を+=する
	return (*this) += (-obj);
}

longer_int& longer_int::operator *= (const longer_int& obj) {
	//かけた値を代入して
	(*this) = (*this) * obj;

	return  (*this);
}

longer_int& longer_int::operator /= (const longer_int& obj) {
	//割った値を代入して
	(*this) = (*this) / obj;

	return  (*this);
}

longer_int& longer_int::operator %= (const longer_int& obj) {
	//余りを求めた値を代入して
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
	//加算したstringを返す
	return longer_int(add_str(a.get_num_cpy(), b.get_num_cpy()));
}


const longer_int operator -(const longer_int& a, const longer_int& b) {
	//加算したstringを返す
	return longer_int(sub_str(a.get_num_cpy(), b.get_num_cpy()));
}
const longer_int operator *(const longer_int& a, const longer_int& b) {
	longer_int answer = 0;
	//b回0にaを足す
	for (longer_int i = 0; i < b; i++) {
		answer += a;
	}
	return answer;
}
const longer_int operator /(const longer_int& a, const longer_int& b) {
	longer_int divided = a;//割られるために使われる。aはconst参照なので
	longer_int subtract_num = 0;//減算した回数

	//割る方は0ではいけない
	assert(b != 0);

	//aからbが引けなくなるまで引いていく
	for (; divided >= b; subtract_num++) {
		divided -= b;
	}

	return subtract_num;
}

const longer_int operator %(const longer_int& a, const longer_int& b) {
	longer_int divided = a;//割られるために使われる。aはconst参照なので
	longer_int subtract_num = 0;//減算した回数

								 //割る方は0ではいけない
	assert(b != 0);


	//aからbが引けなくなるまで引いていく
	for (; divided > b; subtract_num++) {
		divided -= b;
	}

	//余った部分を返す
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
	//加算したstringを返す
	return longer_int(add_str(a.get_num_cpy(), std::to_string(b)));
}

const longer_int operator -(const longer_int& a, const int& b) {
	//加算したstringを返す
	return longer_int(sub_str(a.get_num_cpy(), std::to_string(b)));
}

const longer_int operator *(const longer_int& a, const int& b) {
	longer_int answer = 0;
	//b回0にaを足す
	for (longer_int i = 0; i < b; i++) {
		answer += a;
	}
	return answer;
}

const longer_int operator /(const longer_int& a, const int& b) {
	longer_int divided = a;//割られるために使われる。aはconst参照なので
	longer_int subtract_num = 0;//減算した回数

								 //aからbが引けなくなるまで引いていく
	for (; divided > b; subtract_num++) {
		divided -= b;
	}

	return subtract_num;
}

const longer_int operator %(const longer_int& a, const int& b) {
	longer_int divided = a;//割られるために使われる。aはconst参照なので
	longer_int subtract_num = 0;//減算した回数

								 //aからbが引けなくなるまで引いていく
	for (; divided > b; subtract_num++) {
		divided -= b;
	}
	//余った部分を返す
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

//比較演算子
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
	//加算したstringを返す
	return longer_int(add_str(a.get_num_cpy(), b));
}

const longer_int operator -(const longer_int& a, const std::string& b) {
	//加算したstringを返す
	return longer_int(sub_str(a.get_num_cpy(), b));
}

const longer_int operator *(const longer_int& a, const std::string& b) {
	longer_int answer = 0;
	//b回0にaを足す
	for (longer_int i = 0; less_str(std::to_string(i), b); i++) {
		answer += a;
	}
	return answer;
}

const longer_int operator /(const longer_int& a, const std::string& b) {
	longer_int divided = a;//割られるために使われる。aはconst参照なので
	longer_int subtract_num = 0;//減算した回数

	//aからbが引けなくなるまで引いていく
	for (; greater_str(divided.get_num_cpy(), b); subtract_num++) {
		divided -= b;
	}

	return subtract_num;
}

const longer_int operator %(const longer_int& a, const std::string& b) {
	longer_int divided = a;//割られるために使われる。aはconst参照なので
	longer_int subtract_num = 0;//減算した回数

								//aからbが引けなくなるまで引いていく
	for (; greater_str(divided.get_num_cpy(), b); subtract_num++) {
		divided -= b;
	}
	//余った部分を返す
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

//比較演算子
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
