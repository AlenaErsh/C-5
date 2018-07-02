//---------------------------------------------------------------------------
/*������ � ������������� ���������� �������������� ����������: ��� ����������,
������������ ����������, ������� �������������, ��� ������, ����������
��������� � ������, ���������� ����� ������, ���������� ����� ��������, �������
�������� ������, ��� ��������� �������� (����� ��� �������). ����� � 0.35� ��
��������, ������� � 0.5� �� ��������. ����� �� ������� �������������, ����
������, ������� ��������, ���� ��������� ��������.*/

/*3 - �������� ����, ����������... */
/*�������� �� ������  + */

#include "stdafx.h"
#include "Subject.h"

//---------------------------------------------------------------------------
using namespace std;


int rightInput(int down, int up)
{
	int num;
	bool ok;
	do
	{
		cin >> num;
		ok = (num >= down) && (num <= up);
		if (!ok)
			cout << "������������ ����. ��������� �������" << endl;
	} while (!ok);
	return num;
}
viewSub ChoiseControl() {/*�������� default return +*/
	int choise;
	cout << "1) �����" << endl;
	cout << "2) �������" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
	default: return credit; break;
	case 2: return exam; break;
	}
}

courseWork CourseWork() {/*�������� default return +*/
	int choise;
	cout << "1) ����" << endl;
	cout << "2) ���" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1: return Y; break;
	case 2: 
	default: return N; break;
	}
}

Subject inputRecord()
{
	Subject sub;
	cout << "������� ��� ����������:" << endl;
	cin >> sub.CodeSub;
	cout << "������� �������� ����������:" << endl;
	cin >> sub.NameSub;
	cout << "������� ������� �������������: " << endl;
	cin >> sub.SurnameTeach;
	cout << "������� ��� ������:" << endl;
	cin >> sub.CodeGroup;
	cout << "������� ���������� ��������� � ������:"<<endl;
	cin >> sub.NubmStudent;
	cout << "������� ���������� ����� ������: " << endl;
	cin >> sub.NumbHourLe;
	cout << "������� ���������� ����� ��������:" << endl;
	cin >> sub.NumbHourPr;
	cout << "������� �������� ������:" << endl;
	sub.CourseWork = CourseWork();
	cout << "������� ��� ��������� ��������:" << endl;
	sub.ViewSub = ChoiseControl();
	return sub;
}

void addRecord(vector <Subject>& temp)
{
	Subject sub;
	sub = inputRecord();
	temp.push_back(sub);
}

void deleteRecord(vector <Subject>& temp)
{
	if (temp.size() == 0)
	{
		cout << "������� ���� ���" << endl;
		return;
	}
	cout << "������� ����� ������, ������� ������ �� �������: " << endl;
	int num = rightInput(1, temp.size());

	//��������
	auto it = temp.begin();
	advance(it, num-1);
	temp.erase(it);
}

void changeRecord(vector <Subject>& temp)
{
	if (temp.size() == 0)
	{
		cout << "������� ���� ���" << endl;
		return;
	}
	cout << "������� ����� ������, ������� ������ �� ��������: " << endl;
	int num = rightInput(1, temp.size());
	cout << "������� ����� ������ ��� ������" << endl;
	Subject sub = inputRecord();

	auto it = temp.begin();
	advance(it, num-1);
	*it = sub;
}

void printCourseWork(courseWork *CW) {
	if (*CW == Y)
		cout << "Yes" << endl;
	else if (*CW == N)
		cout << "No" << endl;
}
void printView(viewSub *VS) {
	if (*VS == credit)
		cout << "Credit" << endl;
	else if (*VS == exam)
		cout << "Exam" << endl;
}
ostream& operator<< (ostream& os, Subject sub)
{
	os << "������� �������������:  " << sub.SurnameTeach << endl
		<< "��� ����������:  " << sub.CodeSub << endl
		<< "������������ ����������: " << sub.NameSub << endl
		<< "��� ������: " << sub.CodeGroup << endl
		<< "���������� ��������� � ������: " << sub.NubmStudent << endl
		<< "���������� ����� ������:  " << sub.NumbHourLe << endl
		<< "���������� ����� ��������:  " << sub.NumbHourPr << endl;
	cout << "������� ��������:  ";
	printCourseWork(&sub.CourseWork);
	cout << "��� ��������� ��������:  ";
	printView(&sub.ViewSub);
	cout<< "-------------------------------------------------" << endl;
	return os;
}

