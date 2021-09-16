#include <iostream>
#include <string>

using namespace std;

int main() {

	
	//string output_bin; //инициализация выводного  значения

	while (true)
	{
		cout << "Translating a number from decimal to binary" << endl;
		cout << "Input an integer: ";
		double input_value;   // инициализация входного значения
		cin >> input_value; // ввод значения

	goBackToInput://метка возврата проверки ввода

		if (cin.fail() || input_value < 0 || (input_value - int(input_value) != 0.0)) // проверка ввода
		{
			cin.clear(); // возврат cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // удаление значения предыдущего ввода из входного буфера
			cout << "Wrong type of input data, try again" << endl;
			
			cout << "Input an integer: ";
			cin >> input_value; // ввод значения
			
			goto goBackToInput; //везврат к метке проверки ввода
			
		}
		else
		{
			input_value = int(input_value);
			cout << input_value << endl;
		}

		cout << "Continue? (Y/N) " << endl;
		string end_point;  //переменная для завершения выполнения при вводе N
		cin >> end_point;
		cout << endl;

	tryAgainYN://метка возрата проверки Y/N

		while (end_point != "Y" and end_point != "N")//преверка ввода Y/N
		{
			cout << "Unidentified operator, try again" << endl;
			cout << "Continue? (Y/N) " << endl;
			cin >> end_point;
			cout << endl;
			if (end_point == "Y" || end_point == "N")
			{
				goto tryAgainYN;// возврат к метке проверки Y/N
			}
		}


		if (end_point == "N")
		{
			break;
		}

	}
	return 0;
}