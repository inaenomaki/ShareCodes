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
	this->set_num(num.str());
}

//アクセサ

const std::string& longer_int::str() const {
	return num_str;
}

void longer_int::set_num(std::string num) {
	num_str = num;

	//値が更新された際にその最適化も行う
	adjust_str(num_str);
}

//左から数えてn番目の桁の値を返す
int longer_int::digit_from_left(int n) {
	//文字数と同じかそれより小さい値を指定
	assert(num_str.size() >= n);

	//char->intの変換
	/*
	return char_val-'0';とすることも考えたが
	どこまで通用するかもわかっていないので
	今回は不採用
	*/

	std::string tmp(1, num_str[n-1]);
	return std::stoi(tmp);
}

//右から数えてn番目の桁の値を返す
int longer_int::digit_from_right(int n) {
	//右からn番目は左から(要素数-n+1)番目
	return digit_from_left(num_str.size()-n+1);
}


//"longer_int" and "int"

longer_int::operator int() const {
	assert(num_str != "");//空文字列は変換できないので代入するか初期化する

	//intの最大値以下
	assert(num_str == std::to_string(INT_MAX) || less_str(num_str, std::to_string(INT_MAX)));

	return std::stoi(this->str());
}

//"longer_int"

longer_int longer_int::operator+() const {
	return *this;
}

longer_int longer_int::operator-() const {
	//負の値だったら
	if (this->str()[0] == '-') {
		//一文字目を削除したもの(=正の値)を返す
		longer_int reverse_val(this->str());
		reverse_val.num_str.erase(reverse_val.num_str.begin());
		return reverse_val;
	}
	//正の値だったら
	else {
		return longer_int("-" + this->str());
	}
}

//前置インクリメント
longer_int longer_int::operator++() {
	//数値をインクリメント
	set_num(std::to_string(std::stoi(this->str()) + 1));
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
	set_num(std::to_string(std::stoi(this->str()) - 1));
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
	set_num(obj.str());
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
	return longer_int(add_str(a.str(), b.str()));
}


const longer_int operator -(const longer_int& a, const longer_int& b) {
	//加算したstringを返す
	return longer_int(sub_str(a.str(), b.str()));
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
	return a.str() == b.str();
}

const bool operator !=(const longer_int& a, const longer_int& b) {
	return !(a == b);
}

const bool operator >(const longer_int& a, const longer_int& b) {
	return greater_str(a.str(), b.str());
}

const bool operator >=(const longer_int& a, const longer_int& b) {
	return a > b || a == b;
}

const bool operator <(const longer_int& a, const longer_int& b) {
	return less_str(a.str(), b.str());
}

const bool operator <=(const longer_int& a, const longer_int& b) {
	return a < b || a == b;
}


//"longer_int" and "int"

const longer_int operator +(const longer_int& a, const int& b) {
	//加算したstringを返す
	return longer_int(add_str(a.str(), std::to_string(b)));
}

const longer_int operator -(const longer_int& a, const int& b) {
	//加算したstringを返す
	return longer_int(sub_str(a.str(), std::to_string(b)));
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
	return a.str() == std::to_string(b);
}

const bool operator !=(const longer_int& a, const int& b) {
	return !(a == b);
}

const bool operator >(const longer_int& a, const int& b) {
	return greater_str(a.str(), std::to_string(b));
}

const bool operator >=(const longer_int& a, const int& b) {
	return a > b || a == b;
}

const bool operator <(const longer_int& a, const int& b) {
	return less_str(a.str(), std::to_string(b));
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
	return longer_int(add_str(a.str(), b));
}

const longer_int operator -(const longer_int& a, const std::string& b) {
	//加算したstringを返す
	return longer_int(sub_str(a.str(), b));
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
	for (; greater_str(divided.str(), b); subtract_num++) {
		divided -= b;
	}

	return subtract_num;
}

const longer_int operator %(const longer_int& a, const std::string& b) {
	longer_int divided = a;//割られるために使われる。aはconst参照なので
	longer_int subtract_num = 0;//減算した回数

								//aからbが引けなくなるまで引いていく
	for (; greater_str(divided.str(), b); subtract_num++) {
		divided -= b;
	}
	//余った部分を返す
	return divided;
}

const bool operator ==(const longer_int& a, const std::string& b) {
	return a.str() == b;
}

const bool operator !=(const longer_int& a, const std::string& b) {
	return !(a == b);
}

const bool operator >(const longer_int& a, const std::string& b) {
	return greater_str(a.str(), b);
}

const bool operator >=(const longer_int& a, const std::string& b) {
	return a > b || a == b;
}

const bool operator <(const longer_int& a, const std::string& b) {
	return less_str(a.str(), b);
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
