#include <algorithm>
#include"myFunc.h"

//�w�肵���T�C�Y�̕�����̂����A�E����w�肵��order�Ԗڂ�
//�����́A���̕�����ɂ�����Y����Ԃ��B��ԉE�̕����͉E����1�ԖڂƐ�����B
int get_index_from_end(int str_size, int order) {

	//"osage"�̉E����3�Ԗڂ̕���('a')�̓Y����5(=str_size)-3(=order)=2(=�Y��)
	return str_size - order;
}

//�擪�ɗ]����0�̂���string������K�؂Ȑ����ɒ���
void adjust_str(std::string& num) {

	//�󕶎���Ȃ�Ȃɂ����Ȃ�
	if (num == "") {
		return;
	}

	size_t pos = num.find_first_not_of('0');
	if (pos == std::string::npos) pos = num.length() - 1;
	num.erase(num.begin(), num.begin() + pos);
}

std::string add_str(std::string a_num, std::string b_num) {
	//�Ԃ��l�B�󕶎���ŏ�����
	std::string answer = "";

	//�擪�ɗ]�v��0�������Čv�Z�����������Ȃ�Ȃ��悤�ɂ������蕥��
	adjust_str(a_num);
	adjust_str(b_num);

	//�J��オ�肪���������̔���
	bool carry_over_flag = false;

	//
	//�ǂ��炩�����̒l�̏ꍇ�͈ȉ��ŕςɂȂ�Ȃ��悤�ɂ���
	//

	//�ǂ�������̒l�Ȃ瑫������}�C�i�X��t����
	if (a_num[0] == '-'&&b_num[0] == '-') {
		//�擪(='-')������
		a_num.erase(a_num.begin());
		b_num.erase(b_num.begin());

		return  "-" + add_str(a_num, b_num);
	}

	//a�����̒l�Ȃ�b-|a|���l����
	if (a_num[0] == '-') {
		//�擪(='-')������
		a_num.erase(a_num.begin());

		return  sub_str(b_num, a_num);
	}

	//b�����̒l�Ȃ�a-|b|
	if (b_num[0] == '-') {
		//�擪(='-')������
		b_num.erase(b_num.begin());

		return  sub_str(a_num, b_num);
	}

	//
	//���������̐��̏ꍇ���ȉ�
	//

	//���[�v���I��邩�̔��������
	auto check_end = [&](int now_digit) {

		//�S�Ă̌��ɂ��Čv�Z���I����Ă���킯�łȂ����
		if (a_num.size() >= now_digit
			|| b_num.size() >= now_digit) {
			//�I����Ă��Ȃ�
			return false;
		}

		if (carry_over_flag == true) {
			//�I����Ă��Ȃ�
			return false;
		}

		//�I����Ă���
		return true;
	};

	//��ԉE�̌�������Z���Ă���
	for (int digit_from_right = 1; check_end(digit_from_right) == false; digit_from_right++) {
		int a_digit;
		int b_digit;
		int digit_sum;//��������̒l

					  //a�������Ă��錅�������������
		if (digit_from_right <= a_num.size()) {
			//a�̒l
			a_digit = stoi(std::string(1, a_num[get_index_from_end(a_num.size(), digit_from_right)]));
		}
		//�Ȃ����
		else {
			//a�̒l��0�Ƃ��Ė��߂�
			a_digit = 0;
		}

		//b�������Ă��錅�������������
		if (digit_from_right <= b_num.size()) {
			//b�̒l
			b_digit = stoi(std::string(1, b_num[get_index_from_end(b_num.size(), digit_from_right)]));
		}
		//�Ȃ����
		else {
			//b�̒l��0�Ƃ��Ė��߂�
			b_digit = 0;
		}

		//���̍��v���o��
		digit_sum = a_digit + b_digit;

		//�ЂƂ��̈ʂ���̌���肪����������Z����
		if (carry_over_flag == true) {
			digit_sum++;
		}

		//���̉��Ŏ��ۂɕԂ��l�ɑ������

		//��̈ʂւ̌���肪��������
		if (digit_sum >= 10) {
			carry_over_flag = true;
			//1�̈ʂ����𓪂ɒǉ�
			answer = std::to_string(digit_sum % 10) + answer;
		}
		else {
			carry_over_flag = false;
			//������
			answer = std::to_string(digit_sum) + answer;
		}

	}
	return answer;
}