void printBase(vector <Subject>& base)
{
	Subject elem;
	if (base.size() == 0)
		cout << "������� �������� ���" << endl;
	else
		for (auto pos = base.begin(); pos != base.end(); ++pos)
		{
			elem = *pos;
			cout << elem;
		}
}

Subject helpFind(int& num)
{
	cout << "�� ������ �������� �� ������ ������������ �����?" << endl
		<< "1 - ������� �������������" << endl
		<< "2 - ��� ������" << endl
		<< "3 - ������� ��������" << endl
		<< "4 - ��� ��������� ��������" << endl;
	num = rightInput(1, 4);
	Subject sub;
	switch (num)
	{
	case 1:
	{
		cout << "������� ������� �������������: " << endl;
		cin >> sub.SurnameTeach;
		break;
	}
	case 2:
	{
		cout << "������� ��� ������: " << endl;
		cin >> sub.CodeGroup;
		break;
	}
	case 3:
	{
		cout << "������� �������� ������ :" << endl;
		sub.CourseWork = CourseWork();
		break;
	}
	case 4:
	{
		cout << "������� ��� ��������� ��������" << endl;
		sub.ViewSub = ChoiseControl();
		break;
	}
	}
	return sub;
}
// ��������� ���������������� �����
vector<Subject> find�onsistently(vector <Subject>& temp)
{
	vector<Subject> choise;
	int num;
	bool ok = false;
	Subject sub = helpFind(num);	
	for (auto pos = temp.begin(); pos != temp.end(); ++pos)
	{
		Subject elem=*pos;
		switch (num)
		{
		case 1:
		{
			if (elem.SurnameTeach == sub.SurnameTeach)
				choise.push_back(elem);
			break;
		}
		case 2:
		{
			if (elem.CodeGroup == sub.CodeGroup)
				choise.push_back(elem);
			break;
		}
		case 3:
		{
			if (elem.CourseWork == sub.CourseWork)
				choise.push_back(elem);
			break;
		}
		case 4:
		{
			if (elem.ViewSub == sub.ViewSub)
				choise.push_back(elem);
			break;
		}
		}
	}
	return choise;
}


#pragma region �������� ����� 
// ��������� �������� �����
vector<Subject> binSurname(vector<Subject> &v, bool(*comparator_rec)(Subject, Subject),
	bool(*comparator)(Subject ,string), bool(*equals)(Subject, string)) {
	vector<Subject> results;
	vector<Subject>::iterator v_it = v.begin();
	string strquery;
	cin >> strquery;
	sort(v.begin(), v.end(), comparator_rec);
	v_it = lower_bound(v.begin(), v.end(), strquery, comparator);
	while ((v_it != v.end()) && equals(*v_it, strquery) ) {
		results.insert(results.end(), *v_it);
		++v_it;
	}
	return results;
}
vector<Subject> binCodeGroup(vector<Subject> &v, bool(*comparator_rec)(Subject, Subject),
	bool(*comparator)(Subject, int), bool(*equals)(Subject, int)) {
	vector<Subject> results;
	vector<Subject>::iterator v_it = v.begin();
	int intquery;
	cin >> intquery;
	sort(v.begin(), v.end(), comparator_rec);
	v_it = lower_bound(v.begin(), v.end(), intquery, comparator);
	while ((v_it != v.end()) && equals(*v_it, intquery)) {
		results.insert(results.end(), *v_it);
		++v_it;
	}
	return results;
}
vector<Subject> binCourseWork(vector<Subject> &v, bool(*comparator_rec)(Subject, Subject),
	bool(*comparator)(Subject, courseWork), bool(*equals)(Subject, courseWork)) {
	vector<Subject> results;
	vector<Subject>::iterator v_it = v.begin();
	courseWork crsquery = CourseWork();//����������� �������� �����
	sort(v.begin(), v.end(), comparator_rec);
	v_it = lower_bound(v.begin(), v.end(), crsquery, comparator);
	while ((v_it != v.end()) && equals(*v_it, crsquery)) {
		results.insert(results.end(), *v_it);
		++v_it;
	}
	return results;
}
vector<Subject> binViewSub(vector<Subject> &v, bool(*comparator_rec)(Subject, Subject),
	bool(*comparator)(Subject, viewSub), bool(*equals)(Subject, viewSub)) {
	vector<Subject> results;
	vector<Subject>::iterator v_it = v.begin();
	viewSub viewquery = ChoiseControl();//����������� �������� ����� ��� ������ �������, ���������� ����������
	sort(v.begin(), v.end(), comparator_rec);
	v_it = lower_bound(v.begin(), v.end(), viewquery, comparator);
	while ((v_it != v.end()) && equals(*v_it, viewquery)) {
		results.insert(results.end(), *v_it);
		++v_it;
	}
	return results;
}

