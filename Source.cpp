#include <iostream>

using namespace std;

//Write a program which allows the user to decide how big of an array he wants to make(use new command).Then, access the array using pointer arithmetic(not []).Allow him to enter student grades to the array.Then print the array contents.Print the average grade.Do this by writing separate function such as printArrayand calculateAverage.In these functions you will pass the array as a parameter(i.e. using*).

// changes are being made to the file..

// adding another change

struct Student
{
	int* gradesArray = nullptr;
	int size{};
	double averageGrade{};
	//int count = 0;
};

int getSizeOfArray(Student* temp)
{
	cout << "Enter size of array: ";
	cin >> temp->size;
	return temp->size;
}

void enterGrades(Student* temp)
{
	///*int * tempArray= new int[temp->count+1];

	//for (int i = 0; i < temp->count; i++)
	//{
	//	tempArray[i] = temp->gradesArray[i];
	//}
	//delete[] temp->gradesArray;*/

	//temp->gradesArray = tempArray;

	temp->gradesArray = new int[temp->size];

	for (int i = 0; i < temp->size; i++)
	{
		cout << "Enter grade #" << i + 1 << ": ";
		cin >> *(temp->gradesArray+i);
	}

}

void printGradeArray(Student temp)
{
	cout << "Here are your " << temp.size << " total grades: ";
	for (int i = 0; i < temp.size; i++)
	{
		cout << *(temp.gradesArray+i);

		if (i == temp.size - 1)
		{
			cout << " ";
			break;
		}
		else
		{
			cout << ", ";
		}
	}
	cout << endl;
}

int getAverageGrade(Student* temp)
{
	int gradeSum = 0;

	for (int i = 0; i < temp->size; i++)
	{
		gradeSum = gradeSum + *(temp->gradesArray+i);
								//temp->gradesArray[i]
	}

	cout << "Your average Grade is: ";

	temp->averageGrade = (gradeSum * 1.0) / temp->size;


	cout << temp->averageGrade;

	return temp->averageGrade;
}

void main()
{
	Student temp;

	temp.size = getSizeOfArray(&temp); //get size of array from student input

	enterGrades(&temp);

	printGradeArray(temp);
	getAverageGrade(&temp);
	delete[] temp.gradesArray;

}