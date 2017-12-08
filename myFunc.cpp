#include <algorithm>
#include"myFunc.h"

//指定したサイズの文字列のうち、右から指定したorder番目の
//文字の、その文字列における添字を返す。一番右の文字は右から1番目と数える。
int get_index_from_end(int str_size, int order) {

	//"osage"の右から3番目の文字('a')の添字は5(=str_size)-3(=order)=2(=添字)
	return str_size - order;
}

//先頭に余分な0のついたstring数字を適切な数字に直す
void adjust_str(std::string& num) {

	//空文字列ならなにもしない
	if (num == "") {
		return;
	}

	size_t pos = num.find_first_not_of('0');
	if (pos == std::string::npos) pos = num.length() - 1;
	num.erase(num.begin(), num.begin() + pos);
}

std::string add_str(std::string a_num, std::string b_num) {
	//返す値。空文字列で初期化
	std::string answer = "";

	//先頭に余計な0があって計算がおかしくならないようにそれを取り払う
	adjust_str(a_num);
	adjust_str(b_num);

	//繰り上がりがあったかの判定
	bool carry_over_flag = false;

	//
	//どちらかが負の値の場合は以下で変にならないようにする
	//

	//どちらも負の値なら足した後マイナスを付ける
	if (a_num[0] == '-'&&b_num[0] == '-') {
		//先頭(='-')を消す
		a_num.erase(a_num.begin());
		b_num.erase(b_num.begin());

		return  "-" + add_str(a_num, b_num);
	}

	//aが負の値ならb-|a|を考える
	if (a_num[0] == '-') {
		//先頭(='-')を消す
		a_num.erase(a_num.begin());

		return  sub_str(b_num, a_num);
	}

	//bが負の値ならa-|b|
	if (b_num[0] == '-') {
		//先頭(='-')を消す
		b_num.erase(b_num.begin());

		return  sub_str(a_num, b_num);
	}

	//
	//両方が正の数の場合が以下
	//

	//ループを終わるかの判定をする
	auto check_end = [&](int now_digit) {

		//全ての桁について計算が終わっているわけでなければ
		if (a_num.size() >= now_digit
			|| b_num.size() >= now_digit) {
			//終わっていない
			return false;
		}

		if (carry_over_flag == true) {
			//終わっていない
			return false;
		}

		//終わっている
		return true;
	};

	//一番右の桁から加算していく
	for (int digit_from_right = 1; check_end(digit_from_right) == false; digit_from_right++) {
		int a_digit;
		int b_digit;
		int digit_sum;//足した後の値

					  //aが今見ている桁数数字があれば
		if (digit_from_right <= a_num.size()) {
			//aの値
			a_digit = stoi(std::string(1, a_num[get_index_from_end(a_num.size(), digit_from_right)]));
		}
		//なければ
		else {
			//aの値を0として埋める
			a_digit = 0;
		}

		//bが今見ている桁数数字があれば
		if (digit_from_right <= b_num.size()) {
			//bの値
			b_digit = stoi(std::string(1, b_num[get_index_from_end(b_num.size(), digit_from_right)]));
		}
		//なければ
		else {
			//bの値を0として埋める
			b_digit = 0;
		}

		//桁の合計を出す
		digit_sum = a_digit + b_digit;

		//ひとつ下の位からの桁上りがあったら加算する
		if (carry_over_flag == true) {
			digit_sum++;
		}

		//この下で実際に返す値に代入する

		//上の位への桁上りがあったら
		if (digit_sum >= 10) {
			carry_over_flag = true;
			//1の位だけを頭に追加
			answer = std::to_string(digit_sum % 10) + answer;
		}
		else {
			carry_over_flag = false;
			//桁を代入
			answer = std::to_string(digit_sum) + answer;
		}

	}
	return answer;
}

