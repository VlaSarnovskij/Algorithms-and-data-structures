if .%USERDOMAIN% == .DESKTOP-41MR8N8 goto :savasPC

Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
mingw32-make.exe

:toliau
echo 30  days > params.txt
echo 300  A (Franchise) >> params.txt
echo 100  A1 (Bonus) >> params.txt
echo 25   U (Wage) >> params.txt
echo 2    K (Workers) >> params.txt
echo 20   T1 (VIP prob %%) >> params.txt
echo 50   T2 (Regular prob %%) >> params.txt

KaskoSim.exe params.txt -rnd 50 > result1.txt

echo 30  days > KaskoSim.cfg
echo 500  A (Franchise) >> KaskoSim.cfg
echo 150  A1 (Bonus) >> KaskoSim.cfg
echo 30   U (Wage) >> KaskoSim.cfg
echo 3    K (Workers) >> KaskoSim.cfg
echo 10   T1 (VIP prob %%) >> KaskoSim.cfg
echo 40   T2 (Regular prob %%) >> KaskoSim.cfg

KaskoSim.exe > result2.txt
pause