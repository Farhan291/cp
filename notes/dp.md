best problems

- https://cses.fi/problemset/task/1746/
- https://cses.fi/problemset/task/1635
- https://leetcode.com/problems/dungeon-game/description/
- https://codeforces.com/contest/2252/problem/B

dp on subsequeunces

- think in terms of pointer
- for example distinct subsequence question , s is string and t is the test string to match
- think two pointer on at start of both string dp state dp[i][j] means the pointer is at ith of s and jth at t and np. of distinct subseq till now.
- now if *s pointer matches *t then u have two choice either take in the subsequence or leave - recurrsence become: dp\[i]\[j]= dp\[i-1]\[j] + dp\[i-1]\[j-1]
- now if it doest equal then simply continue the pointer of s untill equal - transititon : dp\[i]\[j]=dp\[i-1]\[j]
