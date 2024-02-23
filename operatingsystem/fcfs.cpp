#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << "Average waiting time = " << (float)total_wt / (float)n << endl;
    cout << "Average turn around time = " << (float)total_tat / (float)n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int *processes = new int[n];
    int *burst_time = new int[n];

    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Burst time for process " << i + 1 << ": ";
        cin >> burst_time[i];
        processes[i] = i + 1;
    }

    findavgTime(processes, n, burst_time);

    delete[] processes;
    delete[] burst_time;

    return 0;
}

/*swapnil-ghosh@swapnil-ghosh-HP-Laptop-15s-eq2xxx:~p
swapnil-ghosh@swapnil-ghosh-HP-Laptop-15s-eq2xxx:~/operatingsystem$ ./a.out
Enter the number of processes: 3
Enter burst time for each process:
Burst time for process 1: 10
Burst time for process 2: 5
Burst time for process 3: 8
Processes  Burst time  Waiting time  Turn around time
 1		10	 0		 10
 2		5	 10		 15
 3		8	 15		 23
Average waiting time = 8.33333
Average turn around time = 16*/
