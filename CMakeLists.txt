cmake_minimum_required(VERSION 3.27)
project(Olymp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task1 task1.cpp bits/stdc++.h)
add_executable(Task2 task2.cpp bits/stdc++.h)
add_executable(Task3 task3.cpp bits/stdc++.h)
add_executable(Task4 task4.cpp bits/stdc++.h)
add_executable(Task5 task5.cpp bits/stdc++.h)

add_executable(Z-func algo/Z-func.cpp bits/stdc++.h)

add_executable(Kmp algo/Kmp.cpp bits/stdc++.h)

add_executable(IncreasingSequence algo/IncreasingSequence.cpp bits/stdc++.h)
add_executable(SegTree algo/SegTree.cpp bits/stdc++.h)