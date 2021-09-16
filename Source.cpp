#include <iostream>
#include <string>

using namespace std;

int main() {

	float input_value;   // инициализация входного значения
	string output_bin; //инициализация выводного  значения
	string end_point;  //переменная для завершения выполнения при вводе N

	while (true)
	{
		cout << "Translating a number from decimal to binary" << endl;
		cout << "Input an integer: ";
		cin >> input_value; // ввод значения

	goBack://метка возврата проверки ввода

		if (cin.fail() /*|| (input_value - input_value/1 != 0.0)*/) // если предыдущее извлечение не выполнилось или произошло переполнение,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Wrong type of input data, try again" << endl;
			
			cout << "Input an integer: ";
			cin >> input_value; // ввод значения
			
			goto goBack; //везврат к метке
			
		}
		else
		{
			cout << input_value << endl;

		}

		cout << "Continue? (Y/N) " << endl;
		cin >> end_point;
		cout << endl;

	tryAgain://метка возрата проверки Y/N

		while (end_point != "Y" and end_point != "N")//преверка ввода Y/N
		{
			cout << "Unidentified operator, try again" << endl;
			cout << "Continue? (Y/N) " << endl;
			cin >> end_point;
			cout << endl;
			if (end_point == "Y" || end_point == "N")
			{
				goto tryAgain;// возврат к метке
			}
		}


		if (end_point == "N")
		{
			break;
		}

	}
	return 0;
}