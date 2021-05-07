#include "Property.h"
#include <deque>
#include <stack>
#include <queue>
#include <Windows.h>

#ifdef max
#undef max
#endif
using namespace std;

bool check(deque<Property> deq);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	deque<Property> DEQ;

	while (true){
		int choice;
		cout << "0 - Выход" << endl;
		cout << "1 - Добавить объект недвижимости в очередь на постройку" << endl;
		cout << "2 - Редактирование первого объекта в очереди" << endl;
		cout << "3 - Редактирование последнего объекта в очереди" << endl;
		cout << "4 - Вызвать в порядке LIFO" << endl;
		cout << "5 - Вызвать в порядке FIFO" << endl;
		cout << "6 - Вызвать в порядке priority" << endl;
		cout << "7 - Вывод очереди" << endl;
		cout << "Ваш выбор: ";
		try	{
			cin >> choice;
			if (!(choice>-1 && choice<8)){
				cin.clear();
				cin.ignore(10, '\n');
				throw 22;
			}
		}
		catch (int){
			cout << "Введите допустимое значение!" << endl;
			Sleep(300);
		}
		
		
		
		switch (choice)
		{
		case 0: return 0;
		case 1: {
			string name;
			cout << "Введите название объекта: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name, '\n');
			Property* property = new Property(name, rand() % 10);
			DEQ.push_back(*property);
			cout << "Номер объекта в очереди: " << DEQ.size() << endl;

			system("pause");
			system("cls");
		}break;
		case 2: {
			if (check(DEQ)) {
				int count = 1;
				cout << " ____________________________________" << endl;
				for (auto it : DEQ) {
					cout << "|" << setw(5) << count << "|" << setw(30) << it.getName() << "|" << endl;
					cout << "|_____|______________________________|" << endl;
					count++;
				}
				string name;
				cout << "Введите новое название объекта: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, name, '\n');
				DEQ.pop_front();
				DEQ.push_front(Property(name, rand() % 10));
				cout << "Данные отредактирвоаны!" << endl;
				Sleep(300);
				system("cls");
			}
		}break;	
		case 3: {
			if (check(DEQ)){
				int count = 1;
				cout << " ____________________________________" << endl;
				for (auto it : DEQ) {
					cout << "|" << setw(5) << count << "|" << setw(30) << it.getName() << "|" << endl;
					cout << "|_____|______________________________|" << endl;
					count++;
				}
				string name;
				cout << "Введите новое название объекта: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, name, '\n');
				DEQ.pop_back();
				DEQ.push_back(Property(name, rand() % 10));
				cout << "Данные отредактирвоаны!" << endl;
				Sleep(300);
				system("cls");
			}
		}break;
		case 4: {
			if (check(DEQ)) {
				stack<Property> stck(DEQ);
				cout << "Последний объект из очереди: " << stck.top().getName() << " отправлен на строительство." << endl;
				DEQ.pop_back();
			}
		}break;
		case 5: {
			if (check(DEQ)) {
				queue<Property> que(DEQ);
				cout<<"Первый объект из очереди: "<<que.front().getName()<< " отправлен на строительство." << endl;
				DEQ.pop_front();
			}
		}break;
		case 6: {			
			if (check(DEQ)) {
				priority_queue<Property, vector<Property>,
					less<vector<Property>::value_type>> pr_deq;
				for (auto it : DEQ)
					pr_deq.push(Property(it.getName(), it.getPriority()));

				cout << "Объект с наибольшим приоритетным числом: " << pr_deq.top().priority << " отправлен на строительство." << endl;
				DEQ.pop_front();
			}
		}break;
		case 7: {
			if (!DEQ.empty()) {
				int count = 1;
				cout << " ____________________________________" << endl;
				for (auto it : DEQ) {
					cout << "|"<<setw(5)<<count<<"|"<<setw(30)<< it.getName()<<"|" << endl;
					cout << "|_____|______________________________|" << endl;
					count++;
				}
			}
			else
				cout << "Очередь пуста" << endl;
		}break;
		}

	}
}

bool check(deque<Property> deq) {
	if (deq.empty()) {
		cout << "Очередь пуста" << endl;
		system("pause");
		system("cls");
		return false;
	}
	else return true;
};