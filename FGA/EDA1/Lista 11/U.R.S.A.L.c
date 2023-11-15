#include <stdio.h>
#include <string.h>
#define EXC(A, B)     \
    Candidato tt = A; \
    A = B;            \
    B = tt

typedef struct
{
    int num;
    int votos;
} Candidato;

Candidato pre[91], sena[901], dfed[9001], dest[90001];

int binarySearch(Candidato *vetor, int start, int end, int search)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (vetor[i].num == search)
        {
            return i;
        }
    }
    return -1;
}

int separa(Candidato *V, int l, int r)
{
    Candidato c = V[r];
    int j = l, k;
    for (k = l; k < r; k++)
        if (V[k].votos > c.votos)
        {
            EXC(V[k], V[j]);
            j++;
        }
    EXC(V[j], V[r]);
    return j;
}

void quicksort(Candidato *v, int l, int r)
{
    if (r <= l)
        return;

    int mid = (l + r) / 2;
    if (v[mid].votos > v[r].votos)
    {
        Candidato temp = v[mid];
        v[mid] = v[r];
        v[r] = temp;
    }
    if (v[l].votos > v[mid].votos)
    {
        Candidato temp = v[l];
        v[l] = v[mid];
        v[mid] = temp;
    }
    if (v[mid].votos > v[r].votos)
    {
        Candidato temp = v[mid];
        v[mid] = v[r];
        v[r] = temp;
    }

    int j = separa(v, l, r);
    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}

int main()
{
    int sen, fed, est, validos = 0, invalidos = 0, votonum, recep;
    int tp = 0, ts = 0, tf = 0, te = 0, i, j, k; // contadores
    int votosP = 0;
    char voto[6];
    scanf("%d %d %d", &sen, &fed, &est);

    while (scanf("%s", voto) == 1)
    {
        votonum = atoi(voto);
        if (votonum < 0)
        {
            invalidos++;
            continue;
        }
        else
        {
            validos++;
        }

        switch (strlen(voto))
        {
        case 2:
            // presidente
            recep = binarySearch(pre, 0, tp, votonum);
            votosP++;
            // se houver
            if (recep != -1)
            {
                pre[recep].votos++;
            }
            else
            {
                pre[tp].num = votonum;
                pre[tp].votos++;
                tp++;
            }
            break;

        case 3:
            recep = binarySearch(sena, 0, ts, votonum);
            // se houver
            if (recep != -1)
            {
                sena[recep].votos++;
            }
            else
            {
                sena[ts].num = votonum;
                sena[ts].votos++;
                ts++;
            }
            break;
        case 4:
            recep = binarySearch(dfed, 0, tf, votonum);
            // se houver
            if (recep != -1)
            {
                dfed[recep].votos++;
            }
            else
            {
                dfed[tf].num = votonum;
                dfed[tf].votos++;
                tf++;
            }
            break;
        case 5:
            recep = binarySearch(dest, 0, te, votonum);
            // se houver
            if (recep != -1)
            {
                dest[recep].votos++;
            }
            else
            {
                dest[te].num = votonum;
                dest[te].votos++;
                te++;
            }
            break;
        }
    }

    quicksort(pre, 0, tp - 1);
    quicksort(dest, 0, te - 1);
    quicksort(dfed, 0, tf - 1);
    quicksort(sena, 0, ts - 1);

    int kk;
    for (kk = 0; kk < tp; kk++)
    {
        printf("%d %d\n", pre[kk].num, pre[kk].votos);
    }

    printf("%d %d\n", validos, invalidos);

    if ((double)pre[0].votos / votosP >= 0.51)
    {
        printf("%d\n", pre[0].num);
    }
    else
    {
        printf("Segundo turno\n");
    }

    int ka;
    for (ka = 0; ka < ts - 1; ka++)
    {
        if (sena[ka].votos == sena[ka + 1].votos && sena[ka + 1].num > sena[ka].num)
        {
            EXC(sena[ka], sena[ka + 1]);
        }
    }
    for (i = 0; i < sen; i++)
    {
        printf("%d", sena[i].num);
        i + 1 == sen ? printf("\n") : printf(" ");
    }

    int kb;
    for (kb = 0; kb < tf - 1; kb++)
    {
        if (dfed[kb].votos == dfed[kb + 1].votos && dfed[kb + 1].num > dfed[kb].num)
        {
            EXC(dfed[kb], dfed[kb + 1]);
        }
    }

    for (j = 0; j < fed; j++)
    {
        printf("%d", dfed[j].num);
        j + 1 == fed ? printf("\n") : printf(" ");
    }

    int kc;
    for (kc = 0; kc < te - 1; kc++)
    {
        if (dest[kc].votos == dest[kc + 1].votos && dest[kc + 1].num > dest[kc].num)
        {
            EXC(dest[kc], dest[kc + 1]);
        }
    }

    for (k = 0; k < est; k++)
    {
        printf("%d", dest[k].num);
        k + 1 == est ? printf("\n") : printf(" ");
    }

    return 0;
}