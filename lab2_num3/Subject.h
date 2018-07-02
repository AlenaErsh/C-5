#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#pragma once
using namespace std;
enum viewSub { credit, exam };
enum courseWork { Y, N };
struct Subject
{
	int CodeSub, CodeGroup, NubmStudent, NumbHourLe, NumbHourPr;
	string SurnameTeach, NameSub;
	courseWork CourseWork;
	viewSub  ViewSub;

};

bool SurnameRecComp(Subject, Subject);
bool CodeGroupRecComp(Subject, Subject);
bool CourseWorkRecComp(Subject, Subject);
bool ViewRecComp(Subject, Subject);

//��������� ������ � ����������� ���������
bool SurnameComp(Subject, string);
bool CodeGroupComp(Subject, int);
bool CourseWorkComp(Subject, courseWork);
bool ViewComp(Subject, viewSub);

//����������� ���������
//��� ������� ����� ������� ��������� ������ � ����� ������ ����� � �������� � ���
bool equalsSurname(Subject, string);
bool equalsCodeGroup(Subject, int);
bool equalsCourseWork(Subject, courseWork);
bool equalsViewSub(Subject, viewSub);

