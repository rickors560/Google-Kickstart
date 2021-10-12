## Problem

    You are given N intervals. An interval can be represented by two positive integers Li and Ri - the interval starts at Li and ends at Ri, represented as [Li,Ri]. Intervals may not be unique, so there might be multiple intervals with both equal Li and equal Ri.

    You are allowed to perform a maximum of C cuts. A cut at X will cut all intervals [L,R] for which L<X and X<R. Cutting an interval at X is defined as splitting the interval into two intervals - [L,X] and [X,R]. Note that cuts can only be performed at integer points. Also, cutting at an endpoint of an interval (X=L or X=R) has no effect and does not split the interval.

    You need to find the maximum number of intervals that can be obtained through a maximum of C cuts.

### Input

    The first line of the input contains the number of test cases, T. T test cases follow.

    Each test case starts with a line containing two integers, N and C, denoting the number of intervals and the maximum number of cuts you can perform respectively. N lines follow.
    The i-th line contains two integers Li and Ri, describing the i-th interval.

### Output

    For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of intervals that can be obtained through at most C cuts, as described above.

### Limits

Memory limit: 1 GB.
1≤T≤100.

### Test Set 1

Time limit: 20 seconds.
1≤N≤500.
1≤C≤105.
1≤Li<Ri≤104 for all i.

### Test Set 2

Time limit: 40 seconds.
1≤N≤105.
1≤C≤1018.
1≤Li<Ri≤1013 for all i.

### Sample

**_Sample Input_**

    1
    3 3
    1 3
    2 4
    1 4

**_Sample Output_**
    
    Case #1: 7

In the provided sample, cuts should be performed at 2 and 3 to get the maximum number of intervals.

After the first cut at 2, the intervals would be {[1,2],[2,3],[2,4],[1,2],[2,4]}.

After the second cut at 3, the intervals would be {[1,2],[2,3],[2,3],[3,4],[1,2],[2,3],[3,4]}.

It can be seen that no interval can be cut further, so the answer is 7.

## Problem Link:

    https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b933

## Reference Link:

    https://youtu.be/5nIrcOZETxI