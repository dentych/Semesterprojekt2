# Kode til projektet #

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