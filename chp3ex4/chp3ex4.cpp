//chp3ex4
#include <iostream>
#include <string>


	using std::cout; using std::cin;
	using std::endl; using std::string;
	

	int main() {

		cout << "Enter all words  followed EOF:" << endl;

		string max = ""; //word not size
		string min = ""; //word not size

		//�Է��� ���� ����
		string word;  //cin���� ����ϱ�

		while (cin >> word) {
			//�ʱ�ȭ
			if (min.size() == 0) min = word;
			if (max.size() == 0) max = word;

			//ũ�� Ȯ��
			if (word.size() < min.size()) min = word;
			else if (word.size() > max.size()) max = word;
		}
		//����� Ȯ��
		cout << "max: " << max << endl;
		cout << "min: " << min;

		return 0;
}