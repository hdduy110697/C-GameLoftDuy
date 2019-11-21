#include <iostream>
#include <string>
#include <list>
#include <fstream>


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
	cout << "score :" << student.score <<"\n"<< endl;
};

void DisplayList(list<Student> listStudent)
{
	list<Student>::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); it++) {
		Display(*it);
	}
};

bool CheckIdStudent(list<Student> listStudent, int id) {
	list<Student>::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); it++) {
		if ((it->id) == id)
		{
			return true;
		}
	}
	return false;
}

void SaveToFile(list<Student> listStudent) {
	ofstream outfile("ListStudent.txt");
	list<Student>::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); it++) {
		outfile << it->id << endl;
		outfile << it->name << endl;
		outfile << it->score << "\n" << endl;
	}
}

Student* InputStudent(list<Student> listStudent) {
	Student* student = new Student();
	bool check = true;
	do
	{
		cout << "Input Id :" << endl;
		int id;
		cin >> id;
		check = CheckIdStudent(listStudent, id);
		if (check) {
			cout << "id is already have input again" << endl;
		}
		else
		{
			student->id = id;
		}
	} while (check == true);
	cout << "Input Name :" << endl;
	cin >> student->name;
	float score;
	bool checkScore = false;
	do
	{
		cout << "Input Score :" << endl;
		cin >> score;
		if (score < 0 || score>10)
		{
			checkScore = true;
			cout << "faise score innput again" << endl;
		}
		else
		{
			checkScore = false;
			student->score = score;
		}
	} while (checkScore == true);

	return student;
}

// load from file then put value into list student 
void LoadFromFile(list<Student> &listStudent) {
	//load file
	string read;
	ifstream inFile;
	list<Student> listLoad;
	inFile.open("ListStudent.txt");
	cout << "\n===========================\n";
	cout << "Read file!" << endl;
	// count =1 is row Id, count =2 is row name , count =3 is row score
	int count = 1;
	string line;
	Student* studentTemp = new Student();
	while (!inFile.eof()) {
		char temp[255];
		inFile.getline(temp, 255);
		line = temp;
		if (line!="")
		{				
			switch (count)
			{
			case 1:
			{
				studentTemp->id = atoi(line.c_str());
				count++;
				break;
			}
			case 2:
			{
				studentTemp->name = line;
				count++;
				break;
			}
			case 3:
			{

				studentTemp->score = atoi(line.c_str());
				// avoid clicking load file multiple times -> put many same students into list 
				if (!CheckIdStudent(listStudent, studentTemp->id))
				{
					listStudent.push_back(*studentTemp);
				}				
				count++;
				break;
			}
			}
		}
		else
		{
			count = 1;
			continue;
		}

	}


}

void main()
{
	list<Student> listStudent;
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
			listStudent.push_back(*InputStudent(listStudent));
			break;
		}
		case 2:
		{
			DisplayList(listStudent);
			break;
		}
		case 3:
		{

			SaveToFile(listStudent);
			break;
		}
		case 4:
		{
			LoadFromFile(listStudent);
			break;
		}
		case 0:
		{
			stopMenu = true;
			break;
		}
		}
	} while (!stopMenu == true);


}
