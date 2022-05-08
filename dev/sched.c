#include "sched.h"

void FCFS(int number_of_jobs, const int job_submitted_time [], const int job_required_time [], int job_sched_start []) {
    int i, cur;
    for (i = 0, cur = 0; i < number_of_jobs; ++i) {
        if (job_submitted_time[i] > cur) {
            job_sched_start[i] = cur = job_submitted_time[i], cur += job_required_time[i];
        } else {
            job_sched_start[i] = cur, cur += job_required_time[i];
        }
    }
}

void SJF(int number_of_jobs, const int *job_submitted_time, const int *job_required_time, int *job_sched_start) {
    int i, j, cur = 0;
    static int marker[0x1000];
    for (i = 0; i < number_of_jobs; ++i) marker[i] = 0;
    for (i = 0; i < number_of_jobs; ++i) {
        int si = -1, st = 1e9, min_sub = 1e9;
        for (j = 0; j < number_of_jobs; ++j) {
            if (!marker[j]) {
                if (job_submitted_time[j] < min_sub) min_sub = job_submitted_time[j];
                if (job_submitted_time[j] <= cur) {
                    if (job_required_time[j] < st) {
                        si = j;
                        st = job_required_time[j];
                    }
                }
            }
        }
        if (si < 0) {
            cur = min_sub;
            --i;
        } else {
            marker[si] = 1;
            job_sched_start[si] = cur;
            cur += st;
        }
    }
}