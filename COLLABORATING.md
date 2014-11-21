# Kode til projektet #

**Bem�rk: Tekst mellem < og > betyder "inds�t egen tekst her", og krokodille-n�bbene skal IKKE med. Feks. kan du inds�tte `menusystem` i stedet for `<ny-branch-navn>`.**

1. Klon repo Semesterprojekt2  
`git clone git@github.com:dentych/Semesterprojekt2.git`

2. Lav en ny branch  
`git checkout -b <ny-branch-navn>`  
Giv branchen et navn, der kort giver en id� om, hvad branchen indeholder kode til. (F.eks. seriel, ny-menu, nasa-rumskib-software).

3. Skriv kode, det bedste du har l�rt.

4. Test det kode du har lavet

5. Commit �ndringen  
Hvis du kun har �ndret i eksisterende filer:  
`git commit -a`  
Hvis du har lavet nye filer:  
`git add <ny-fil-sti>` (f.eks. `git add STK500/NytProgram.cpp`)  
`git commit -a`

6. Enten forts�t med at skrive mere kode efter commit'en (g� tilbage til pkt. 3)  
Eller hvis du er f�rdig - push.

7. Push til remote repo:  
`git push origin <branch-navn>`

Hvis du f�r fejl, kontakt @dentych .

## Ops�tte Visual Studio ##
* Lav en ny mappe til dine Visual Studio projekter
 * (Jeg har lavet min i min GitHub mappe.)
* Lav et nyt projekt i din nye mappe. Kald projektet "Semesterprojekt2".
* N�r du er i projektet skal du h�jre-klikke p� din solution "Semesterprojekt2" i h�jre side.
* V�lg Properties
* V�lg "VC++ Directories" i venstre side
* Tilf�j din GitHub mappes sti til "Include Directories"
 * Min sti er f.eks. `C:\Users\Dennis\Documents\Github`
* V�lg "Add existing item" og tilf�j De filer du vil bruge fra Semesterprojekt2 git repoet.
* Skrive kode!

## Ops�tte Atmel Studio ##
Kommer snart.