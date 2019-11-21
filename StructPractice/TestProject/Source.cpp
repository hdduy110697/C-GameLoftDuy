#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Student
{
	int  id;
	string  name;
	float  score;
};

void Display(Student student)
{
	cout << "Id :" << student.id << endl;
	cout << "Name :" << student.name << endl;
	cout << "score :" << student.score << endl;
};
void DisplayList(list<Student> listStudent)
{
	list<Student>::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); it++) {
		Display(*it);
	}
};
Student InputStudent() {
	Student student;
	cout << "Input Id :" << endl;
	cin >> student.id;
	cout << "Input Name :" << endl;
	cin >> student.name;
	cout << "Input Score :" << endl;
	cin >> student.score;
	return student;
}
void main()
{
	Student student1;
	student1.name = "duy";
	student1.id = 1;
	student1.score = 7;

	Student student2;
	student2.id = 2;
	student2.name = "nin";
	student2.score = 9;

	list<Student> listStudent;
	listStudent.push_back(student1);
	listStudent.push_back(student2);
	DisplayList(listStudent);

	bool stopMenu = false;
	int choise = 0;
	do {
		cout << "----------------------------------Menu-------------------------------------" << endl;
		cout << "1. Input" << endl;
		cout << "2.Display" << endl;
		cout << "3.Save to file" << endl;
		cout << "4.Load from file" << endl;
		cout << "0.Exit" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			listStudent.push_back(InputStudent());
			break;
		}
		case 2:
		{
			DisplayList(listStudent);
			break;
		}
		//case 3:
		//{
		//	Statements;
		//	break;
		//}
		//case 4:
		//{
		//	Statements;
		//	break;
		//}
		//case 0:
		//{
		//	Statements;
		//	break;
		//}
		}
	} while (!stopMenu == true);


}
