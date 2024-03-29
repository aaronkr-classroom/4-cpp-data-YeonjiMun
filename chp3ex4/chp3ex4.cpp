//chp3ex4
#include <iostream>
#include <string>


	using std::cout; using std::cin;
	using std::endl; using std::string;
	

	int main() {

		cout << "Enter all words  followed EOF:" << endl;

		string max = ""; //word not size
		string min = ""; //word not size

		//입력을 위한 변수
		string word;  //cin에서 사용하기

		while (cin >> word) {
			//초기화
			if (min.size() == 0) min = word;
			if (max.size() == 0) max = word;

			//크기 확인
			if (word.size() < min.size()) min = word;
			else if (word.size() > max.size()) max = word;
		}
		//결과를 확인
		cout << "max: " << max << endl;
		cout << "min: " << min;

		return 0;
}