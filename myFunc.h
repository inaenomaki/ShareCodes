#pragma once
#include<string>

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
