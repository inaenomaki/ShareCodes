#pragma once
#include<string>
#include<iostream>

//
//������n
//

//�w�肵���T�C�Y�̕�����̂����A�E����w�肵��order�Ԗڂ�
//�����́A���̕�����ɂ�����Y����Ԃ��B��ԉE�̕����͉E����1�ԖڂƐ�����B
int get_index_from_end(int str_size, int order);

//�擪�ɗ]����0�̂���string������K�؂Ȑ����ɒ���
//ex) 0013 -> 13
void adjust_str(std::string& num);

//2�̕�����𐔎��Ƃ��ĉ��Z����
std::string add_str(std::string a_num, std::string b_num);

//2�̕�����𐔎��Ƃ��Č��Z����
std::string sub_str(std::string a_num, std::string b_num);

//2�̕�����𐔎��Ƃ��Ĕ�r�� a_num > b_num �ƂȂ��Ă�����true��Ԃ��A�Ȃ��Ă��Ȃ����false��Ԃ�
bool greater_str(std::string a_num, std::string b_num);

//2�̕�����𐔎��Ƃ��Ĕ�r�� a_num < b_num �ƂȂ��Ă�����true��Ԃ��A�Ȃ��Ă��Ȃ����false��Ԃ�
bool less_str(std::string a_num, std::string b_num);

//�ϐ��ȈՕ\���}�N���B�ϐ���n���ƕϐ����Ƃ��̒l��W���o�͂ɏo�͂��Ă����B
#define cout_instant(var)CoutInst(#var,var)

//����͒��ڂ͎g��Ȃ��Bcout_instant�}�N�����g�����ł������Ă΂��B
template<class T>
void CoutInst(std::string name,T var) {
	std::cout << name << " : " << var << std::endl;
}