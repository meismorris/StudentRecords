#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;


/*****************************************************************************
 *
 * Student Records
 *_________________________________________________
 * This program takes an input file and returns the records of students in a specific class
 * Classes ranges from english, history, and math.
 * 
 *_________________________________________________
 * INPUT:
 *  string filename: input file's name
 *  string outfileName: output file's name
 *  string lastName: student's last name
 *  string firstName: student's first name
 *  string courseName: student's course name/class they are taking
 *  int firstGrade: first exam test score
 *  int secondGrade: second exam test score
 *  double finalGrade: final exam score
 *
 * OUTPUT:
 *  string tempName: A string consisting of first and last name.
 *  double finalGrade: final grade of student consisting of their test and exam scores
 *  double mathAvg: average of class grade in math class
 *  double histAvg: average of class grade in history class
 *  double engAvg: average of class grade in english class
 ******************************************************************************/


struct student 
{

   string lastName; // student's last name
   string firstName; // student's first name
   string courseName; // student's course name/class they are taking
   int firstGrade; // first exam test score
   int secondGrade; // second exam test score
   int thirdGrade; // second exam test score
   double finalGrade; // final exam score

};

// FUNCTION PROTOTYPES

/*****************************************************************************
 * selectCourse
 * This function prints out class name based on first letter
 *      -EX. M = MATH
 *****************************************************************************/
/*****************************************************************************
 * getGrade
 * returns letter grade based on percentage by asking for percentage grade
 *      -ex. 90 returns A
 *****************************************************************************/
/*****************************************************************************
 * displayUI
 * This function is to display the course gui based on class
 * asks for parameter course name:
 *          -returns parameter + Class
 *****************************************************************************/
/*****************************************************************************
 * displayClassAvg
 * Displays GUI of class average:
 * Takes argument average, count
 *        -returns class grade average and letter grade
 *****************************************************************************/

/*****************************************************************************
 * displayStu
 * This function is responsible for indivdually outputing the student's name and grade
 *	takes in name, and score,
 *****************************************************************************/

//Functions//

/*****************************************************************************
string selectCourse(string course) // course - takes selected course letter
 *________________________________________________
 * The function simplys determines class name based on letter
 *      -returns a course like "history"
 *________________________________________________
------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * string course;
 *
 * POST-CONDITIONS
 * This function will then return Math, English, or History based on letter.
****************************************************************************/

string selectCourse(string course)
{
  if (course == "M")
  {
    return "Math";
  }
  else if (course == "E") 
  {
    return "English";
  }
  else if (course == "H")
  {
    return "History";
  }
}

/*****************************************************************************
string getGrade(double percentage) // CALC - takes percentage of a grade and turns into letter
 *________________________________________________
 * The function simplys determines grade letter based on percentage given
 *      -returns a letter grade. EX: 90 -> A
 *________________________________________________
------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * string percentage;
 *
 * POST-CONDITIONS
 * This function will return a letter grade based on percentage student has.
****************************************************************************/

string getGrade(double percentage)
  {
    
     if (percentage > 90)
    {
      return "A";
    }
    else if (percentage < 90 && percentage > 80) 
    {
      return "B";
    }
    else if (percentage < 80 && percentage > 70) 
    {
      return "C";
    }
    else if (percentage < 80 && percentage > 70) 
    {
      return "C";
    }
    else if (percentage < 70 && percentage > 60)   
    {
      return "D";
    }
    else
    {
      return "F";
    }
    
  }

/*****************************************************************************
void displayUI(string course)// CALC - takes course and outputs the GUI
 *________________________________________________
 * The function simplys display the gui based on what class they are in
 *      - determines MATH CLASS if the argument was "MATH"
 *________________________________________________
------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * string course;
 *
 * POST-CONDITIONS
 * This function will return a GUI based on what class.
****************************************************************************/

void displayUI(string course)
{
  cout << course << " CLASS\n" << endl;
  cout.setf(ios::left,ios::adjustfield);
  cout << setw(37) << "Student Name";
  cout << setw(13) << "Test Avg     Grade" << endl;
  cout << "----------------------------------------------------------------\n";
}

/*****************************************************************************
*void displayClassAvg(double average, double count)//  OUTPUT - student average
 *                                                     output - student count
 *________________________________________________
 * The function displays the class average divided by count (amounts of student in each class) and letter grade
 *      - using function getGrade
 *________________________________________________
------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * double average;
 * double count;
 * POST-CONDITIONS
 * This function returns the class average divided by count, and a letter grade based on class average
****************************************************************************/

void displayClassAvg(double average, double count)
{
  cout.setf(ios::left);
  cout << setw(40) << "\nClass Average" << " " ;
  cout << setw(8) << average / count ;
  cout.unsetf(ios::left);
  cout << setw(5) << getGrade(average/count) << "\n";
  cout << "----------------------------------------------------------------\n";
}
/*****************************************************************************
 * void displayStu(string name, double score)//  OUTPUT - student name
 *                                               output - student score
 *________________________________________________
 * The function displays the students' name, grade, letter 
 *      based on parameter.
 *________________________________________________
------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * double score;
 * string name;
 * POST-CONDITIONS
 * Outputs students' name, score, lettergrade
****************************************************************************/

