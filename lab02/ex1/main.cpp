/*
јндрей, просматрива€ программу телевидени€ на воскресенье, выписал названи€, 
врем€ начала и продолжительности трех передач, которые ему хотелось бы посмотреть. 
¬ h часов m (min) минут он включил телевизор. 
 акую передачу смотрит јндрей?
*/


#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	setlocale(LC_ALL, "Russian");
	int h;
	int min;
	int h1;
	int min1;
	int h1_dur;
	int min1_dur;
	int time1Finish;
	int h2;
	int min2;
	int h2_dur;
	int min2_dur;
	int time2Finish;
	int h3;
	int min3;
	int h3_dur;
	int min3_dur;
	int time3Finish;
	string name1;
	string name2;
	string name3;

	cout << "Input the name of the 1st programm: " << endl;
	cin >> name1;
	cout << "Input the time of the beginning of the 1st programm: " << endl;
	cout << "h:" << endl;
	cin >> h1;
	cout << "min:" << endl;
	cin >> min1;
	int beginningTime1 = h1 * 60 + min1;
	cout << "Input the time of the duration of the 1st programm:" << endl;
	cout << "h:" << endl;
	cin >> h1_dur;
	cout << "min:" << endl;
	cin >> min1_dur;
	time1Finish = h1_dur * 60 + min1_dur + beginningTime1;	

	cout << "Input the name of the 2nd programm:" << endl;
	cin >> name2;
	cout << "Input the time of the beginning of the 2nd programm:" << endl;
	cout << "h:" << endl;
	cin >> h2;
	cout << "min:" << endl;
	cin >> min2;
	int beginningTime2 = h2 * 60 + min2;
	cout << "Input the time of the duration of the 2nd programm:" << endl;
	cout << "h:" << endl;
	cin >> h2_dur;
	cout << "min:" << endl;
	cin >> min2_dur;
	time2Finish = h2_dur * 60 + min2_dur + beginningTime2;

	cout << "Input the name of the 3rd programm:" << endl;
	cin >> name3;
	cout << "Input the time of the beginning of the 3rd programm:" << endl;
	cout << "h:" << endl;
	cin >> h3;
	cout << "min:" << endl;
	cin >> min3;
	int beginningTime3 = h3 * 60 + min3;
	cout << "Input the time of the duration of the 3rd programm:" << endl;
	cout << "h:" << endl;
	cin >> h3_dur;
	cout << "min:" << endl;
	cin >> min3_dur;
	time3Finish = h3_dur * 60 + min3_dur + beginningTime3;

	cout << "Input the time Andrew has switched on the TV:" << endl;
	cout << "h:" << endl;
	cin >> h;
	cout << "m:" << endl;
	cin >> min;
	int time = h * 60 + min;

	if (time >= beginningTime1 && time < time1Finish)
	{
		cout << "Andrew is watching " << name1;
	}
	else if (time >= beginningTime2 && time < time2Finish)
	{
		cout << "Andrew is watching " << name2;
	}
	else if (time >= beginningTime3 && time < time3Finish)
	{
		cout << "Andrew is watching " << name3;
	}
	else {
		cout << "Andrew doesn't watch anything.";
	}
}