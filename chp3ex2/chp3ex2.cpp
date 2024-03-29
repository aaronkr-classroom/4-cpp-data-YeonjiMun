//chp3ex2.cpp
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cin;   using std::setprecision;   //�Ǽ� ���� ���� ����
using std::cout;  using std::string;
using std::endl;  using std::streamsize;
using std::sort;  using std::vector;

int main() {
	//���� ������ ����
	cout << "enter all values  followed be eof: ";
	
	vector<double> val;

	//�Է��� ���� ����
	double x; //cin���� ���

	//�Һ���: ���ݱ��� count�� ������ �Է¹޾�����
	//�Է¹��� ������ ���� sum

	while (cin >> x) {
		val.push_back(x);
	}

	//���� ���� �Է������� Ȯ��
	typedef vector<double>::size_type vec_sz;
	vec_sz size = val.size();

	if (size == 0) {
		cout << endl << "No grades. Try again." << endl;
		return 1;
	}

	//������ ����
	sort(val.begin(), val.end());

	//���� ������ �߾Ӱ��� ����
	vec_sz q1 = size / 4;
	vec_sz q2 = size / 2;
	vec_sz q3 = 3*size / 4;

	//sort
	double q1_val, q2_val, q3_val;
	q1_val = size % 4 == 0 ? (val[q1] + val[q1 - 1]) / 2 : val[q1];
	q2_val = size % 2 == 0 ? (val[q2] + val[q2 - 1]) / 2 : val[q2];
	q3_val = 3 *size % 4 == 0 ? (val[q3] + val[q3 - 1]) / 2 : val[q3];
	
	
	//����� ���
	cout << "q1: " <<q1_val << endl
			<< "q2: " << q2_val << endl
			<< "q3: " << q3_val << endl;

	return 0;
} //main ��