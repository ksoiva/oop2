#include <iostream>
#include <string.h>
#define N 20
using namespace std;


class UkrString {
private:

	char* str;
	char substr[N] = {};
	int num = 10, subnum = 0;
	int copnum;

public:

	UkrString(int valuenum) {
		cout << "\n���������� �����������" << endl<<endl;
		num = valuenum;

		str = new char[num];
		cout << "������ �����: ";
		gets_s(str, num);
		num = strlen(str);
		this->copnum = num;
	}

	UkrString(const UkrString& copstr) {
		cout << "\n���������� ����������� ���������" << endl<<endl;
		this->copnum = copstr.copnum + 1;
		this->str = new char[copstr.copnum + 1];
		int i;
		for (i = 0; i < copstr.copnum; i++) {
			this->str[i] = copstr.str[i];
		}
		this->str[i] = '\0';
		this->num = copstr.copnum + 1;
	}

	void Inputsub() {
		gets_s(substr, N);
		subnum = strlen(substr);
		cout << endl;
	}

	bool Check() {
		return (bool)strncmp(str, substr, num);
	}

	void �oncatenation() {
		strncat(str, substr, subnum);
		num += subnum;
	}

	void Output() {
		puts(str);
		cout << endl;
	}

	~UkrString() {
		cout << "���������� ����������" << endl;
		delete[] str;
	}
};

int main() {
	system("chcp 1251");
	UkrString sent1(25);
	UkrString sent2(sent1);
	cout << "������ �������: ";
	sent1.Inputsub();
	if (sent1.Check() == true) {
		cout << "ϳ������ �� ������� � �����."<<endl;
		sent1.�oncatenation();
		cout << "����� ���� ������������: ";
		sent1.Output();
	}
	else cout << "\nϳ������ ������� � �����." << endl;
	return 0;
}
