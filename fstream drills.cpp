// fstream drills
// 10/12/2021
// Amir Afunian

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Point {
	Point(int, int);
	int x;
	int y;
};
Point::Point(int xx, int yy) {
	x = xx;
	y = yy;
}
ostream& operator<<(ostream& os, Point pt) {
	return os << '(' << pt.x << ',' << pt.y << ")\n";
}
bool operator==(Point a, Point b) {
	if (a.x != b.x || a.y != b.y) { return false; }
	return true;
}
int main() {
	ofstream ost{ "mydata.txt" };
	vector<Point> original_points;
	int a, b;
	cout << "Enter seven (x,y) point pairs with a space between each x, y, and pair: ";
	for (int i = 0; i < 7; ++i) {
		cin >> a >> b;
		original_points.push_back(Point(a, b));
	}
	for (int i = 0; i < original_points.size(); ++i) {
		ost << original_points[i];
	}
	ost.close();
	vector<Point> processed_points;
	char test;
	char test2 = ',';
	char test3 = ')';
	int x, y;
	ifstream ist{ "mydata.txt" };
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	for (int i = 0; i < original_points.size(); ++i) {
		if (ist >> test && test != '(') {
			ist.unget();
			ist.clear(ios_base::failbit);
			cout << "Error! (1)\n";
			return -1;
		}
		ist >> x >> test2 >> y >> test3;
		if (!ist || test2 != ',' || test3 != ')')
		{
			cout << "Error! (2)\n";
			return -2;
		}
		else processed_points.push_back(Point(x, y));
	}
	//original_points[5].x = 4;		/*** Test for loop ***/
	for (int i = 0; i < original_points.size(); ++i) {
		if (!(original_points[i] == processed_points[i])) {
			cout << "Something's wrong!\n";
			return -3;
		}
	}
	for (int i = 0; i < original_points.size(); ++i) {
		if (original_points[i] == processed_points[i]) {
			cout << "original_points[" << i << "]:  " << original_points[i];
			cout << "processed_points[" << i << "]: " << processed_points[i];
		}
	}
	return 0;
}