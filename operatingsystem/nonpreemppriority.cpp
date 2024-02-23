/*#include <iostream>
#include <algorithm>
using namespace std;

#define totalprocess 5

struct process {
    int at, bt, pr, pno;
};

process proc[50];

bool comp(process a, process b) {
    if (a.at == b.at) {
        return a.pr < b.pr;
    } else {
        return a.at < b.at;
    }
}

void get_wt_time(int wt[]) {
    int service[50];
    service[0] = proc[0].at;
    wt[0] = 0;
    for (int i = 1; i < totalprocess; i++) {
        service[i] = proc[i - 1].bt + service[i - 1];
        wt[i] = service[i] - proc[i].at;
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

void get_tat_time(int tat[], int wt[]) {
    for (int i = 0; i < totalprocess; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findgc() {
    int wt[50], tat[50];
    double wavg = 0, tavg = 0;
    get_wt_time(wt);
    get_tat_time(tat, wt);
    int stime[50], ctime[50];
    stime[0] = proc[0].at;
    ctime[0] = stime[0] + tat[0];
    for (int i = 1; i < totalprocess; i++) {
        stime[i] = ctime[i - 1];
        ctime[i] = stime[i] + tat[i] - wt[i];
    }
    cout << "Process_no\tArrival time\tCompletion time\tTAT\tWT" << endl;
    for (int i = 0; i < totalprocess; i++) {
        wavg += wt[i];
        tavg += tat[i];
        cout << proc[i].pno << "\t\t" <<
            stime[i] << "\t\t" << ctime[i] << "\t\t" <<
            tat[i] << "\t" << wt[i] << endl;
    }
    cout << "Average waiting time is : ";
    cout << wavg / (float)totalprocess << endl;
    cout << "average turnaround time : ";
    cout << tavg / (float)totalprocess << endl;
}

int main() {
    int arrivaltime[totalprocess], bursttime[totalprocess], priority[totalprocess];

    cout << "Enter arrival time, burst time, and priority for each process:" << endl;
    for (int i = 0; i < totalprocess; i++) {
        cout << "For process " << i + 1 << ":" << endl;
        cout << "Arrival time: ";
        cin >> arrivaltime[i];
        cout << "Burst time: ";
        cin >> bursttime[i];
        cout << "Priority: ";
        cin >> priority[i];
    }

    for (int i = 0; i < totalprocess; i++) {
        proc[i].at = arrivaltime[i];
        proc[i].bt = bursttime[i];
        proc[i].pr = priority[i];
        proc[i].pno = i + 1;
    }

    sort(proc, proc + totalprocess, comp);
    findgc();
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

#define totalprocess 5

struct process {
    int at, bt, pr, pno;
};

process proc[50];

bool comp(process a, process b) {
    if (a.at == b.at) {
        if (a.pr == b.pr) {
            return a.pno < b.pno; // If priorities and arrival times are the same, sort based on process number
        }
        return a.pr > b.pr; // Sort based on priority (higher priority first) if arrival times are the same
    } else {
        return a.at < b.at; // Sort based on arrival time
    }
}

void findWaitingTime(int wt[]) {
    int service[50];
    service[0] = proc[0].at;
    wt[0] = 0;
    for (int i = 1; i < totalprocess; i++) {
        service[i] = proc[i - 1].bt + service[i - 1];
        wt[i] = service[i] - proc[i].at;
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

void findTurnAroundTime(int tat[], int wt[]) {
    for (int i = 0; i < totalprocess; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findavgTime() {
    int wt[50], tat[50];
    double wavg = 0, tavg = 0;
    findWaitingTime(wt);
    findTurnAroundTime(tat, wt);
    cout << "Process_no\tArrival time\tBurst time\tPriority\tWaiting time\tTurnaround time" << endl;
    for (int i = 0; i < totalprocess; i++) {
        wavg += wt[i];
        tavg += tat[i];
        cout << proc[i].pno << "\t\t" <<
            proc[i].at << "\t\t" << proc[i].bt << "\t\t" << proc[i].pr << "\t\t" <<
            wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "Average waiting time is : ";
    cout << wavg / totalprocess << endl;
    cout << "Average turnaround time : ";
    cout << tavg / totalprocess << endl;
}

int main() {
    cout << "Enter arrival time, burst time, and priority for each process:" << endl;
    for (int i = 0; i < totalprocess; i++) {
        cout << "For process " << i + 1 << ":" << endl;
        cout << "Arrival time: ";
        cin >> proc[i].at;
        cout << "Burst time: ";
        cin >> proc[i].bt;
        cout << "Priority: ";
        cin >> proc[i].pr;
        proc[i].pno = i + 1;
    }

    sort(proc, proc + totalprocess, comp);
    findavgTime();
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

struct process {
    int at, bt, pr, pno;
};

void findWaitingTime(process proc[], int n, int wt[]) {
    int service[n];
    service[0] = proc[0].at;
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        service[i] = proc[i - 1].bt + service[i - 1];
        wt[i] = service[i] - proc[i].at;
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

void findTurnAroundTime(process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

bool comp(process a, process b) {
    if (a.at == b.at) {
        if (a.pr == b.pr) {
            return a.pno < b.pno; // If priorities and arrival times are the same, sort based on process number
        }
        return a.pr > b.pr; // Sort based on priority (higher priority first) if arrival times are the same
    } else {
        return a.at < b.at; // Sort based on arrival time
    }
}

void findavgTime(process proc[], int n) {
    int wt[n], tat[n];
    double wavg = 0, tavg = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    cout << "Process_no\tArrival time\tBurst time\tPriority\tWaiting time\tTurnaround time" << endl;
    for (int i = 0; i < n; i++) {
        wavg += wt[i];
        tavg += tat[i];
        cout << proc[i].pno << "\t\t" <<
            proc[i].at << "\t\t" << proc[i].bt << "\t\t" << proc[i].pr << "\t\t" <<
            wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "Average waiting time is : ";
    cout << wavg / n << endl;
    cout << "Average turnaround time : ";
    cout << tavg / n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    process proc[n];

    cout << "Enter arrival time, burst time, and priority for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For process " << i + 1 << ":" << endl;
        cout << "Arrival time: ";
        cin >> proc[i].at;
        cout << "Burst time: ";
        cin >> proc[i].bt;
        cout << "Priority: ";
        cin >> proc[i].pr;
        proc[i].pno = i + 1;
    }

    sort(proc, proc + n, comp);
    findavgTime(proc, n);
    return 0;
}*/

