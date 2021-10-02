#include <iostream>
#include <string>

using namespace std;

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