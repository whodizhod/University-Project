#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class CStudent{

private:

	string m_name;		
	string m_number;	
	string m_gender;	
	double m_average;	

public:

	CStudent(){
		m_name = "NULL";
		m_number = "NULL";
		m_gender = "NULL";
		m_average = 0;
	}

	CStudent(string name, string number, string gender ,double average ){
		m_name = name;
		m_number = number;
		m_gender = gender;
		m_average = average;
	}

	~CStudent(){
		
	}

	void setName(string name){
		m_name = name;
	}

	string getName(){
		return m_name;
	}

	void setNumber(string number){
		m_number = number;
	}

	string getNumber(){
		return m_number;
	}

	void setGender(string gender){
		m_gender = gender;
	}

	string getGender(){
		return m_gender;
	}

	void setAverage(double average){
		m_average = average;
	}

	double getAverage(){
		return m_average;
	}

	void printStudent(int i){	
		cout<<i<<". Student name: "<<m_name<<endl;
		cout<<"   Faculty number: "<<m_number<<endl;
		cout<<"   Gender: "<<m_gender<<endl;
		cout<<"   Average grade: "<<m_average<<endl<<endl;
	}

};

void printVector(list<CStudent>StudentInfo){



	if(StudentInfo.empty())
	
		cout<<"There are no students."<<endl<<endl;
	
	else
		
		for(unsigned i = 0; i < StudentInfo.size(); i++){
			list<CStudent>::iterator it;
			it = StudentInfo.begin();
			advance(it, i);
			it->printStudent(i);
		}
}

bool sortByName(CStudent left, CStudent right){
	return left.getName()<right.getName();
}

bool sortByAverage(CStudent left, CStudent right){
	return left.getAverage()<right.getAverage();
}

int main(){

	//Setup
	list <CStudent> StudentInfo;
	list <CStudent> Failed;
	list <CStudent> Succeeded;

	//Student examples
	CStudent student1("Chloe", "17621301", "Female", 6.00);
	CStudent student2("Demi", "17621302", "Female", 4.90);
	CStudent student3("Abraham", "17621303", "Male", 2.99);
	CStudent student4("George", "17621304", "Male", 2.10);
	CStudent student5("Christian", "17621305", "Male", 3.90);
	CStudent student6("Alphonse", "17621306", "Male", 5.70);
	CStudent student7("Daniel", "17621307", "Male", 4.20);
	CStudent student8("TEST", "TEST", "TEST", 2);

	StudentInfo.push_back(student1);
	StudentInfo.push_back(student2);
	StudentInfo.push_back(student3);
	StudentInfo.push_back(student4);
	StudentInfo.push_back(student5);
	StudentInfo.push_back(student6);
	StudentInfo.push_back(student7);
	StudentInfo.push_back(student8);

	//Menu
	int choice;

	do{
		system("cls");
		cout<<endl;

		cout<<" 1 - Add Student."<<endl;
		cout<<" 2 - Delete Student."<<endl;
		cout<<" 3 - Sort Student."<<endl;
		cout<<" 4 - Max. and min. grades"<<endl;
		cout<<" 5 - Average grade of all students"<<endl;
		cout<<" 6 - Divide students with grade 2 - 1st way"<<endl;
		cout<<" 7 - Divide students with grade 2 - 2nd way"<<endl;
		cout<<" 8 - Print StudentInfo."<<endl<<endl;
		cout<<" 9 - Exit."<<endl<<endl;
		cout<<" Enter your choice and press enter: ";
		
		cin >> choice;
		cout<<endl;
		
		switch (choice)
		{

			case 1:
			{
				system("cls");
				string name;
				string number;
				string gender;
				double average;
				cout<<"Student name: ";
				cin>>name;
				cout<<"Faculty number: ";
				cin>>number;
				cout<<"Gender: ";
				cin>>gender;
				cout<<"Average grade: ";
				cin>>average;
				cout<<endl;
				CStudent student(name ,number ,gender,average ); 
				StudentInfo.push_back(student);
				cout<<"Students added successfully!"<<endl;
				system("pause");
				break;
			}

			case 2:
			{
				int input = 0;
				do{
					system("cls");
					printVector(StudentInfo);
					cout<<endl<<endl<<"Press the number of student you want to remove and press enter!"<<endl;
					cout<<endl<<endl<<"Or type a negative number and enter to return to the main menu! : ";
					cin>>input;
					if(input>=0){

					list<CStudent>::iterator it;
					it = StudentInfo.begin();
					advance (it,input); 
					StudentInfo.erase(it);

					}
					else break;
				}while(input>=0);
				break;
			}

			case 3:	
			{
				system("cls");
				StudentInfo.sort(StudentInfo.begin(),StudentInfo.end(), sortByName()); 
				cout<<"Students sorted by name successfully!"<<endl<<endl;
				system("pause");
				break;
			}

			case 4:
			{
				system("cls");

				list<CStudent>::iterator first;
				first = StudentInfo.begin();

				list<CStudent>::iterator last;
				last = StudentInfo.begin();

				sort(StudentInfo.begin(), StudentInfo.end());	
				cout<<"Max.avg.grade: "<<last->getAverage()<<endl;
				cout<<"Min.avg.grade: "<<first->getAverage()<<endl;
				sort(StudentInfo.begin(), StudentInfo.end()); 
				system("pause");
				break;
			}

			case 5:
			{
				system("cls");	

				double sum = 0;
				
				for(unsigned i=0; i<StudentInfo.size(); i++){
					list<CStudent>::iterator it;
					it = StudentInfo.begin();
					advance(it, i);
					sum += it->getAverage();
				}

				cout<<"Average grade of all students: "<<sum/StudentInfo.size()<<endl<<endl;

				system("pause");
				break;
			}

			case 6:
			{
				system("cls");

				for(unsigned i=0; i<StudentInfo.size(); i++){

					list<CStudent>::iterator it;
					it = StudentInfo.begin();
					advance(it, i);

					if(it->getAverage()<3)
						Failed.push_back(*it);
					else
						Succeeded.push_back(*it);
				}

				cout<<"Failed students: "<<endl<<endl;
				printVector(Failed);
				
				cout<<endl<<endl;

				cout<<"Succeeded students: "<<endl<<endl;
				printVector(Succeeded);

				system("pause");
				break;
			}

			case 7:
			{
				system("cls");

				for(unsigned i=0; i<StudentInfo.size(); i++){

					list<CStudent>::iterator it;
					it = StudentInfo.begin();
					advance(it, i);

					if(it->getAverage()<3)
					{
						Failed.push_back(*it);
						StudentInfo.erase(it);
					}
				}

				cout<<"Failed students: "<<endl<<endl;
				printVector(Failed);
				
				cout<<endl<<endl;

				cout<<"StudentInfo: "<<endl<<endl;
				printVector(StudentInfo);

				system("pause");
				break;
			}

			case 8:
			{
				system("cls");
				printVector(StudentInfo);
				system("pause");
				break;
			}

			case 9:break;

			default:
			{
				system("cls");
				cout<<"Not a Valid Choice."<<endl;
				cout<<"Choose again!"<<endl;
				system("pause");
				break;
			}
		}
	

	}while (choice !=5);

	return 0;
}
