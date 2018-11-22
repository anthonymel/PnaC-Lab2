#include <string>
#include <iostream>
#include <vector>


using namespace std;



void Next(int& index, const vector<int>& diy, vector<vector<string>>& tfd) 
{ 
	index++; 
	if (index > 11)index = 0; 
	vector<vector<string>> NewMonth = tfd; 
	int a = tfd.size(); 
	int b = diy[index]; 
	tfd.resize(b); 
	const int e = b - 1; 
	if (a > b) { 
		for (b; a > b; b++) { 
			tfd[e].insert(end(tfd[e]), begin(NewMonth[b]), end(NewMonth[b])); 
		}
	}
	NewMonth.clear(); 
}
void Dump(int day, const vector<vector<string>>& tfd)
{
	cout << tfd[day - 1].size();
	for (auto i : tfd[day - 1]) {
		cout << " " << i;
	}
}

void Remove(int day, vector<vector<string>>& daily, string task)
{
	for (int i = 0; i < daily[day - 1].size(); i++)
	{
		if (daily[day - 1][i] == task)
		{
			daily[day - 1].erase(daily[day - 1].begin() + i);

		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int Q;
	cout << "Введите количество операций" << endl;
	cin >> Q; 
	vector<int> day_in_year = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	vector<vector<string>> daily; 
	int index_of_month = 0; 
	daily.resize(day_in_year[index_of_month], {}); 
	for (int i = 0; Q > i; i++) 
	{ 
		string comand; 
		int day; 
		string task; 
		cin >> comand; 
		if (comand == "NEXT") 
		{ 
			Next(index_of_month, day_in_year, daily); 
		}
		else if (comand == "DUMP") 
		{ 
			cin >> day; 
			if (day > day_in_year[index_of_month]) continue;
			Dump(day,daily); 
		}
		else if (comand == "ADD") 
		{ 
			cin >> day >> task; 
			if (day > day_in_year[index_of_month]) continue;
			daily[day - 1].push_back(task); 
		}
		else if (comand == "REMOVE") 
		{
			cin >> day >> task;
			if (day > day_in_year[index_of_month]) continue;
			Remove(day, daily, task);

		}
	}
	system("pause");
	return 0;
}