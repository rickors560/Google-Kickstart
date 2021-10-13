## Problem
    It's time for the final exam in algorithms and data structures!

    Edsger prepared N sets of problems. Each set consists of problems in an increasing difficulty sequence; the i-th set can be described by two integers Ai and Bi (Ai≤Bi), which denotes that this set contains problems with difficulties Ai,Ai+1,…,Bi. Among all problems from all sets, it is guaranteed that no two problems have the same difficulty.

    This semester Edsger has to test M students. He wants to test each student with exactly one problem from one of his sets. No two students can get the exact same problem, so when Edsger tests a student with some problem, he cannot use this problem anymore. Through countless lectures, exercises, and projects, Edsger has gauged student number j to have skill level Sj, and wants to give that student a problem with difficulty Sj. Unfortunately, this is not always possible, as Edsger may have not prepared a problem of this difficulty, or he may have already asked this problem to some other student earlier. Therefore, Edsger will choose for the j-th student a problem of difficulty Pj, in a way that |Pj−Sj| is minimal and a question of difficulty Pj was not already given to any of the students before the j-th student. In case of ties, Edsger will always choose the easier problem. Note that the problem chosen for the j-th student may affect problems chosen for all the students tested later, so you have to process students in the same order as they appear in the input.

    As keeping track of all the problems can be fairly complicated, can you help Edsger and determine which problems he should give to all of his students?

### Input

    The first line of the input gives the number of test cases, T. T test cases follow.

    Each test case begins with a line which contains two integers N and M: the number of problem sets, and the number of students, respectively. N lines follow, describing the problem sets. Each of these N lines consists of two integers Ai and Bi denoting the easiest and the hardest problem in the i-th problem set. Finally, the test case ends with a single line with M integers S1,S2,…,SM denoting students' skill levels in the order they will be tested.

### Output

    For each test case, output one line containing Case #x: P1P2…PM, where x is the test case number (starting from 1) and Pj is a difficulty of a problem that will be given to the j-th student.

### Limits

    Memory limit: 1 GB.
    1≤T≤100.
    Among all problem sets, no two problems have the same difficulty.
    The number of problems in total is greater than or equal to the number of students.

### Test Set 1

    Time limit: 20 seconds.
    1≤N≤1000.
    1≤M≤1000.
    1≤Ai≤Bi≤1000 for all i.
    1≤Sj≤1000 for all j.

### Test Set 2
    Time limit: 40 seconds.
    1≤N≤105.
    1≤M≤105.
    1≤Ai≤Bi≤1018 for all i.
    1≤Sj≤1018 for all j.

### Sample

***Sample Input***

    2
    5 4
    1 2
    6 7
    9 12
    24 24
    41 50
    14 24 24 4
    1 1
    42 42
    24

***Sample Output***

    Case #1: 12 24 11 2
    Case #2: 42
In Sample Case #1, we have N=5 problem sets and M=4 students.

For the first student, we are looking for a problem with the difficulty closest to their skill level S1=14. The problem with the minimum difference is problem with difficulty 12, which we can find in the third problem set, so P1=12.
For the second student, we are looking for a problem with the difficulty closest to their skill level S2=24. Fortunately, we can find a problem of this exact difficulty in the fourth problem set, so P2=24.
For the third student, we are once again looking for a problem with the difficulty closest to the skill level S3=24. As we already used the problem with difficulty 24, we cannot use this problem. The problem closest in difficulty is 11, as 12 was already used as well. Therefore P3=11.
Finally, for the fourth student, we are looking for the problem closest to his skill level S4=4. We have two problems with the same difference: 2 and 6. We choose the easier problem, so P4=2.
In Sample Case #2, we have N=1 problem set and M=1 student. In the only problem set, there is only one problem, so we have to use this problem to examine the first and only student, so P1=42.

## Problem Link:
    https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082bffc#problem