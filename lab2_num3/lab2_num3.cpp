//---------------------------------------------------------------------------
/*Запись о преподаваемой дисциплине представляется структурой: код дисциплины,
наименование дисциплины, фамилия преподавателя, код группы, количество
студентов в группе, количество часов лекций, количество часов практики, наличие
курсовой работы, вид итогового контроля (зачет или экзамен). Зачет — 0.35ч на
студента, экзамен — 0.5ч на студента. Поиск по фамилии преподавателя, коду
группы, наличию курсовой, виду итогового контроля.*/

/*3 - бинарный файл, расширение... */
/*разнести по файлам  + */

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
			cout << "Неккоректный ввод. Повторите попытку" << endl;
	} while (!ok);
	return num;
}
viewSub ChoiseControl() {/*добавить default return +*/
	int choise;
	cout << "1) Зачет" << endl;
	cout << "2) Экзамен" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
	default: return credit; break;
	case 2: return exam; break;
	}
}

courseWork CourseWork() {/*добавить default return +*/
	int choise;
	cout << "1) Есть" << endl;
	cout << "2) Нет" << endl;
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
	cout << "Введите код дисциплины:" << endl;
	cin >> sub.CodeSub;
	cout << "Введите название дисциплины:" << endl;
	cin >> sub.NameSub;
	cout << "Введите фамилию преподавателя: " << endl;
	cin >> sub.SurnameTeach;
	cout << "Введите код группы:" << endl;
	cin >> sub.CodeGroup;
	cout << "Введите количество студентов в группе:"<<endl;
	cin >> sub.NubmStudent;
	cout << "Введите количество часов лекций: " << endl;
	cin >> sub.NumbHourLe;
	cout << "Введите количество часов практики:" << endl;
	cin >> sub.NumbHourPr;
	cout << "Наличие курсовой работы:" << endl;
	sub.CourseWork = CourseWork();
	cout << "Введите вид итогового контроля:" << endl;
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
		cout << "Записей пока нет" << endl;
		return;
	}
	cout << "Введите номер записи, которую хотели бы удалить: " << endl;
	int num = rightInput(1, temp.size());

	//удаление
	auto it = temp.begin();
	advance(it, num-1);
	temp.erase(it);
}

void changeRecord(vector <Subject>& temp)
{
	if (temp.size() == 0)
	{
		cout << "Записей пока нет" << endl;
		return;
	}
	cout << "Введите номер записи, которую хотели бы изменить: " << endl;
	int num = rightInput(1, temp.size());
	cout << "Введите новые данные для записи" << endl;
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
	os << "Фамилия преподавателя:  " << sub.SurnameTeach << endl
		<< "Код дисциплины:  " << sub.CodeSub << endl
		<< "Наименование дисциплины: " << sub.NameSub << endl
		<< "Код группы: " << sub.CodeGroup << endl
		<< "Количество студентов в группе: " << sub.NubmStudent << endl
		<< "Количество часов лекций:  " << sub.NumbHourLe << endl
		<< "Количество часов практики:  " << sub.NumbHourPr << endl;
	cout << "Наличие курсовой:  ";
	printCourseWork(&sub.CourseWork);
	cout << "Вид итогового контроля:  ";
	printView(&sub.ViewSub);
	cout<< "-------------------------------------------------" << endl;
	return os;
}

void printBase(vector <Subject>& base)
{
	Subject elem;
	if (base.size() == 0)
		cout << "Никаких сведений нет" << endl;
	else
		for (auto pos = base.begin(); pos != base.end(); ++pos)
		{
			elem = *pos;
			cout << elem;
		}
}

Subject helpFind(int& num)
{
	cout << "По какому критерию вы хотите осуществлять поиск?" << endl
		<< "1 - фамилия преподавателя" << endl
		<< "2 - код группы" << endl
		<< "3 - наличие курсовой" << endl
		<< "4 - вид итогового контроля" << endl;
	num = rightInput(1, 4);
	Subject sub;
	switch (num)
	{
	case 1:
	{
		cout << "Введите фамилию преподавателя: " << endl;
		cin >> sub.SurnameTeach;
		break;
	}
	case 2:
	{
		cout << "Введите код группы: " << endl;
		cin >> sub.CodeGroup;
		break;
	}
	case 3:
	{
		cout << "Наличие курсовой работы :" << endl;
		sub.CourseWork = CourseWork();
		break;
	}
	case 4:
	{
		cout << "Введите вид итогового контроля" << endl;
		sub.ViewSub = ChoiseControl();
		break;
	}
	}
	return sub;
}
// шаблонный последовательный поиск
vector<Subject> findСonsistently(vector <Subject>& temp)
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


#pragma region Бинарный поиск 
// шаблонный бинарный поиск
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
	courseWork crsquery = CourseWork();//перегрузить оператор ввода
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
	viewSub viewquery = ChoiseControl();//перегрузить оператор ввода или ввести снаружи, передавать параметром
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
	cout << "По какому критерию вы хотите осуществлять поиск?" << endl
		<< "1 - фамилия преподавателя" << endl
		<< "2 - код группы" << endl
		<< "3 - наличие курсовой" << endl
		<< "4 - вид итогового контроля" << endl;
	num = rightInput(1, 4);
	Subject sub;
	switch (num)
	{
	case 1:
	{
		cout << "Введите фамилию преподавателя: " << endl;
		break;
	}
	case 2:
	{
		cout << "Введите код группы: " << endl;
		break;
	}
	case 3:
	{
		cout << "Наличие курсовой работы :" << endl;
		break;
	}
	case 4:
	{
		cout << "Введите вид итогового контроля" << endl;
		break;
	}
	}
	return num;
}

vector<Subject> findBinary(vector <Subject>& temp)//вынести и дополнить
//ничего не печатать
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
	cout << "Какой поиск хотите осуществить?" << endl
		<< "1 - последовательный" << endl
		<< "2 - бинарный" << endl;
	int num = rightInput(1, 2);
	//switch по типу вводимых данных
	switch (num)
	{
	case 1: {	choise = findСonsistently(temp);  break;  }
	case 2: {	choise = findBinary(temp);  break;   }
	}
	return choise;
}

void choiseBased(vector <Subject>& base)
{
	vector<Subject> choise = find(base);



	int k;
	cout << "Куда вы хотите вывести результат?" << endl
		<< "1 - экран" << endl
		<< "2 - файл" << endl;
	k = rightInput(1, 2);
	switch (k)
	{
	case 1:
	{
		if (choise.empty())
		{
			cout << "Нет подходящей выборки" << endl;
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
			fout << "Нет подходящей выборки" << endl;
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
		cout << "1 - Добавить одну запись о предмете" << endl
			<< "2 - Удаление заданной записи" << endl
			<< "3 - Замена заданной записи" << endl
			<< "4 - Выборка подмножества записей" << endl
			<< "5 - Печать всех записей" << endl
			<< "0 - Выход" << endl;
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
