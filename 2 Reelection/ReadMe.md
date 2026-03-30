# 2 Laboratorinis darbas: Perrinkimas

1 užduotis: Iš duotų N natūrinių skaičių išrinkti M skaičių taip, kad jų suma būtų lygi S. Vartotojas nurodo failą, iš kurio programa įveda pradinius N skaičių, bei skaičius M ir S.

**Algoritmas**: realizuotas funkcijoje backtrack(Reelection* r). Siekiant pagreitinti darbą, algoritmas nutraukia šakos peržiūrą, jei: 
- Dabartinė suma viršija tikslinę sumą. 
- Pasiekiama masyvo pabaiga, bet reikalavimai netenkinami.

##  Kompiliavimas ir paleidimas

Paleidžiant programą per terminalą, galima nurodyti šiuos parametrus:

- **-mode fullSearch** - Pilna paieška	
- **-mode firstMatchSearch** - Pirmo atitikmens paieška
- **-timeout [ms]**	- Laiko limitas	

*pvz.:*
```cmd
./program.exe duomenys.txt -mode fullSearch 
```

## Statistika ir analizė

Baigusi darbą, programa išveda statistiką (statistics_to_string):

- Total combinations to check
- Combinations checked
- Progress - Parodo santykį tarp teorinio maksimumo ir realiai patikrintų šakų.