std::string sub_str(std::string a_num, std::string b_num) {
	//�Ԃ��l�B�󕶎���ŏ�����
	std::string answer = "";

	//�擪�ɗ]�v��0�������Čv�Z�����������Ȃ�Ȃ��悤�ɂ������蕥��
	adjust_str(a_num);
	adjust_str(b_num);

	//�J�艺���肪���������̔���
	bool borrow_flag = false;

	//
	//�ǂ��炩�����̒l�̏ꍇ�͈ȉ��ŕςɂȂ�Ȃ��悤�ɂ���
	//

	//�ǂ�������̒l�Ȃ�(-|a|)-(-|b|)=-|a|+|b|=|b|-|a|
	if (a_num[0] == '-'&&b_num[0] == '-') {
		//�擪(='-')������
		a_num.erase(a_num.begin());
		b_num.erase(b_num.begin());

		return  sub_str(b_num, a_num);
	}

	//a�����̒l�Ȃ�-|a|-|b|=-(|a|+|b|)���l����
	if (a_num[0] == '-') {
		//�擪(='-')������
		a_num.erase(a_num.begin());

		return  "-" + add_str(a_num, b_num);
	}

	//b�����̒l�Ȃ�|a|-(-|b|)=|a|+|b|
	if (b_num[0] == '-') {
		//�擪(='-')������
		b_num.erase(b_num.begin());

		return  add_str(a_num, b_num);
	}

	//a=b�Ȃ�a-b=0
	if (a_num == b_num) {
		return "0";
	}

	//b�̕����傫���Ȃ�|a|-|b|=-(|b|-|a|)�Ȃ̂ł������
	if (greater_str(b_num, a_num) == true) {
		return "-" + sub_str(b_num, a_num);
	}


	//
	//���������̐����� a_num > b_num �̏ꍇ���ȉ�
	//

	//���[�v���I��邩�̔��������
	auto check_end = [&](int now_digit) {

		//�S�Ă̌��ɂ��Čv�Z���I����Ă���킯�łȂ����
		if (a_num.size() >= now_digit
			|| b_num.size() >= now_digit) {
			//�I����Ă��Ȃ�
			return false;
		}

		if (borrow_flag == true) {
			//�I����Ă��Ȃ�
			return false;
		}

		//�I����Ă���
		return true;
	};


	//��ԉE�̌����猸�Z���Ă���
	for (int digit_from_right = 1; check_end(digit_from_right) == false; digit_from_right++) {
		int a_digit;
		int b_digit;
		int digit_diff;//�Q�̐��̍�

					   //a�������Ă��錅�������������
		if (digit_from_right <= a_num.size()) {
			//a�̒l
			a_digit = stoi(std::string(1, a_num[get_index_from_end(a_num.size(), digit_from_right)]));
		}
		//�Ȃ����
		else {
			//a�̒l��0�Ƃ��Ė��߂�
			a_digit = 0;
		}

		//b�������Ă��錅�������������
		if (digit_from_right <= b_num.size()) {
			//b�̒l
			b_digit = stoi(std::string(1, b_num[get_index_from_end(b_num.size(), digit_from_right)]));
		}
		//�Ȃ����
		else {
			//b�̒l��0�Ƃ��Ė��߂�
			b_digit = 0;
		}

		//���̍����o��
		digit_diff = a_digit - b_digit;

		//�ЂƂ��̈ʂւ̌J�艺���肪�������猸�Z����
		if (borrow_flag == true) {
			digit_diff--;
		}

		//���̉��Ŏ��ۂɕԂ��l�ɑ������

		//���ł̌v�Z���}�C�i�X=��̈ʂւ̌J�艺���肪��������
		if (digit_diff < 0) {
			borrow_flag = true;
			//���̌�����؂�Ă������Ōv�Z����Bdigit_diff�͕��̒l�Ȃ̂ő���
			answer = std::to_string(10 + digit_diff) + answer;
		}
		else {
			borrow_flag = false;
			//������
			answer = std::to_string(digit_diff) + answer;
		}

	}
	return answer;
}


//2�̕�����𐔎��Ƃ��Ĕ�r�� a_num > b_num �ƂȂ��Ă�����true��Ԃ��A�Ȃ��Ă��Ȃ����false��Ԃ�
bool greater_str(std::string a_num, std::string b_num) {

	//
	//�ǂ��炪���̒l�̏ꍇ
	//

	//�ǂ�������̒l�Ȃ畄�����������㐔����
	if (a_num[0] == '-'&&b_num[0] == '-') {
		//�擪(='-')������
		a_num.erase(a_num.begin());
		b_num.erase(b_num.begin());

		//-|a|>-|b|��|a|<|b|��|b|>|a|
		return   greater_str(b_num, a_num);
	}

	//a�݂̂����̒l�Ȃ�a<b
	if (a_num[0] == '-') {
		return false;
	}

	//b�݂̂����̒l�Ȃ�a>b
	if (b_num[0] == '-') {
		return true;
	}

	//
	//�ǂ�������̒l�̏ꍇ
	//

	//�擪�ɗ]�v��0�������Čv�Z�����������Ȃ�Ȃ��悤�ɂ������蕥��
	adjust_str(a_num);
	adjust_str(b_num);

	//a�̕����T�C�Y���傫��������a�̕����l���傫��
	if (a_num.size() > b_num.size()) {
		return true;
	}
	//b�̕����T�C�Y���傫��������b�̕����l���傫��
	if (b_num.size() > a_num.size()) {
		return false;
	}

	//������������
	if (a_num.size() == b_num.size()) {
		//��̌����猅���m���ׂĂ����A�ǂ����ő召�������炻�ꂪ�S�̂̑召
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

//2�̕�����𐔎��Ƃ��Ĕ�r�� a_num < b_num �ƂȂ��Ă�����true��Ԃ��A�Ȃ��Ă��Ȃ����false��Ԃ�
bool less_str(std::string a_num, std::string b_num) {
	//������������
	if (a_num == b_num) {
		return false;
	}

	//a_num > b_num ��������
	if (greater_str(a_num, b_num) == true) {
		return false;
	}

	//��̂ǂ���ł��Ȃ����
	return true;
}
