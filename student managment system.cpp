//Seyed Aman Zargari
//9811910045

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct student
{
	long int snum;
	string name;
	string lname;
	float mark;
} s[255], tnm;

void mainlist(student, int td);
bool sv(long int s, student, int t);
///////////////////////////////////// import danshjo


int importdanshjo(student)
{
	student aa;
	int t = 0, x = 1, ttdanshjo, yu = 0;
	float checksscore;
	cout << "Students number : "; cin >> ttdanshjo;
	for (t = 0; t < ttdanshjo; t++)
	{
		cout << endl << "***************************" << endl << "Student number " << t+1 << endl;
		cout << "Firt Name : "; cin >> s[t].name;
		cout << "Last Name : "; cin >> s[t].lname;
		
		do{
			yu++;
			if (yu >= 2) {
				cout << "Student ID is Exist ! ! ! ";
			}
			cout << "Student number : "; cin >> s[t].snum;
		} while (!sv(s[t].snum, aa, t));
		
		while (1) {
			cout << "Score (0 - 20): "; cin >> checksscore;
			if ( checksscore > 20) {
				cout << endl << "Wrong input ! (0 - 20)" << endl << endl;
			}
			else if (checksscore < 0 ) {
				cout << endl << "Wrong input ! (0 - 20)" << endl << endl;
			}
			else {
				s[t].mark = checksscore;
				break;
			}
		}
	}
	Sleep(500);
	return ttdanshjo;
}

bool sv(long int s, student, int t) {
	int i = 0;
	long int snum[255];
	//for (i = 0; i < t; i++) { snum[i] = s[i].snum; }
	for (int i = 0; i < t; i++)
	{
		if (snum[i] == s) { return false; }
	}
	return true;
}
/////////////////////////               student list full  1

void studentlist(student, int td) {
	student aa;
	string back;
	int i;
	system("cls");

	cout << "-------------------------- Students List ---------------------------------------" << endl << endl;
	cout << "   First name        " << "Last name       " << "Mark       " << "Student number     " << endl << endl;
	for (i = 0; i < td; i++) {
		cout << i+1 << " )      " << s[i].name << "               " << s[i].lname << "            " << s[i].mark << "          " << s[i].snum << endl
			<< "   *****************************************************************************************" << endl;

	}
	cout << "continue ??(y , n) "; cin >> back;
	if (back == "n" or back == "N") {
		system("exit");
	}
	else if (back == "y" or back == "Y") { mainlist(aa, td); }
	else
		studentlist(aa, td);
}

////////////////////////////////////           gpa full   2

void gpa(student, int td) {
	int i;
	system("cls");
	student aa;
	string back;
	float sum = 0;
	for (i = 0; i <= td; i++) {
		sum = sum + s[i].mark;
	}
	cout << endl << endl << endl << "Grade Point Average : " << sum / td << endl << endl << endl;
	cout << "Continue ??(y , n) "; cin >> back;
	if (back == "n" or back == "N") {
		system("exit");
	}
	else if (back == "y" or back == "Y") { mainlist(aa, td); }
	else
		gpa(aa, td);

}

///////////////////////////////////////////      highest score full     3

void highestscore(student, int td) {
	student aa;
	system("cls");
	string back;
	int i, t, j;
	float sum = 0, mark[255], highest = 0;
	for (i = 0; i <= td; i++) {mark[i] = s[i].mark ;}
	for (i = 0; i <= td; i++)
	{
		sum += mark[i];
		if (mark[i] > highest)
			highest = mark[i];
	}
	cout << "-------------------------- Highest scores students---------------------------------------" << endl << endl;
	cout << "   First name        " << "Last name       " << "Mark       " << "Student number     " << endl << endl;
	
	for (i = 0; i <= td; i++) {
		if (s[i].mark == highest) {
			cout << " )      " << s[i].name << "               " << s[i].lname << "            " << s[i].mark << "          " << s[i].snum << endl
				<< "   *****************************************************************************************" << endl;
		}
	}

	cout << endl << "Continue ??(y , n) "; cin >> back;
	if (back == "n" or back == "N") {
		system("exit");
	}
	else if (back == "y" or back == "Y") { mainlist(aa, td); }
	else
		highestscore(aa, td);
}

/////////////////////////////////////////////     rejecteds full       4

void rejecteds(student, int td) {
	int i;
	student aa;
	string back;
	system("cls");
	cout << endl << endl << "       Rejecteds      " << endl;
	for (i = 0; i < td; i++) {
		if (s[i].mark < 10) {
			cout << "   " << s[i].snum << "  # " << s[i].name << " " << s[i].lname << " -  Mark : " << s[i].mark << endl;
		}
	}
	cout << endl << "Continue ??(y , n) "; cin >> back;
	if (back == "n" or back == "N") {
		system("exit");
	}
	else if (back == "y" or back == "Y") { mainlist(aa, td); }
	else
		rejecteds(aa, td);
}

//////////////////////////////////////////        search full          5


void search(student, int td) {
	student aa;
	system("cls");
	long int sstudentnumber;
	cout << "Enter Student number : "; cin >> sstudentnumber;
	string back;
	int i, n = 0;
	for (i = 0; i <= td; i++) {
		if (s[i].snum == sstudentnumber) {
			cout << endl;
			cout << "Firt Name : "; cout << s[i].name << endl;
			cout << "Last Name : "; cout << s[i].lname << endl;
			cout << "Student number : "; cout << s[i].snum << endl;
			cout << "Score : "; cout << s[i].mark << endl;
			cout << "*****************" << endl;
			n = 1;
			break;
		}
	}

	Sleep(500);
	if (n == 1) {
		cout << endl << "Continue ??(y , n) "; cin >> back;
		if (back == "n" or back == "N") {
			system("exit");
		}
		else if (back == "y" or back == "Y") { mainlist(aa, td); }
		else
			search(aa, td);
	}
}

