## 实验内容

本次实验的内容是实现任务调度的先来先服务（FCFS）算法和短作业优先（SJF）算法。

函数签名约定如下：

```c
void FCFS (
    int number_of_jobs,
    const int job_submitted_time [],
    const int job_required_time [],
    int job_sched_start []
);

void SJF (
    int number_of_jobs,
    const int job_submitted_time [],
    const int job_required_time [],
    int job_sched_start []
);
```

其中各参数的含义约定如下：

- `number_of_jobs`：任务总数
  - 任务编号从 0 开始
- `job_submitted_time`：任务提交时间
  - `job_submitted_time[i]` 为第 $i$ 个任务被提交到队列中的时间
- `job_required_time`：任务所需时间
  - `job_required_time[i]` 为第 $i$ 个任务执行所需的时间
- `job_sched_start`：任务开始时间
  - `job_sched_start[i]` 为第 $i$ 个任务的开始时间

我们保证调用 `FCFS` 函数和 `SJF` 函数时，在有效范围（不超出任务总数）内，`job_submitted_time` 数组单调不减。

函数 `FCFS` 和函数 `SJF` 从 `job_submitted_time` 数组和 `job_required_time` 数组中获取任务信息，按照如下规则进行任务调度，并将每个任务的实际开始时间写回 `job_sched_start` 数组中：

- 在 `FCFS` 函数中，对于提交时间相同的任务，编号小的任务优先；
- 在 `SJF` 函数中：
  - 对于所需时间相同的任务，提交时间早的任务优先；
  - 对于所需时间相同，提交时间也相同的任务，编号小的任务优先；

## 数据规模

对于所有测试点，编译限时 $5000\;\rm{ms}$，运行限时 $1000\;\rm{ms}$。

记任务总数为 $n$，第 $i$ 个任务的提交时间是 $s_i$，所需时间是 $r_i$。

| 测试点编号 | 分值 | $n$ | $s, r$ | 测试内容 |
|:--------:|:--------:|:--------:|:--------:|:--------:|
| **1** | $20$ | $0 \le n\le 20$ | $0\le s_i \le 10^6$，$1\le r_i \le 10^6$ | FCFS |
| **2** | $20$ | $0 \le n\le 2000$ | $0\le s_i \le 10^6$，$1\le r_i \le 10^6$ | FCFS |
| **3** | $20$ | $0 \le n\le 20$ |  $0\le s_i \le 10^6$，$1\le r_i \le 10^6$ | SJF |
| **4** | $20$ | $0 \le n\le 2000$ | $0\le s_i \le 10^6$，$1\le r_i \le 10^6$ | SJF |
| **5** | $10$ | $0 \le n\le 20$ |  $0\le s_i \le 10^6$，$1\le r_i \le 10^6$ | FCFS + SJF |
| **6** | $10$ | $0 \le n\le 2000$ | $0\le s_i \le 10^6$，$1\le r_i \le 10^6$ | FCFS + SJF |

## 实验流程

1. 创建新的空白分支：`git checkout --orphan job-scheduling`
2. 清除无关文件：`git rm -rf . && rm -rf *`
3. 创建并填充相关代码文件：
   1. 新建 `sched.h` 文件，在其中添加约定的函数签名。
   2. 新建 `sched.c` 文件，在其中：
      1. 包含 `sched.h` 头文件：`#include "sched.h"`
      2. 实现约定的两个函数。
4. 将文件添加进 Git：`git add sched.h sched.c`
5. 创建 commit：`git commit -m "commit 信息"`
6. 推送至 GitLab：`git push -u origin job-scheduling:job-scheduling`

## 测试样例

创建 `main.c` 文件，内容如下：

```c
#include <stdio.h>
#include "sched.h"
int job_submitted_time[] = {0, 1, 2, 3, 12, 12, 12, 12, 200, 200};
int job_required_time[] = {4, 3, 2, 1, 6, 5, 4, 3, 1, 1};
int fcfs_result[10];
int sjf_result[10];

int main() {
    int n = 10, i;
    FCFS(n, job_submitted_time, job_required_time, fcfs_result);
    puts("FCFS results:");
    for (i = 0; i < n; ++i) printf("job % 2d: [% 9d]\n", i, fcfs_result[i]);
    SJF(n, job_submitted_time, job_required_time, sjf_result);
    puts("SJF results:");
    for (i = 0; i < n; ++i) printf("job % 2d: [% 9d]\n", i, sjf_result[i]);
}
```

编译：

```sh
gcc -o main sched.c main.c
```

运行：

```sh
./main
```

运行结果：

```plain
FCFS results:
job  0: [        0]
job  1: [        4]
job  2: [        7]
job  3: [        9]
job  4: [       12]
job  5: [       18]
job  6: [       23]
job  7: [       27]
job  8: [      200]
job  9: [      201]
SJF results:
job  0: [        0]
job  1: [        7]
job  2: [        5]
job  3: [        4]
job  4: [       24]
job  5: [       19]
job  6: [       15]
job  7: [       12]
job  8: [      200]
job  9: [      201]
```
