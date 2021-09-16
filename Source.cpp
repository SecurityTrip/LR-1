#include <iostream>
#include <string>

using namespace std;

int main() {

	float input_value;   // ������������� �������� ��������
	string output_bin; //������������� ���������  ��������
	string end_point;  //���������� ��� ���������� ���������� ��� ����� N

	while (true)
	{
		cout << "Translating a number from decimal to binary" << endl;
		cout << "Input an integer: ";
		cin >> input_value; // ���� ��������

	goBack://����� �������� �������� �����

		if (cin.fail() /*|| (input_value - input_value/1 != 0.0)*/) // ���� ���������� ���������� �� ����������� ��� ��������� ������������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Wrong type of input data, try again" << endl;
			
			cout << "Input an integer: ";
			cin >> input_value; // ���� ��������
			
			goto goBack; //������� � �����
			
		}
		else
		{
			cout << input_value << endl;

		}

		cout << "Continue? (Y/N) " << endl;
		cin >> end_point;
		cout << endl;

	tryAgain://����� ������� �������� Y/N

		while (end_point != "Y" and end_point != "N")//�������� ����� Y/N
		{
			cout << "Unidentified operator, try again" << endl;
			cout << "Continue? (Y/N) " << endl;
			cin >> end_point;
			cout << endl;
			if (end_point == "Y" || end_point == "N")
			{
				goto tryAgain;// ������� � �����
			}
		}


		if (end_point == "N")
		{
			break;
		}

	}
	return 0;
}