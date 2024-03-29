//chp4ex0.cpp
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


using std::cin;   using std::setprecision;   //실수 숫자 같이 정의
using std::cout;  using std::string;
using std::endl;  using std::streamsize;
using std::sort;  using std::vector;
using std::domain_error; using std::istream;

//중간 시험 점수, 기말 시험 점수, 종합 과제 점수
//학생의 종합 점수를 가함
double grade(double mt, double ft, double hw) {
	
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
	
}

//vectoe <double>의 중앙값을 구함
//함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double>vec) {
	//과제 점수의 입력 유무를 확인
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("Median of empty vector");
		return 1;
	}

	//점수를 정렬
	sort(vec.begin(), vec.end());

	//과제 점수의 중앙값을 구함
	vec_sz mid = size / 2;
	return size % 2 == 0 
		? (vec[mid] + vec[mid - 1]) / 2
		: vec[mid];
}
//중간 시험 점수, 기말 시험 점수, 과제 점수의 벡터로 
//학생의 종합 점수를 가함
//이 함수는 인수를 복사하지 않고 median함수가 해당 작업을 실행
double grade(double mt, double ft, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework!");

	return grade(mt, ft, median(hw));
}
 //입력 스트림에서 과제 점수를 입력 받아서 vector<double>에 넣음

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//이전 내용을 제거
		hw.clear();

		//과제 점수를 읽음
		double x;  //cin에서 사용하기
		//불변성: 지금까지 count개 점수를 입력받았으며
		//입력받은 점수의 합은 sum
		while (cin >> x) {
			hw.push_back(x);
		}
		in.clear();

		return in;
	}
}


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

	//과제 점수를 읽음
	read_hw(cin, homework);

	//종합 점수를 계산해 생성
	try {
		double final_grade = grade(midterm, final, homework);
		//결과를 출력
		streamsize prec = cout.precision();
		cout << "Final grade: " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "No grades entered" << endl;
	}

	return 0;
} //main 끝