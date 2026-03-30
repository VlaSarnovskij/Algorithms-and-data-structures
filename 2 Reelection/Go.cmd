if .%USERDOMAIN% == .DESKTOP-41MR8N8 goto :savasPC

Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
mingw32-make.exe

:toliau
echo 4 2 5 > test1.txt
echo 1 2 3 4 >> test1.txt
program.exe test1.txt
program.exe test1.txt > result1.txt

echo 5 3 8 > test2.txt
echo 1 2 3 4 5 >> test2.txt
program.exe test2.txt
program.exe test2.txt > result2.txt

echo 14 4 15 > test3.txt
echo 1 2 3 4 5 6 7 8 >> test3.txt
echo 10 11 14 15 17 20 >> test3.txt
program.exe test3.txt
program.exe test3.txt > result3.txt


echo 11 7 20 > test4.txt
echo 1 1 2 2 5 5 6 6 8 8 10 >> test4.txt
program.exe test4.txt
program.exe test4.txt > result4.txt

mingw32-make.exe clean