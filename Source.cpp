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
		cout << "\nÂèêëèêàâñÿ êîíñòðóêòîð" << endl<<endl;
		num = valuenum;

		str = new char[num];
		cout << "Ââåä³òü ðÿäîê: ";
		gets_s(str, num);
		num = strlen(str);
		this->copnum = num;
	}

	UkrString(const UkrString& copstr) {
		cout << "\nÂèêëèêàâñÿ êîíñòðóêòîð êîï³þâàííÿ" << endl<<endl;
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
		return (bool)strstr(str, substr);
	}

	void Ñoncatenation() {
		strncat(str, substr, subnum);
		num += subnum;
	}

	void Output() {
		puts(str);
		cout << endl;
	}

	~UkrString() {
		cout << "Âèêëèêàâñÿ äåñòðóêòîð" << endl;
		delete[] str;
	}
};

int main() {
	system("chcp 1251");
	UkrString sent1(25);
	UkrString sent2(sent1);
	cout << "Ââåä³òü ï³äðÿäîê: ";
	sent1.Inputsub();
	if (sent1.Check() == false) {
		cout << "Ï³äðÿäîê íå âõîäèòü ó ðÿäîê."<<endl;
		sent1.Ñoncatenation();
		cout << "Ðÿäîê ï³ñëÿ êîíêàòåíàö³¿: ";
		sent1.Output();
	}
	else cout << "Ï³äðÿäîê âõîäèòü ó ðÿäîê." << endl;
	return 0;
}