#pragma endregion 


int helpFind()
{
	int num;
	cout << "�� ������ �������� �� ������ ������������ �����?" << endl
		<< "1 - ������� �������������" << endl
		<< "2 - ��� ������" << endl
		<< "3 - ������� ��������" << endl
		<< "4 - ��� ��������� ��������" << endl;
	num = rightInput(1, 4);
	Subject sub;
	switch (num)
	{
	case 1:
	{
		cout << "������� ������� �������������: " << endl;
		break;
	}
	case 2:
	{
		cout << "������� ��� ������: " << endl;
		break;
	}
	case 3:
	{
		cout << "������� �������� ������ :" << endl;
		break;
	}
	case 4:
	{
		cout << "������� ��� ��������� ��������" << endl;
		break;
	}
	}
	return num;
}

vector<Subject> findBinary(vector <Subject>& temp)//������� � ���������
//������ �� ��������
{
	int num;
	vector<Subject> choise;
	num = helpFind();
	switch (num)
	{
	case 1:
	{
		choise = binSurname(temp, SurnameRecComp, SurnameComp, equalsSurname);
		break;
	}
	case 2:
	{
		choise = binCodeGroup(temp, CodeGroupRecComp, CodeGroupComp, equalsCodeGroup);
		break;
	}
	case 3:
	{
		choise = binCourseWork(temp, CourseWorkRecComp, CourseWorkComp, equalsCourseWork);
		break;
	}
	case 4:
	{
		choise = binViewSub(temp, ViewRecComp, ViewComp, equalsViewSub);
		break;
	}
	}
	return choise;
}

vector<Subject> find(vector <Subject>& temp)
{
	vector<Subject> choise;
	cout << "����� ����� ������ �����������?" << endl
		<< "1 - ����������������" << endl
		<< "2 - ��������" << endl;
	int num = rightInput(1, 2);
	//switch �� ���� �������� ������
	switch (num)
	{
	case 1: {	choise = find�onsistently(temp);  break;  }
	case 2: {	choise = findBinary(temp);  break;   }
	}
	return choise;
}

void choiseBased(vector <Subject>& base)
{
	vector<Subject> choise = find(base);



	int k;
	cout << "���� �� ������ ������� ���������?" << endl
		<< "1 - �����" << endl
		<< "2 - ����" << endl;
	k = rightInput(1, 2);
	switch (k)
	{
	case 1:
	{
		if (choise.empty())
		{
			cout << "��� ���������� �������" << endl;
			return;
		}
		else
			printBase(choise);
		break;
	}
	case 2:
	{
		ofstream fout;
		stack<Subject> st;
		if (choise.empty())
		{
			fout << "��� ���������� �������" << endl;
			return;
		}

		if(!choise.empty())
		{
			fout.open("Total_Subjects.txt");
			printBase(choise);
			while(!choise.empty())
				st.push(choise.front());
		}
		while (!st.empty())
		{
			fout << st.top();
			st.pop();
		}
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Subject> base;
	int num;

	do
	{
		cout << "1 - �������� ���� ������ � ��������" << endl
			<< "2 - �������� �������� ������" << endl
			<< "3 - ������ �������� ������" << endl
			<< "4 - ������� ������������ �������" << endl
			<< "5 - ������ ���� �������" << endl
			<< "0 - �����" << endl;
		num = rightInput(0, 6);
		switch (num)
		{
		case 1: {	addRecord(base);   break; }
		case 2: {	deleteRecord(base);  break; }
		case 3: {   changeRecord(base); break; }
		case 4: {   choiseBased(base); break;  }
		case 5: {   printBase(base);  break;   }
		}
	} while (num != 0);
	return 0;
}
//---------------------------------------------------------------------------
