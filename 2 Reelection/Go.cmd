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
echo PIRMAS TESTAS  
program.exe test1.txt
program.exe test1.txt > result1.txt


mingw32-make.exe clean