#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    //convert the hour to an integer for comparison
    int hour = stoi(s.substr(0, s.find(":")));
    
    //add 12 hours to PM times, except 12pm itself
    if(s.find("PM") != std::string::npos){
        //don't add 12 to 12 since 12PM is the same in both formats
        if (hour != 12){
            hour += 12;
        }
    }
    //if it's 12 AM, convert it to 0 AM
    else if (hour == 12)
        hour = 0;
    
    //update the string to cut off the old hour and AM/PM
    s = s.substr(s.find(":"), s.length() - 4);
    
    if (hour < 10)
        //prepend a leading 0 for hours less than 10
        s = to_string(0).append(to_string(hour).append(s));
    else
        //prepend the hour without a leading 0
        s = to_string(hour).append(s);
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
