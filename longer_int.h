#pragma once

#include<string>

//
//----------------------------------------------------------------------------------------
//longer_int
//----------------------------------------------------------------------------------------
//

//上限のない整数型
class longer_int {
private:
	std::string num_str;//数字の実体
public:
	longer_int();
	longer_int(const int& num);
	longer_int(const std::string& num);
	longer_int(const longer_int& num);

	//コピーを返す(実際にはconst参照)
	const std::string& get_num_cpy() const;
	//参照を返す
	std::string& get_num_ref();

	void set_num(std::string num);

	//演算子オーバーロード
	//

	//"longer_int" and "int"
	operator int() const;

	//"longer_int"
	longer_int operator+() const;
	longer_int operator-() const;

	longer_int operator++();//前置インクリメント
	longer_int operator++(int);//後置インクリメント

	longer_int operator--();//前置デクリメント
	longer_int operator--(int);//後置デクリメント

	//"longer_int" and "longer_int"

	//(a=b)=cが出来るように返り値にconst付けない。
	//値の変更があるので関数の後にもconst付けない。
	longer_int& operator =(const longer_int& obj);
	longer_int& operator += (const longer_int& obj);
	longer_int& operator -= (const longer_int& obj);
	longer_int& operator /= (const longer_int& obj);
	longer_int& operator *= (const longer_int& obj);
	longer_int& operator %= (const longer_int& obj);


	//"longer_int" and "int"

	//(a=b)=cが出来るように返り値にconst付けない。
	//値の変更があるので関数の後にもconst付けない。
	longer_int& operator =(const int& num);
	longer_int& operator += (const int& obj);
	longer_int& operator -= (const int& obj);
	longer_int& operator *= (const int& obj);
	longer_int& operator /= (const int& obj);
	longer_int& operator %= (const int& obj);

	//"longer_int" and "std::string"

	//(a=b)=cが出来るように返り値にconst付けない。
	//値の変更があるので関数の後にもconst付けない。
	longer_int& operator =(const std::string& num);
	longer_int& operator += (const std::string& obj);
	longer_int& operator -= (const std::string& obj);
	longer_int& operator *= (const std::string& obj);
	longer_int& operator /= (const std::string& obj);
	longer_int& operator %= (const std::string& obj);
};

//
//左右の項が等価の演算子は普通の関数として定義したほうが良い
//

//(a+b)=cがコンパイルエラーになるように戻り値はconst
//move semanticsを使うことを考えると戻り値は非constの方が良い？

//"longer_int" and "longer_int"

//四則演算
const longer_int operator +(const longer_int& a, const longer_int& b);
const longer_int operator -(const longer_int& a, const longer_int& b);
const longer_int operator *(const longer_int& a, const longer_int& b);
const longer_int operator /(const longer_int& a, const longer_int& b);
const longer_int operator %(const longer_int& a, const longer_int& b);

//比較演算子
const bool operator ==(const longer_int& a, const longer_int& b);
const bool operator !=(const longer_int& a, const longer_int& b);
const bool operator >(const longer_int& a, const longer_int& b);
const bool operator >=(const longer_int& a, const longer_int& b);
const bool operator <(const longer_int& a, const longer_int& b);
const bool operator <=(const longer_int& a, const longer_int& b);

//"longer_int" and "int"

//四則演算
const longer_int operator +(const longer_int& a, const int& b);
const longer_int operator -(const longer_int& a, const int& b);
const longer_int operator *(const longer_int& a, const int& b);
const longer_int operator /(const longer_int& a, const int& b);
const longer_int operator %(const longer_int& a, const int& b);

//比較演算子
const bool operator ==(const longer_int& a, const int& b);
const bool operator !=(const longer_int& a, const int& b);
const bool operator >(const longer_int& a, const int& b);
const bool operator >=(const longer_int& a, const int& b);
const bool operator <(const longer_int& a, const int& b);
const bool operator <=(const longer_int& a, const int& b);

//"int" and "longer_int" 

//四則演算
const longer_int operator +(const int& a, const longer_int& b);
const longer_int operator -(const int& a, const longer_int& b);
const longer_int operator *(const int& a, const longer_int& b);
const longer_int operator /(const int& a, const longer_int& b);
const longer_int operator %(const int& a, const longer_int& b);

//比較演算子
const bool operator ==(const int& a, const longer_int& b);
const bool operator !=(const int& a, const longer_int& b);
const bool operator >(const int& a, const longer_int& b);
const bool operator >=(const int& a, const longer_int& b);
const bool operator <(const int& a, const longer_int& b);
const bool operator <=(const int& a, const longer_int& b);

//"longer_int" and "std::string"

//四則演算
const longer_int operator +(const longer_int& a, const std::string& b);
const longer_int operator -(const longer_int& a, const std::string& b);
const longer_int operator *(const longer_int& a, const std::string& b);
const longer_int operator /(const longer_int& a, const std::string& b);
const longer_int operator %(const longer_int& a, const std::string& b);

//比較演算子
const bool operator ==(const longer_int& a, const std::string& b);
const bool operator !=(const longer_int& a, const std::string& b);
const bool operator >(const longer_int& a, const std::string& b);
const bool operator >=(const longer_int& a, const std::string& b);
const bool operator <(const longer_int& a, const std::string& b);
const bool operator <=(const longer_int& a, const std::string& b);

//"int" and "longer_int" 

//四則演算
const longer_int operator +(const std::string& a, const longer_int& b);
const longer_int operator -(const std::string& a, const longer_int& b);
const longer_int operator *(const std::string& a, const longer_int& b);
const longer_int operator /(const std::string& a, const longer_int& b);
const longer_int operator %(const std::string& a, const longer_int& b);

//比較演算子
const bool operator ==(const std::string& a, const longer_int& b);
const bool operator !=(const std::string& a, const longer_int& b);
const bool operator >(const std::string& a, const longer_int& b);
const bool operator >=(const std::string& a, const longer_int& b);
const bool operator <(const std::string& a, const longer_int& b);
const bool operator <=(const std::string& a, const longer_int& b);
