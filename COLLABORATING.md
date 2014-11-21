# Kode til projektet #

**Bemærk: Tekst mellem < og > betyder "indsæt egen tekst her", og krokodille-næbbene skal IKKE med. Feks. kan du indsætte `menusystem` i stedet for `<ny-branch-navn>`.**

1. Klon repo Semesterprojekt2  
`git clone git@github.com:dentych/Semesterprojekt2.git`

2. Lav en ny branch  
`git checkout -b <ny-branch-navn>`  
Giv branchen et navn, der kort giver en idé om, hvad branchen indeholder kode til. (F.eks. seriel, ny-menu, nasa-rumskib-software).

3. Skriv kode, det bedste du har lært.

4. Test det kode du har lavet

5. Commit ændringen  
Hvis du kun har ændret i eksisterende filer:  
`git commit -a`  
Hvis du har lavet nye filer:  
`git add <ny-fil-sti>` (f.eks. `git add STK500/NytProgram.cpp`)  
`git commit -a`

6. Enten fortsæt med at skrive mere kode efter commit'en (gå tilbage til pkt. 3)  
Eller hvis du er færdig - push.

7. Push til remote repo:  
`git push origin <branch-navn>`

Hvis du får fejl, kontakt @dentych .

## Opsætte Visual Studio ##
* Lav en ny mappe til dine Visual Studio projekter
 * (Jeg har lavet min i min GitHub mappe.)
* Lav et nyt projekt i din nye mappe. Kald projektet "Semesterprojekt2".
* Når du er i projektet skal du højre-klikke på din solution "Semesterprojekt2" i højre side.
* Vælg Properties
* Vælg "VC++ Directories" i venstre side
* Tilføj din GitHub mappes sti til "Include Directories"
 * Min sti er f.eks. `C:\Users\Dennis\Documents\Github`
* Vælg "Add existing item" og tilføj De filer du vil bruge fra Semesterprojekt2 git repoet.
* Skrive kode!

## Opsætte Atmel Studio ##
Kommer snart.