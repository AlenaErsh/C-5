#include "stdafx.h"
#include "Subject.h"

//компараторы

//сравнение записей
bool SurnameRecComp(Subject left, Subject right) {
	return left.SurnameTeach < right.SurnameTeach;
}
bool CodeGroupRecComp(Subject left, Subject right) {
	return left.CodeGroup < right.CodeGroup;
}
bool CourseWorkRecComp(Subject left, Subject right) {
	return left.CourseWork < right.CourseWork;
}
bool ViewRecComp(Subject left, Subject right) {
	return left.ViewSub < right.ViewSub;
}

//сравнение записи с поступившим значением
bool SurnameComp(Subject left, string value) {
	return (left.SurnameTeach < value);
}
bool CodeGroupComp(Subject left, int value) {
	return (left.CodeGroup < value);
}
bool CourseWorkComp(Subject left, courseWork value) {
	return left.CourseWork < value;
}
bool ViewComp(Subject left, viewSub value) {
	return left.ViewSub < value;
}

//возвращение равенства
//без шаблона можно сделать фиктивную запись с одним нужным полем и сравнить с ней
bool equalsSurname(Subject sub, string strquery) {
	if (sub.SurnameTeach == strquery) return true;
	return false;
}
bool equalsCodeGroup(Subject sub, int intquery) {
	if (sub.CodeGroup == intquery) return true;
	return false;
}
bool equalsCourseWork(Subject sub, courseWork crsquery) {
	if (sub.CourseWork == crsquery) return true;
	return false;
}
bool equalsViewSub(Subject sub, viewSub viewquery) {
	if (sub.ViewSub == viewquery) return true;
	return false;
}
