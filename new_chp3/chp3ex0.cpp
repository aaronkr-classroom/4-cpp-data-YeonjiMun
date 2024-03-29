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
	//학생의 이름을 묻고 입력 받기
	cout << "Your name: ";
	string name;
	cin >> name;
	cout << "hello, " << name << "!" << endl;

	//중간고사 점수와 기마록사 점수를 묻고 입력 받기
	cout << "Mid term and final score: ";
	double midterm, final; //double 최소 10자리에서 보통 15자리까지
	cin >> midterm >> final;

	//과제 점수를 물음
	cout << "Enter all homework grades"
		"followed by EOF: "; //end of file

	//지금까지 입력된 과제 점수의 개수와 함
	vector<double> homework;

	//입력을 위한 변수
	double x; //cin에서 사용하기

	//불변성: 지금까지 count개 점수를 입력받았으며
	//입력받은 점수의 합은 sum
	while (cin >> x) {
		homework.push_back(x);
	}

	//과제 점수 입력유무를 확인
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size == 0) {
		cout << endl << "No grades. Try again." << endl;
		return 1;
	}

	//점수를 정렬
	sort(homework.begin(), homework.end());

	//과제 점수의 중앙값을 구함
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
		: homework[mid];
	//결과물 출력
	
		streamsize prec = cout.precision(); //지금 cout precision
	cout << "Final grade: " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
} //main 끝