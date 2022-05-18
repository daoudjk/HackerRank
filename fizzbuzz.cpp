#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n) {
    bool fizz = false, buzz = false;
    for(int i = 1; i <= n; i++)
    {
        if(i%3 == 0){
            fizz = true;
        }
        if(i%5 == 0){
            buzz = true;
        }
        if(fizz && buzz)
            cout << "FizzBuzz" << endl;
        if(fizz && !buzz)
            cout << "Fizz" << endl;
        if(!fizz && buzz)
            cout << "Buzz" << endl;
        if(!fizz && !buzz)
            cout << i << endl;
        fizz = false;
        buzz = false;
    }
}
int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    fizzBuzz(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
