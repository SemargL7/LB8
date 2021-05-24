/*
ѕеревантажити операц≥њ > (пор≥вн€нн€ двох к≥л за площею), Ц (р≥зниц€ двох к≥л Ц координат центру та рад≥ус≥в),
в≥дсортувати масив екземпл€р≥в класу к≥л за спаданн€м площ з використанн€м алгоритму сортуванн€ обм≥ном,
обчислити р≥зницю двох к≥л з найб≥льшою та найменшою площею у масив≥.
*/

#include <iostream>
#include <cmath>
#include <string>
#define PI 3.14

using namespace std;

class Database
{
private:
	static Database* singleObject;
	static int count;

	int x;
	int y;
	int radius;
	Database(int x, int y, int r)
	{
		this->x = x;
		this->y = y;
		this->radius = r;
		count++;
	}
public:
	static Database& getInstance(int x, int y, int r)
	{
		if (count == 0)
		{
			singleObject = new Database(x, y, r);
		}

		return *singleObject;

	};
	int GetX() { return x; }
	int GetY() { return y; }
	int GetRadius() { return radius; }
};
int Database::count = 0;

Database* Database::singleObject = 0;

class Cirle {
private:
	int x;
	int y;
	int radius;

public:
	Cirle(int x, int y, int radius) {
		this->x = x; this->y = y; this->radius = radius;
	}
	Cirle() {}
	~Cirle() {}													

	int GetX() { return x; }
	int GetY() { return y; }
	int GetRadius() { return radius; }

	void SetX(int a) { x = a; }
	void SetY(int b) { y = b; }
	void SetRadius(int c) { radius = c; }

	double square();
};


double Cirle::square() {											
	return (PI * pow(radius, 2));
}

bool operator > (Cirle a, Cirle b) {
	return a.square() > b.square();
}

Cirle operator - (Cirle c1, Cirle c2)
{
	return Cirle(c1.GetX() - c2.GetX(), c1.GetY() - c2.GetY(), c1.GetRadius() - c2.GetRadius());
}

void sorting(Cirle a[], int b) {
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			bool wtbigger = a[i] > a[j];
			if (wtbigger == true) {
				Cirle a_sort(a[j].GetX(), a[j].GetY(), a[j].GetRadius());

				a[j].SetX(a[i].GetX());
				a[j].SetY(a[i].GetY());
				a[j].SetRadius(a[i].GetRadius());

				a[i].SetX(a_sort.GetX());
				a[i].SetY(a_sort.GetY());
				a[i].SetRadius(a_sort.GetRadius());
			}
		}
	}
}



int main() {
	cout << "How much Circles you wanna insert? :"<<endl;
	int C;
	cin >> C;
	Cirle* arrays;
	arrays = new Cirle[C];
	int a;
	for (int i = 0; i < C; i++) {
		cout << "SetX:";
		cin >> a;
		arrays[i].SetX(a);
		cout << "SetY:";
		cin >> a;
		arrays[i].SetY(a);
		cout << "SetRadius:";
		cin >> a;
		arrays[i].SetRadius(a);
		Database test = Database::getInstance(arrays[i].GetX(), arrays[i].GetY(), arrays[i].GetRadius());
	}
	Database test = Database::getInstance(arrays[C - 1].GetX(), arrays[C - 1].GetY(), arrays[C - 1].GetRadius());
	cout << "\tTest:" << endl;

	cout << test.GetX() << " " << test.GetY() << " " << test.GetRadius() << endl;

	cout << "\tList of array:" << endl;
	for (int i = 0; i < C; i++) {
		cout << arrays[i].GetX() << " " << arrays[i].GetY() << " " << arrays[i].GetRadius() << endl;
	}
	sorting(arrays, C);
	cout << "\tSorted list of array:" << endl;
	for (int i = 0; i < C; i++) {
		cout << arrays[i].GetX() << " " << arrays[i].GetY() << " " << arrays[i].GetRadius() << endl;
	}
	cout << "\n\tThe difference between  the biggest and the smallest:\n";
	Cirle dif_of_max_and_min = arrays[0] - arrays[C - 1];
	cout << dif_of_max_and_min.GetX() << " " << dif_of_max_and_min.GetY() << " " << dif_of_max_and_min.GetRadius() << endl;

	test = Database::getInstance(dif_of_max_and_min.GetX(), dif_of_max_and_min.GetY(), dif_of_max_and_min.GetRadius());
	cout << "\tTest:" << endl;

	cout << test.GetX() << " " << test.GetY() << " " << test.GetRadius() << endl;
}