void displayStu(string name, double score)
{
  cout.setf(ios::left);
  cout << setw(40) << name;
  cout << setw(8) << score;
  cout.unsetf(ios::left);
  cout << setw(5) << getGrade(score) << "\n";

}
  
int main() {

  double engCount = 0; // CALC - keeps track of students in english
  double mathCount = 0; // CALC - keeps track of students in math
  double histCount = 0; // CALC - keeps track of students in history
  string tempFirst; // PLACEHOLDER for first test.
  string tempSecond; // PLACEHOLDER for second test.
  string tempFinal; // PLACEHOLDER for final test.
  string tempName; // used as an argument for function 
  string fileName; 
  string outfileName;
  double finalGrade = 0; //OUTPUT/CALC  - Final Grade of Student
  double mathAvg = 0; //OUTPUT/CALC  - Final Math Grade of Class
  double engAvg = 0; //OUTPUT/CALC  - Final English Grade of Class
  double histAvg = 0; //OUTPUT/CALC  - Final History Grade of Class
  
  cout << fixed;
  cout << setprecision(2);
  
  ifstream iFile;
  ofstream oFile;
  student *sptr;
  int size;

  while(true)
    {
      cout << "Please enter the name of the input file." << endl << "Filename: ";
      cin >> fileName;
      if (fileName == "test1.txt" || fileName == "test2.txt")
      {
          cout << "\nPlease enter the name of the output file." << endl << "Filename: ";
          cin >> outfileName;
          iFile.open(fileName);
          oFile.open(outfileName);
          break;
      }
    }

 
  cout << "Processing Complete\n" << endl;
  cout << "Student Grade Summary\n";
  cout << "---------------------\n" << endl << endl;
  

  iFile >> size;
  iFile.ignore(1000, '\n');
  
  sptr = new student[size];

  int i = 0;

  while(iFile && i < size)
  
  {

    getline(iFile, sptr[i].lastName, ',');
    getline(iFile, sptr[i].firstName, ','); 
    getline(iFile,sptr[i].courseName,',');
    getline(iFile,tempFirst,',');
    getline(iFile,tempSecond,',');
    getline(iFile,tempFinal);
  
    string first = sptr[i].firstName;
    string last = sptr[i].lastName;
    string name = sptr[i].lastName + ", " + sptr[i].firstName ;
    string course = selectCourse(sptr[i].courseName);
    int num;

    sptr[i].firstGrade = stoi(tempFirst);
    sptr[i].secondGrade = stoi(tempSecond);
    sptr[i].thirdGrade = stoi(tempFinal);
    finalGrade += (sptr[i].firstGrade * 0.30 + sptr[i].secondGrade * 0.30 + sptr[i].thirdGrade * 0.40);
  
    i++;
    finalGrade = 0;
  }
    


   displayUI("ENGLISH");
      for(int i = 0; i < size;i++)
    {
      if(sptr[i].courseName == "E") // IF student course == English
      {
        finalGrade += (sptr[i].firstGrade * 0.30 + sptr[i].secondGrade * 0.30 + sptr[i].thirdGrade * 0.40);
        tempName = sptr[i].lastName + ", " + sptr[i].firstName;
        displayStu(tempName, finalGrade);
        engAvg += finalGrade;
        finalGrade = 0;
        engCount+=1; //Keeps track of how many students are in class
      }
    }
    
    displayClassAvg(engAvg, engCount);

  displayUI("HISTORY");
    for(int i = 0; i < size;i++)
    {
      if(sptr[i].courseName == "H") // IF student course == History
      {
        finalGrade += (sptr[i].firstGrade * 0.30 + sptr[i].secondGrade * 0.30 + sptr[i].thirdGrade * 0.40);
        tempName = sptr[i].lastName + ", " + sptr[i].firstName;
        displayStu(tempName, finalGrade);
        histAvg += finalGrade;
        finalGrade = 0;
        histCount+=1;  //Keeps track of how many students are in class
      }
    }
     displayClassAvg(histAvg, histCount);
  
  displayUI("MATH");
  for(int i = 0; i < size;i++)
    {
      if(sptr[i].courseName == "M") // IF student course == Math
      {
        finalGrade += (sptr[i].firstGrade * 0.30 + sptr[i].secondGrade * 0.30 + sptr[i].thirdGrade * 0.40);
        tempName = sptr[i].lastName + ", " + sptr[i].firstName;
        displayStu(tempName, finalGrade);    
        mathAvg += finalGrade;
        finalGrade = 0;
        mathCount+=1;  //Keeps track of how many students are in class
      }
    }
      displayClassAvg(mathAvg, mathCount);

  
  iFile.close();
  oFile.close();
    
}



  