std::string sub_str(std::string a_num, std::string b_num) {
	//返す値。空文字列で初期化
	std::string answer = "";

	//先頭に余計な0があって計算がおかしくならないようにそれを取り払う
	adjust_str(a_num);
	adjust_str(b_num);

	//繰り下がりがあったかの判定
	bool borrow_flag = false;

	//
	//どちらかが負の値の場合は以下で変にならないようにする
	//

	//どちらも負の値なら(-|a|)-(-|b|)=-|a|+|b|=|b|-|a|
	if (a_num[0] == '-'&&b_num[0] == '-') {
		//先頭(='-')を消す
		a_num.erase(a_num.begin());
		b_num.erase(b_num.begin());

		return  sub_str(b_num, a_num);
	}

	//aが負の値なら-|a|-|b|=-(|a|+|b|)を考える
	if (a_num[0] == '-') {
		//先頭(='-')を消す
		a_num.erase(a_num.begin());

		return  "-" + add_str(a_num, b_num);
	}

	//bが負の値なら|a|-(-|b|)=|a|+|b|
	if (b_num[0] == '-') {
		//先頭(='-')を消す
		b_num.erase(b_num.begin());

		return  add_str(a_num, b_num);
	}

	//a=bならa-b=0
	if (a_num == b_num) {
		return "0";
	}

	//bの方が大きいなら|a|-|b|=-(|b|-|a|)なのでこちらで
	if (greater_str(b_num, a_num) == true) {
		return "-" + sub_str(b_num, a_num);
	}


	//
	//両方が正の数かつ a_num > b_num の場合が以下
	//

	//ループを終わるかの判定をする
	auto check_end = [&](int now_digit) {

		//全ての桁について計算が終わっているわけでなければ
		if (a_num.size() >= now_digit
			|| b_num.size() >= now_digit) {
			//終わっていない
			return false;
		}

		if (borrow_flag == true) {
			//終わっていない
			return false;
		}

		//終わっている
		return true;
	};


	//一番右の桁から減算していく
	for (int digit_from_right = 1; check_end(digit_from_right) == false; digit_from_right++) {
		int a_digit;
		int b_digit;
		int digit_diff;//２つの数の差

					   //aが今見ている桁数数字があれば
		if (digit_from_right <= a_num.size()) {
			//aの値
			a_digit = stoi(std::string(1, a_num[get_index_from_end(a_num.size(), digit_from_right)]));
		}
		//なければ
		else {
			//aの値を0として埋める
			a_digit = 0;
		}

		//bが今見ている桁数数字があれば
		if (digit_from_right <= b_num.size()) {
			//bの値
			b_digit = stoi(std::string(1, b_num[get_index_from_end(b_num.size(), digit_from_right)]));
		}
		//なければ
		else {
			//bの値を0として埋める
			b_digit = 0;
		}

		//桁の差を出す
		digit_diff = a_digit - b_digit;

		//ひとつ下の位への繰り下がりがあったら減算する
		if (borrow_flag == true) {
			digit_diff--;
		}

		//この下で実際に返す値に代入する

		//桁での計算がマイナス=上の位への繰り下がりがあったら
		if (digit_diff < 0) {
			borrow_flag = true;
			//一つ上の桁から借りてきた分で計算する。digit_diffは負の値なので足す
			answer = std::to_string(10 + digit_diff) + answer;
		}
		else {
			borrow_flag = false;
			//桁を代入
			answer = std::to_string(digit_diff) + answer;
		}

	}
	return answer;
}


//2つの文字列を数字として比較し a_num > b_num となっていたらtrueを返し、なっていなければfalseを返す
bool greater_str(std::string a_num, std::string b_num) {

	//
	//どちらが負の値の場合
	//

	//どちらも負の値なら符号を消した後数字が
	if (a_num[0] == '-'&&b_num[0] == '-') {
		//先頭(='-')を消す
		a_num.erase(a_num.begin());
		b_num.erase(b_num.begin());

		//-|a|>-|b|→|a|<|b|→|b|>|a|
		return   greater_str(b_num, a_num);
	}

	//aのみが負の値ならa<b
	if (a_num[0] == '-') {
		return false;
	}

	//bのみが負の値ならa>b
	if (b_num[0] == '-') {
		return true;
	}

	//
	//どちらも正の値の場合
	//

	//先頭に余計な0があって計算がおかしくならないようにそれを取り払う
	adjust_str(a_num);
	adjust_str(b_num);

	//aの方がサイズが大きかったらaの方が値も大きい
	if (a_num.size() > b_num.size()) {
		return true;
	}
	//bの方がサイズが大きかったらbの方が値も大きい
	if (b_num.size() > a_num.size()) {
		return false;
	}

	//桁数が同じ時
	if (a_num.size() == b_num.size()) {
		//上の桁から桁同士を比べていき、どこかで大小がついたらそれが全体の大小
		for (int i = 0; i < a_num.size(); i++) {
			if (a_num[i] > b_num[i]) {
				return true;
			}
			if (a_num[i] < b_num[i]) {
				return false;
			}
		}
	}
}

//2つの文字列を数字として比較し a_num < b_num となっていたらtrueを返し、なっていなければfalseを返す
bool less_str(std::string a_num, std::string b_num) {
	//同じだったら
	if (a_num == b_num) {
		return false;
	}

	//a_num > b_num だったら
	if (greater_str(a_num, b_num) == true) {
		return false;
	}

	//上のどちらでもなければ
	return true;
}
