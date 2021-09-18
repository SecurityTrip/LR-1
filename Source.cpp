#include <iostream>
#include <string>

using namespace std;

int main() {

	
	

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
			int processed_value;
			processed_value = int(input_value);
			string output_bin; //������������� ���������  ��������
			EscapeFrom:
			while (processed_value > 1) 
			{
				output_bin +=to_string(processed_value % 2);
				processed_value = processed_value / 2;
				if (processed_value == 1) 
				{
					output_bin += to_string(processed_value);
					goto EscapeFrom;
				}
			}
			cout << "Result: ";
			for (int i = output_bin.length() - 1; i >= 0; i--)
			{

				cout << output_bin[i];

			}
			cout << endl;
			
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