///////////////////////////////////             sort full              6 

void sort(student, int td) {
	student aa;
	system("cls");
	int i, j;
	string back;
	for (i = 0; i <= td; i++)
	{
		for (j = 0; j <= td - 1; j++)
		{
			if (s[j].mark < s[j + 1].mark)
			{
				tnm = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tnm;
			}
		}
	}
	studentlist(aa, td);
}

///////////////////////////////////////////       round full         7

void round(student, int td) {
	system("cls");
	student aa;
	string back;
	int i, ch;
	cout << " You want save marks in list or save and show?" << endl << "{1 . save and show}" << endl << "{2 . just save}" << endl << endl << endl << "      ::::   ";
	cin >> ch;
	if (ch == 1) {
		for (i = 0; i <= td; i++) {
			s[i].mark = ceil(s[i].mark);
		}
		studentlist(aa, td);
	}
	else if (ch == 2) {
		for (i = 0; i <= td; i++) {
			s[i].mark = ceil(s[i].mark);
		}
		cout << "          Saved !" << endl;
	}
	else {
		round(aa, td);
	}
	cout << endl << "Continue ??(y , n) "; cin >> back;
	if (back == "n" or back == "N") {
		system("exit");
	}
	else if (back == "y" or back == "Y") { mainlist(aa, td); }
	else
		round(aa, td);

}

//////////////////////////////////////////          shift full          8

void shift(student, int td) {
	system("cls");
	int i;
	string back;
	
	student aa;
	for (i = 0; i <= td; i++) {
		
		if (s[i].mark > 19 && s[i].mark <= 20) {
			s[i].mark = 20;
		}

		else if (s[i].mark >= 10) {
			s[i].mark++;
		}

		else if (8 <= s[i].mark) {
			s[i].mark = 10;
		}
		else if (s[i].mark < 8) {
			s[i].mark = 9.9;
		}
		else {
			s[i].mark = 9.9;
		}
	}
	studentlist(aa, td);
}

/////////////////////////////////////////          edit full            9

void edit(student, int td) {
	student aa;
	system("cls");
	long int sstudentnumber;
	cout << "Enter Student number : "; cin >> sstudentnumber;
	float checksscore;
	int i;
	string back;
	for (i = 0; i <= td; i++) {
		if (s[i].snum == sstudentnumber) {
			cout << endl;
			cout << "Enter new Firt Name : "; cout << s[i].name << " => "; cin >> s[i].name;
			cout << "Enter new Last Name : "; cout << s[i].lname << " => "; cin >> s[i].lname;
			cout << "Enter new Student number : "; cout << s[i].snum << " => "; cin >> s[i].snum;
			cout << "Enter new Score (0-20) : "; cout << s[i].mark << " => "; cin >> checksscore;
			while (1) {
				cout << "Score (0 - 20): "; cin >> checksscore;
				if (checksscore > 20) {
					cout << endl << "Wrong input ! (0 - 20)" << endl << endl;
				}
				else if (checksscore < 0) {
					cout << endl << "Wrong input ! (0 - 20)" << endl << endl;
				}
				else {
					s[i].mark = checksscore;
					break;
				}
			}
		}
	}
	cout << endl << "Continue ??(y , n) "; cin >> back;
	if (back == "n" or back == "N") {
		system("exit");
	}
	else if (back == "y" or back == "Y") { mainlist(aa, td); }
	else
		edit(aa, td);
}

///////////////////////////////////////////// chmainlist 

void chmainlist(student, int td)
{
	student ss;
	string ex = "n";
	int ch;
	cin >> ch;
	switch (ch) {
	case 1:
		studentlist(ss, td); break;
	case 2:
		gpa(ss, td); break;
	case 3:
		highestscore(ss, td); break;
	case 4:
		rejecteds(ss, td); break;
	case 5:
		search(ss, td); break;
	case 6:
		sort(ss, td); break;
	case 7:
		round(ss, td); break;
	case 8:
		shift(ss, td); break;
	case 9:
		edit(ss, td); break;
	case 0:
		cout <<endl<<endl<< "Are you sure you want to Exit?! (y,n)  "; cin >> ex;
		if (ex == "y" or ex == "Y") {
			exit(0);
		}
		else {
			system("cls");
			mainlist(ss, td);
		}
	default:
		mainlist(ss, td); break;
	}
}

//////////////////////////////////////////        mainlist

void mainlist(student, int td)
{
	student ss;
	system("cls");
	cout << "+++ Student Managment System +++" << endl <<
		"1) Students list " << endl <<
		"2) GPA " << endl <<
		"3) Highest scores" << endl <<
		"4) Rejecteds" << endl <<
		"5) Search" << endl <<
		"6) Sort" << endl <<
		"7) Round the scores" << endl <<
		"8) Shift scores" << endl <<
		"9) Edit" << endl <<
		"0) Exit" << endl << endl << endl <<
		"Enter your choose (just number) =>  ";
	chmainlist(ss, td);
}

////////////////////////////////////           main

void main(student)
{
	int td;
	student ss;
	td = importdanshjo(ss);
	system("cls");
	mainlist(ss, td);
}