#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int A[100][4]; // Array to store process ID, Burst Time, Waiting Time, and Turnaround Time
    int total = 0, temp;
    float avg_wt = 0, avg_tat = 0;

    cout << "Enter Burst Time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Burst Time for process P" << i + 1 << ": ";
        cin >> A[i][1]; // Burst Time
        A[i][0] = i + 1; // Process ID
    }

    // Sorting processes based on burst time (FCFS)
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1])
                index = j;
        }
        // Swapping process IDs and Burst Times
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    A[0][2] = 0; // Waiting time for the first process is 0
    total = 0;
    cout << "P  BT  WT  TAT" << endl;
    for (int i = 0; i < n; i++) {
        A[i][2] = total; // Waiting time calculation
        total += A[i][1];
        A[i][3] = total; // Turnaround time calculation
        cout << "P" << A[i][0] << "   " << A[i][1] << "   " << A[i][2] << "   " << A[i][3] << endl;
        avg_wt += A[i][2]; // Sum of waiting times
        avg_tat += A[i][3]; // Sum of turnaround times
    }

    avg_wt /= n; // Average waiting time
    avg_tat /= n; // Average turnaround time
    cout << "Average Waiting Time = " << avg_wt << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;

    return 0;
}

