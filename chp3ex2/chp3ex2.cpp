//chp3ex2.cpp
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cin;   using std::setprecision;   //실수 숫자 같이 정의
using std::cout;  using std::string;
using std::endl;  using std::streamsize;
using std::sort;  using std::vector;

int main() {
	//과제 점수를 물음
	cout << "enter all values  followed be eof: ";
	
	vector<double> val;

	//입력을 위한 변수
	double x; //cin에서 사용

	//불변성: 지금까지 count개 점수를 입력받았으며
	//입력받은 점수의 합은 sum

	while (cin >> x) {
		val.push_back(x);
	}

	//과제 점수 입력유무를 확인
	typedef vector<double>::size_type vec_sz;
	vec_sz size = val.size();

	if (size == 0) {
		cout << endl << "No grades. Try again." << endl;
		return 1;
	}

	//점수를 정렬
	sort(val.begin(), val.end());

	//과제 점수의 중앙값을 구함
	vec_sz q1 = size / 4;
	vec_sz q2 = size / 2;
	vec_sz q3 = 3*size / 4;

	//sort
	double q1_val, q2_val, q3_val;
	q1_val = size % 4 == 0 ? (val[q1] + val[q1 - 1]) / 2 : val[q1];
	q2_val = size % 2 == 0 ? (val[q2] + val[q2 - 1]) / 2 : val[q2];
	q3_val = 3 *size % 4 == 0 ? (val[q3] + val[q3 - 1]) / 2 : val[q3];
	
	
	//결과를 출력
	cout << "q1: " <<q1_val << endl
			<< "q2: " << q2_val << endl
			<< "q3: " << q3_val << endl;

	return 0;
} //main 끝