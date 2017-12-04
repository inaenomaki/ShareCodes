#pragma once
#include<string>

//
//文字列系
//

//指定したサイズの文字列のうち、右から指定したorder番目の
//文字の、その文字列における添字を返す。一番右の文字は右から1番目と数える。
int get_index_from_end(int str_size, int order);

//先頭に余分な0のついたstring数字を適切な数字に直す
//ex) 0013 -> 13
void adjust_str(std::string& num);

//2つの文字列を数字として加算する
std::string add_str(std::string a_num, std::string b_num);

//2つの文字列を数字として減算する
std::string sub_str(std::string a_num, std::string b_num);

//2つの文字列を数字として比較し a_num > b_num となっていたらtrueを返し、なっていなければfalseを返す
bool greater_str(std::string a_num, std::string b_num);

//2つの文字列を数字として比較し a_num < b_num となっていたらtrueを返し、なっていなければfalseを返す
bool less_str(std::string a_num, std::string b_num);
