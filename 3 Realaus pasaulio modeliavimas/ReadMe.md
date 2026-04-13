# Kasko draudimo / autoserviso simuliacija (3-as laboratorinis)
 
Simuliuojamas autoservisas su dviejų tipų klientais: VIP (frančizė A, servisas gauna A1 priedo) ir paprastais (frančizė B = A - A1). VIP klientai aptarnaujami pirmiausiai, prireikus dirbami viršvalandžiai (mokant darbuotojams dvigubai). Modeliuojama kuri strategija servisui naudingesnė - turėti bendradarbiavimo sutartis ar dirbti be jų.
 
## Panaudoti ADT
 
Darbe panaudoti du abstraktūs duomenų tipai:
 
- **Prioritetinė eilė** (`priorityQueue`) - paimta iš dėstytojo puslapio (1lugu2023). Rasta defektų: 0;
- **Ilgas sveikasis skaičius** (`BigInteger`) — paimta iš dėstytojo puslapio (1masi2289). Rasta defektų: 0.
 
## Bendravimas ir bendradarbiavimas
 
 
 
## Algoritmo aprašymas
 
Kiekviena simuliacijos iteracija atitinka vieną valandą. Kiekvienos valandos eigoje:
 
1. Dienų ciklas: Simuliacija kartojama nurodytą dienų skaičių, išlaikant nebaigtus darbus ir eilę iš praėjusios dienos.
2. Klientų atvykimas: Per pirmąsias 8 valandas (darbo laiką) pagal tikimybes T1 ir T2 į prioritetinę eilę generuojami VIP arba įprasti klientai.
3. Užduočių paskirstymas: Laisvi meistrai ima automobilius iš eilės: darbo laiku bet kokius, viršvalandžių metu tik VIP tipo.
4. Darbo procesas: Kiekvieną valandą meistrai mažina likusį remonto laiką, tačiau po 16:00 val. dirbama tik prie VIP automobilių.
5. Atlyginimų skaičiavimas: Naudojant BigInteger, už kiekvieną darbo valandą pridedamas atlyginimas U, o viršvalandžių metu už VIP remontą – dvigubas tarifas 2 * U.
6. Rezultatų fiksavimas: Kiekvienas VIP klientas iškart padidina bonus_income kintamąjį sutarties premija A1.
7. Galutinis pelnas: Simuliacijos pabaigoje pelnas apskaičiuojamas iš visų premijų sumos atimant sukauptas išlaidas viršvalandžiams.
 
## Programos naudojimas
 
### Sukompiliuoti:
```cmd
make
```
arba 
```cmd
mingw32-make.exe
```
 
### Paleisti su parametrų failu:
```cmd
KaskoSim.exe params.txt -rnd 50
```
 
### Paleisti be parametrų failo (automatiškai ieško `KaskoSim.cfg`):
```cmd
KaskoSim.exe
```
 
Rezultatai išsaugomi į `result1.txt` ir `result2.txt` paleidus `Go.cmd`.
 
## Pastabos
 
- `BigInt` naudojamas pelno skaičiavimui, kad būtų išvengta sveikųjų skaičių perpildymo.
- **Darbuotojų skaičiaus įtaka:** Pastebėta, kad esant mažam darbuotojų skaičiui (K), VIP klientų viršvalandžiai mažina pelną, nes jų aptarnavimo laikas (iki 5*K valandų) dažnai viršija standartinę 8 valandų darbo dieną.
- **Sutarčių nauda:** Bendradarbiavimo sutartys (VIP) yra pelningos tik tada, kai A1 (priedas) yra didesnis už potencialias išlaidas viršvalandžiams. Jei vidutinis taisymo laikas ilgas, servisas patiria nuostolį dėl dvigubai didesnių algų darbuotojams už kiekvieną papildomą darbo valandą.
- **Eilės efektyvumas:** Prioritetinė eilė reikalinga, kad paprasti klientai (prioritetas 0) būtų aptarnaujami tik tada, kai nėra laukiančių VIP klientų, tačiau VIP klientai su prioritetu 1 vis tiek gali laukti, jei visi darbuotojai užimti.
 