#include<stdio.h>

int main() {
    int i, n, p[10], min, k = 1, burst = 0, pri[10];
    int bt[10], temp, temp1, j, at[10], wt[10], rt[10], tt[10], ta = 0, sum = 0;
    float wavg, tavg, tsum = 0, wsum = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n\nProcess %d \n", i + 1);
        printf("\tBurst time: ");
        scanf("%d", &bt[i]);
        printf("\tArrival time: ");
        scanf("%d", &at[i]);
        printf("\tPriority: ");
        scanf("%d", &pri[i]);
        p[i] = i + 1; // Assigning process numbers
    }

    // Sorting according to arrival time
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (at[i] < at[j]) {
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;

                temp = at[j];
                at[j] = at[i];
                at[i] = temp;

                temp1 = bt[j];
                bt[j] = bt[i];
                bt[i] = temp1;

                temp = pri[j];
                pri[j] = pri[i];
                pri[i] = temp;
            }
        }
    }

    for (j = 0; j < n; j++) {
        burst += bt[j];
        min = bt[k];
        for (i = k; i < n; i++) {
            min = pri[k];
            if (burst >= at[i]) {
                if (pri[i] < min) {
                    temp = p[k];
                    p[k] = p[i];
                    p[i] = temp;

                    temp = at[k];
                    at[k] = at[i];
                    at[i] = temp;

                    temp1 = bt[k];
                    bt[k] = bt[i];
                    bt[i] = temp1;

                    temp = pri[k];
                    pri[k] = pri[i];
                    pri[i] = temp;
                }
            }
        }
        k++;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        sum += bt[i - 1];
        wt[i] = sum - at[i];
    }

    for (i = 0; i < n; i++) {
        wsum += wt[i];
    }
    wavg = wsum / n;

    for (i = 0; i < n; i++) {
        ta += bt[i];
        tt[i] = ta - at[i];
    }

    for (i = 0; i < n; i++) {
        tsum += tt[i];
    }
    tavg = tsum / n;

    for (i = 0; i < n; i++) {
        rt[i] = wt[i];
    }

    printf("********\n");
    printf("RESULT: VARIOUS TIMES\n");
    printf("Process\tBurst\tArrival\tPriority\n");

    for (i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\n", p[i], bt[i], at[i], pri[i]);
    }

    printf("Waiting Time\tTurnaround Time\tResponse Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", wt[i], tt[i], rt[i]);
    }

    printf("AVERAGE WAITING TIME: %.2f ms\n", wavg);
    printf("AVERAGE TURNAROUND TIME: %.2f ms\n", tavg);
    printf("AVERAGE RESPONSE TIME: %.2f ms\n", wavg);

    return 0;
}


