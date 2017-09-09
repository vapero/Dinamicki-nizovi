# Dinamički-nizovi

Dinamička dodela memorije omogućava rad s nizovima upravo onolike veličine koliko elemenata je potrebno da ti nizovi sadrže datog momenta.

Na primer, sa
```C
int *p = malloc(n * sizeof (int));
```
dobija se prostor u koji mogu da stanu **n** celih brojeva.

**Adresa** pojedinih brojeva može da se dobije pomoću `p + i`, a njihove **vrednosti** sa `*(p + i)`  ili  `p[i]`

## Matrice

Za dvodimenzionalan niz, odnosno matricu sa *m* x *n* elemenata treba dodeliti memoriju naredbom
```C
double *p = malloc(m * n * sizeof (double));
```
Posle toga, element matrice, `a[i,j]` može se dobiti izrazom `a[i*n+j]`. 

Karakteristika prikazanog načina stvaranja dinamičkog višedimenzionalnog niza jeste da se svi elementi, bez obzira na dimenzionalnost, smeštaju u jedan blok uzastopnih memorijskih lokacija. Takođe, nema dodatnog utroška memorije, osim za jedan pokazivač na sam početak niza.

### Matrica kao niz pokazivača

Ovo je u neku ruku fleksibilniji način. Može se realizovati korišćenjem pokazivača, tako da komponentni nizovi budu medjusobno **nezavisno** smešteni u memoriji. U tu svrhu treba da se obrazuje niz pokazivača od kojih svaki pokazuje na jedan od komponentnih nizova.

Niz *a* je niz pokazivača, na primer `int *[]`, pa je `a[i]` adresa i-tog niza/vrste. Adresa elementa matrice, `a[i,j]` može se dobiti izrazom `a[i]+j`, a vrednost tog elementa je `*(a[i]+j)`. 

Sledeći program stvara celobrojnu matricu od *m* vrsta i *n* kolona pomoću *m* **nezavisnih** nizova od po *n* elemenata u dinamičkoj zoni memorije.

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *a[20];
  int m, n;
  
  scanf("%d %d", &m, &n);
  
  //Stvaranje matrice
  for(int i=0; i<m; i++)
  {
    a[i]=malloc(n*sizeof(int));
    for(int j=0; j<n; j++)
      printf("%4.4d", *(a[i]+j)=100*i+j);
    printf("\n");
  }
  
  //Unistavanje matrice
  for(int i=0; i<m; i++) free(a[i]);
}
```
Umesto `*(a[i]+j)` moglo se slobodno pisati `a[i][j]`, a takodje i `*(*(a+i)+j)`.

Prethodno formirana matrica nije prava dinamička matrica, jer je veličina niza pokazivača na matrice definisana statički. To nameće ograničenja za maksimalni broj vrsta matrice. **Vrlo lako može da se oslobodi i tog ograničenja ako se za pristup matrici statički predvidi samo jedan skalaran pokazivač, a niz pokazivača na vrste matrice se stvara dinamički.**

### Matrica kao pokazivač na pokazivače

U sledećem programu se za potrebe pristupa matrici tipa **int**, sa `**a` definiše samo skalaran pokazivač na pokazivače na celobrojne podatke.

```C

```
