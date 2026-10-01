#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    double totalCredits = 0;
    double totalGradePoints = 0;

    double grade[n], credit[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter grade for Course " << i + 1 << ": ";
        cin >> grade[i];

        cout << "Enter credit hours for Course " << i + 1 << ": ";
        cin >> credit[i];

        totalGradePoints += grade[i] * credit[i];
        totalCredits += credit[i];
    }

    cout << "\n--- Course Details ---\n";

    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grade[i]
             << " | Credits: " << credit[i] << endl;
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << fixed << setprecision(2);
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
