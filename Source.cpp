#include <iostream>
#include <string>

using namespace std;

int main() {

	
	//string output_bin; //������������� ���������  ��������

	while (true)
	{
		cout << "Translating a number from decimal to binary" << endl;
		cout << "Input an integer: ";
		double input_value;   // ������������� �������� ��������
		cin >> input_value; // ���� ��������

	goBackToInput://����� �������� �������� �����

		if (cin.fail() || input_value < 0 || (input_value - int(input_value) != 0.0)) // �������� �����
		{
			cin.clear(); // ������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // �������� �������� ����������� ����� �� �������� ������
			cout << "Wrong type of input data, try again" << endl;
			
			cout << "Input an integer: ";
			cin >> input_value; // ���� ��������
			
			goto goBackToInput; //������� � ����� �������� �����
			
		}
		else
		{
			input_value = int(input_value);
			cout << input_value << endl;
		}

		cout << "Continue? (Y/N) " << endl;
		string end_point;  //���������� ��� ���������� ���������� ��� ����� N
		cin >> end_point;
		cout << endl;

	tryAgainYN://����� ������� �������� Y/N

		while (end_point != "Y" and end_point != "N")//�������� ����� Y/N
		{
			cout << "Unidentified operator, try again" << endl;
			cout << "Continue? (Y/N) " << endl;
			cin >> end_point;
			cout << endl;
			if (end_point == "Y" || end_point == "N")
			{
				goto tryAgainYN;// ������� � ����� �������� Y/N
			}
		}


		if (end_point == "N")
		{
			break;
		}

	}
	return 0;
}