Semesterprojekt2
================

Semesterprojekt til 2. semester.

Dette repo indeholder source-koden til hele vores system.

For at skrive kode til projektet (og dette repo): [COLLABORATING](https://github.com/dentych/Semesterprojekt2/blob/master/COLLABORATING.md)

Dette indebærer
* PC der kører menu-system
* STK500 controller der gemmer rutiner og sørger for at køre dem (ved at sende data vha. X10 protokollen på et 18V elnet)
* En modtager-STK500 som aflæser X10 data sendt gennem senderen.

Der skal laves følgende
* [X] Menu-system
* [X] Menu - Start rutine
* [X] Menu - Stop rutine
* [X] Menu - Oprette rutine
* [X] Menu - Ændre rutine
* [X] Seriel kommunikation (protokol+implementering)
* [X] Routine-klasse
* [X] Sender - Modtage data fra PC serielt
* [X] Sender - Oplåsning/låsning vha. interrupt
* [X] Sender - 120 kHz signal (timer)
* [X] Sender - Køre rutiner (sende tænd/sluk til lys og vente)
* [X] Sender - X10 protokol (sende data til X10 modtagerne)
* [X] Modtager - Modtage data over X10 protokol
* [X] Modtager - Aflæse data ved zero cross (interrupt + aflæsning af 0/1 på databen)
* [ ] Evt. andet
