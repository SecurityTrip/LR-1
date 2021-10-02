#include <iostream>
#include <string>

using namespace std;

string sum(const string s1, const string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	// Выровняем длины строк
	string ls1 = len1 < len2 ? s1 : s2;
	string ls2 = len1 < len2 ? s2 : s1;
	for (int i = ls1.size(); i < ls2.size(); ++i) ls1 = '0' + ls1;

	string result;
	int carry = 0;
	for (int i = ls2.size() - 1; i >= 0; --i) {
		int bit1 = ls1.at(i) - '0'; // '0' => 0, '1' => 1
		int bit2 = ls2.at(i) - '0';
		char sum = (bit1 ^ bit2 ^ carry) + '0';
		result = sum + result;
		carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
	}
	if (carry) result = '1' + result;
	return result;
}

int main() {

	while (true)
	{
		cout << "Translating a number from decimal to binary" << endl;
		cout << "Input an integer: ";
		double input_value;   // инициализация входного значения
		cin >> input_value; // ввод значения

	

		while ((cin.fail()) || (cin.peek() != '\n') || (input_value - int(input_value) != 0.0)) // проверка ввода
		{
			cin.clear(); // возврат cin в обычный режим работы
			cin.ignore(9999999, '\n'); // удаление значения предыдущего ввода из входного буфера
			cout << "Wrong type of input data, try again" << endl;
			
			cout << "Input an integer: ";
			cin >> input_value; // ввод значения
		}
		
		int processed_value;
		processed_value = int(input_value);

		if (processed_value >= 0) //перевод не отрицательных чисел в двоичную систему счисления
		{
			if (processed_value > 1)
			{
				string output_bin; //инициализация выводного  значения
				while (processed_value > 1)
				{
					output_bin += to_string(processed_value % 2);
					processed_value = processed_value / 2;
					if (processed_value == 1)
					{
						output_bin += to_string(processed_value);
					}
				}

				cout << "Result: ";
				for (int i = output_bin.length() - 1; i >= 0; i--) //вывод числа в двоичной системе
				{
					cout << output_bin[i];
				}
				cout << endl;
			}
			else
			{
				cout << "Result: " << processed_value << endl;
			}
		}
		else //перевод отрицательных чисел в двоичную систему счисления
		{
			string output_bin; //инициализация выводного  значения
			
			processed_value = abs(processed_value);
			while (processed_value > 1) //перевод модуля числа в двоичную систему
			{
				output_bin += to_string(processed_value % 2);
				processed_value = processed_value / 2;
				if (processed_value == 1)
				{
					output_bin += to_string(processed_value);
				}
			}

			int i = 0;
			string output_negative;

			while (i!= output_bin.length()) //инвертирование числа в двоичной системе
			{
				if (output_bin[i] == '0')
				{
					output_negative += '1';
				}
				else
				{
					output_negative += '0';
				}
				i++;
			}
			
			cout << sum(output_negative, "1") << endl;

		}
		
		cout << "Continue? (Y/N) " << endl;
		string end_point;  //переменная для завершения выполнения при вводе N
		cin >> end_point;
		cout << endl;

		while (true)
		{
			if ((end_point == "Y") || (end_point == "y") || (end_point == "N") || (end_point == "n"))
			{
				break;
			}
			else
			{
				cout << "Unidentified operator, try again" << endl;
				cout << "Continue? (Y/N) " << endl;
				cin >> end_point;
				cout << endl;
			}
		}

		if (end_point == "N" || end_point == "n")
		{
			break;
		}
	}
	return 0;
}