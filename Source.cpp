#include <iostream>

class Student
{
private: // it's standard to keep things like variables private
	int* grades;
	int size;
	double averageGrade;

public: /* functions here */
	Student(); // constructor
	Student(int s); // this is not used; it's soley to give an example of function overloading
	void getSize(); // asks user for the size of the array
	void getGrades(); // fills grades with values from the user
	void getAverageGrade();
	void printGrades();
	~Student(); // destructor for Student (executes when the instance of Student dies)
};

int main()
{
	Student s; // this is where the default constructor is called

	s.getSize();
	s.getGrades();
	s.getAverageGrade();
	s.printGrades();

	std::cin.get(); // used to pause the console without "System("pause")"
}

Student::Student()
	: size(0), averageGrade(0.0), grades(nullptr) // member initializer list
{
	// what I want to be done when an instance of Student has been created
}

/*
	overloading a function is when you create another function of the same name
	with different parameters
*/

Student::Student(int s) // overloaded constructor 
	: size(s), averageGrade(0.0), grades(nullptr)
{
	std::cout << "Inside overloaded constructor.\n\n";
}

void Student::getSize()
{
	std::cout << "Enter amount of grades: ";

	// this function has access to size because it is apart of the Student class
	std::cin >> size;
	grades = new int[size];
}

void Student::getGrades()
{
	std::cout << "Enter grades: \n";

	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		std::cin >> *(grades + i);
	}
	std::cout << std::endl;
}

void Student::getAverageGrade()
{
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += *(grades + i);

	averageGrade = (double)sum / (double)size; // have to cast sum and size to double to prevent integer truncating
}

void Student::printGrades()
{
	std::cout << "Grades: ";
	for (int i = 0; i < size; i++)
	{
		if (i < size - 1) // this is just to print commas only till the last number
			std::cout << *(grades + i) << ", ";
		else
			std::cout << *(grades + i);
	}
	std::cout << "\nAverage: " << averageGrade << std::endl;
}

Student::~Student()
{
	delete[] grades;
}