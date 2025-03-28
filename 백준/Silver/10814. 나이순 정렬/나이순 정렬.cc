#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person
{
    int age, idx;
    string name;
};

bool compare(const person& now, const person& last)
{
    if(now.age != last.age) return now.age < last.age;
    return now.idx < last.idx;
}

person people[100001]; 

int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) //배열에 값 넣어줌
    {    
        cin >> people[i].age >> people[i].name;
        people[i].idx = i;
    }

    sort(people, people + N, compare);

    for (int i = 0; i < N; i++)
        cout << people[i].age << " " << people[i].name << "\n";
}