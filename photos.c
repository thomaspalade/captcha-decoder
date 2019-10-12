#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma pack(1)

struct bmp_fileheader
{
    unsigned char  fileMarker1; /* 'B' */
    unsigned char  fileMarker2; /* 'M' */
    unsigned int   bfSize; /* File's size */
    unsigned short unused1;
    unsigned short unused2;
    unsigned int   imageDataOffset; /* Offset to the start of image data */
};

struct bmp_infoheader
{
    unsigned int   biSize; /* Size of the info header - 40 bytes */
    signed int     width; /* Width of the image */
    signed int     height; /* Height of the image */
    unsigned short planes;
    unsigned short bitPix;
    unsigned int   biCompression;
    unsigned int   biSizeImage; /* Size of the image data */
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
};

#pragma pack()

struct matrice
{
    char c;
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

struct pozitii
{
    int i;
    int x;
    int y;
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

struct culoare
{
    unsigned int R;
    unsigned int G;
    unsigned int B;
};


int Bine (int i, int j, int height, int width, char mat[110][110])
{
    if (i == height + 1 || i == 0) return 0;
    if (j == width  + 1 || j == 0) return 0;
    if (mat[i][j] != 'x') return 0;
    return 1;
}

void MBine (int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MAT[i][j].c = 'x';
    MAT[i][j].R = R;
    MAT[i][j].G = G;
    MAT[i][j].B = B;
}

int Zero (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i, j+1, height, width, mat) && Bine(i, j+2, height, width, mat)
        && Bine(i, j+3, height, width, mat) &&  Bine(i, j+4, height, width, mat)
        &&  Bine(i+1, j, height, width, mat) && Bine(i+2, j, height, width, mat)
        && Bine(i+3, j, height, width, mat) && Bine(i+4, j, height, width, mat)
        &&  Bine(i+1, j+4, height, width, mat) && Bine(i+2, j+4, height, width, mat)
        && Bine(i+3, j+4, height, width, mat) && Bine(i+4, j+4, height, width, mat)
        &&  Bine(i+4, j+1, height, width, mat) && Bine(i+4, j+2, height, width, mat)
        && Bine(i+4, j+3, height, width, mat))
        return 1;
    return 0;
}

void Pune_0(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j, R, G, B, MAT),     MBine(i, j+1, R, G, B, MAT),   MBine(i, j+2, R, G, B, MAT),
    MBine(i, j+3, R, G, B, MAT),   MBine(i, j+4, R, G, B, MAT),   MBine(i+4, j, R, G, B, MAT);
    MBine(i+1, j, R, G, B, MAT),   MBine(i+2, j, R, G, B, MAT),   MBine(i+3, j, R, G, B, MAT);
    MBine(i+4, j+1, R, G, B, MAT), MBine(i+4, j+2, R, G, B, MAT), MBine(i+4, j+3, R, G, B, MAT);
    MBine(i+1, j+4, R, G, B, MAT), MBine(i+2, j+4, R, G, B, MAT), MBine(i+3, j+4, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT);
}

int Unu (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i+1, j, height, width, mat) && Bine(i+2, j, height, width, mat)
         && Bine(i+3, j, height, width, mat) && Bine(i+4, j, height, width, mat)
            &&  !Bine(i, j-1, height, width, mat) && !Bine(i+1, j-1, height, width, mat) && !Bine(i+2, j-1, height, width, mat)
         && !Bine(i+3, j-1, height, width, mat) && !Bine(i+4, j-1, height, width, mat)
            &&  !Bine(i, j-2, height, width, mat) && !Bine(i+1, j-2, height, width, mat) && !Bine(i+2, j-2, height, width, mat)
         && !Bine(i+3, j-2, height, width, mat) && !Bine(i+4, j-2, height, width, mat)
            &&  !Bine(i, j-3, height, width, mat) && !Bine(i+1, j-3, height, width, mat) && !Bine(i+2, j-3, height, width, mat)
         && !Bine(i+3, j-3, height, width, mat) && !Bine(i+4, j-3, height, width, mat))
        return 1;
    return 0;
}

void Pune_1(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    j = j+4;
    MBine(i, j, R, G, B, MAT), MBine(i+1, j, R, G, B, MAT), MBine(i+2, j, R, G, B, MAT), MBine(i+3, j, R, G, B, MAT), MBine(i+4, j, R, G, B, MAT);
}

int Doi (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i, j+1, height, width, mat) && Bine(i, j+2, height, width, mat)
         && Bine(i, j+3, height, width, mat) &&  Bine(i, j+4, height, width, mat)
            &&  Bine(i+2, j, height, width, mat) && Bine(i+2, j+1, height, width, mat) && Bine(i+2, j+2, height, width, mat)
         && Bine(i+2, j+3, height, width, mat) &&  Bine(i+2, j+4, height, width, mat)
            &&  Bine(i+4, j, height, width, mat) && Bine(i+4, j+1, height, width, mat) && Bine(i+4, j+2, height, width, mat)
         && Bine(i+4, j+3, height, width, mat) &&  Bine(i+4, j+4, height, width, mat)
            &&  Bine(i+1, j, height, width, mat) && Bine(i+3, j+4, height, width, mat))
        return 1;
    return 0;
}

void Pune_2(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j, R, G, B, MAT),   MBine(i, j+1, R, G, B, MAT),   MBine(i, j+2, R, G, B, MAT),
    MBine(i, j+3, R, G, B, MAT),   MBine(i, j+4, R, G, B, MAT);
    MBine(i+2, j, R, G, B, MAT), MBine(i+2, j+1, R, G, B, MAT), MBine(i+2, j+2, R, G, B, MAT),
     MBine(i+2, j+3, R, G, B, MAT), MBine(i+2, j+4, R, G, B, MAT);
    MBine(i+4, j, R, G, B, MAT), MBine(i+4, j+1, R, G, B, MAT), MBine(i+4, j+2, R, G, B, MAT),
     MBine(i+4, j+3, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT);
    MBine(i+1,j,R,G,B, MAT), MBine(i+3,j+4,R,G,B, MAT);
}

int Trei (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i, j+1, height, width, mat) && Bine(i, j+2, height, width, mat)
         && Bine(i, j+3, height, width, mat) &&  Bine(i, j+4, height, width, mat) // linie sus
            &&  Bine(i+2, j, height, width, mat) && Bine(i+2, j+1, height, width, mat)
         && Bine(i+2, j+2, height, width, mat) && Bine(i+2, j+3, height, width, mat) &&  Bine(i+2, j+4, height, width, mat)
            &&  Bine(i+4, j, height, width, mat) && Bine(i+4, j+1, height, width, mat) && Bine(i+4, j+2, height, width, mat)
         && Bine(i+4,j+3, height, width, mat) &&  Bine(i+4, j+4, height, width, mat)
            &&  Bine(i+3, j+4, height, width, mat) && Bine(i+1, j+4, height, width, mat))
        return 1;
    return 0;
}

void Pune_3(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j, R, G, B, MAT),    MBine(i, j+1, R, G, B, MAT),    MBine(i, j+2, R, G, B, MAT),
        MBine(i, j+3, R, G, B, MAT),   MBine(i, j+4, R, G, B, MAT); // linie sus
    MBine(i+2, j, R, G, B, MAT),  MBine(i+2, j+1, R, G, B, MAT),  MBine(i+2, j+2, R, G, B, MAT),
      MBine(i+2, j+3, R, G, B, MAT), MBine(i+2, j+4, R, G, B, MAT);
    MBine(i+4, j, R, G, B, MAT),  MBine(i+4, j+1, R, G, B, MAT),  MBine(i+4, j+2, R, G, B, MAT),
      MBine(i+4, j+3, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT);
    MBine(i+3, j+4, R, G, B, MAT),MBine(i+1, j+4, R, G, B, MAT);
}

int Patru (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j+4, height, width, mat) && Bine(i+1, j+4, height, width, mat) && Bine(i+2, j+4, height, width, mat)
         && Bine(i+3, j+4, height, width, mat) && Bine(i+4, j+4, height, width, mat)
            &&  Bine(i+2, j, height, width, mat) && Bine(i+2, j+1, height, width, mat)
         && Bine(i+2, j+2, height, width, mat) && Bine(i+2, j+3, height, width, mat)
        && Bine(i+3, j, height, width, mat) &&  Bine(i+4, j, height, width, mat))
        return 1;
    return 0;
}

void Pune_4(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j+4, R, G, B, MAT),  MBine(i+1, j+4, R, G, B, MAT),   MBine(i+2, j+4, R, G, B, MAT),
    MBine(i+3, j+4, R, G, B, MAT),  MBine(i+4, j+4, R, G, B, MAT);
    MBine(i+2, j, R, G, B, MAT), MBine(i+2, j+1, R, G,B, MAT),  MBine(i+2, j+2, R, G, B, MAT),
    MBine(i+2, j+3, R, G, B, MAT),  MBine(i+3, j, R, G, B, MAT), MBine(i+4, j, R, G, B, MAT);
}

int Cinci (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i, j+1, height, width, mat) && Bine(i, j+2, height, width, mat)
        && Bine(i, j+3, height, width, mat) &&  Bine(i, j+4, height, width, mat) // linie sus
            &&  Bine(i+2, j, height, width, mat) && Bine(i+2, j+1, height, width, mat)
         && Bine(i+2,j+2, height, width, mat) && Bine(i+2, j+3, height, width, mat)
        &&  Bine(i+2, j+4, height, width, mat) &&  Bine(i+4, j, height, width, mat) && Bine(i+4, j+1, height, width, mat)
        && Bine(i+4, j+2, height, width, mat) && Bine(i+4, j+3, height, width, mat) &&  Bine(i+4, j+4, height, width, mat)
            &&  Bine(i+3, j, height, width, mat) && Bine(i+1, j+4, height, width, mat))
        return 1;
    return 0;
}

void Pune_5(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j, R, G, B, MAT),   MBine(i, j+1, R, G, B, MAT),   MBine(i, j+2, R, G, B, MAT),   MBine(i, j+3, R, G, B, MAT),
       MBine(i, j+4, R, G, B, MAT); MBine(i+2, j, R, G, B, MAT), MBine(i+2, j+1, R, G, B, MAT),
     MBine(i+2, j+2, R, G, B, MAT), MBine(i+2, j+3, R, G, B, MAT), MBine(i+2, j+4, R, G, B, MAT);
    MBine(i+4, j, R, G, B, MAT), MBine(i+4, j+1, R, G, B, MAT), MBine(i+4, j+2, R, G, B, MAT),
    MBine(i+4, j+3, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT), MBine(i+3, j, R, G, B, MAT), MBine(i+1, j+4, R, G, B, MAT);
}

int Sase (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i, j+1, height, width, mat) && Bine(i, j+2, height, width, mat)
        && Bine(i,j +3, height,width,mat) &&  Bine(i, j+4, height, width, mat)
            &&  Bine(i+2, j, height, width, mat) && Bine(i+2, j+1, height, width, mat) && Bine(i+2, j+2, height, width, mat)
        && Bine(i+2, j+3, height, width, mat) &&  Bine(i+2, j+4, height, width, mat)
            &&  Bine(i+4, j,height,width,mat) && Bine(i+4, j+1,height,width,mat) && Bine(i+4, j+2,height,width,mat)
        && Bine(i+4, j+3, height, width, mat) &&  Bine(i+4, j+4, height, width, mat)
            &&  Bine(i+1, j, height, width, mat) && Bine(i+1, j+4, height, width, mat) && Bine(i+3, j, height, width,mat))
        return 1;
    return 0;
}

void Pune_6(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j, R, G, B, MAT),   MBine(i, j+1, R, G, B, MAT),   MBine(i, j+2, R, G, B, MAT),
    MBine(i, j+3, R, G, B, MAT),   MBine(i, j+4, R, G, B, MAT);
    MBine(i+2, j, R, G, B, MAT), MBine(i+2, j+1, R, G, B, MAT), MBine(i+2, j+2, R, G, B, MAT),
    MBine(i+2, j+3, R, G, B, MAT), MBine(i+2, j+4, R, G, B, MAT);
    MBine(i+4, j, R, G, B, MAT), MBine(i+4, j+1, R, G, B, MAT), MBine(i+4, j+2, R, G, B, MAT),
    MBine(i+4, j+3, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT);
    MBine(i+1, j, R, G, B, MAT), MBine(i+1, j+4, R, G, B, MAT), MBine(i+3, j, R, G, B, MAT);
}


int Sapte (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j+4, height, width, mat) && Bine(i+1, j+4, height, width,mat) && Bine(i+2, j+4, height, width, mat)
        && Bine(i+3, j+4, height, width, mat) && Bine(i+4, j+4, height, width, mat)
            && Bine(i+4, j,height, width, mat) && Bine(i+4, j+1, height, width, mat)
        && Bine(i+4, j+2, height, width, mat) && Bine(i+4, j+3, height, width, mat))
        return 1;
    return 0;
}

void Pune_7(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j+4, R, G, B, MAT), MBine(i+1, j+4, R, G, B, MAT), MBine(i+2, j+4, R, G, B, MAT),
    MBine(i+3, j+4, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT);
    MBine(i+4, j, R, G, B, MAT), MBine(i+4, j+1, R, G, B, MAT),
    MBine(i+4, j+2, R, G, B, MAT), MBine(i+4, j+3, R, G, B, MAT);
}


int Opt (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i, j+1, height, width, mat) && Bine(i, j+2, height, width, mat)
        && Bine(i, j+3, height, width, mat) &&  Bine(i, j+4, height, width, mat)
            &&  Bine(i+1, j, height, width, mat) && Bine(i+2, j, height, width, mat)
        && Bine(i+3, j, height, width, mat) && Bine(i+4, j, height, width, mat)
            &&  Bine(i+1, j+4, height, width, mat) && Bine(i+2, j+4, height, width, mat)
        && Bine(i+3, j+4, height, width, mat) && Bine(i+4, j+4, height, width, mat)
            &&  Bine(i+4, j+1, height, width, mat) && Bine(i+4, j+2, height, width, mat)
        && Bine(i+4, j+3, height, width, mat)
            &&  Bine(i+2, j+1, height, width, mat) && Bine(i+2, j+2, height, width, mat)
        && Bine(i+2, j+3, height, width, mat))
        return 1;
    return 0;
}

void Pune_8(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j, R, G, B, MAT),     MBine(i, j+1, R, G, B, MAT),    MBine(i, j+2, R, G, B, MAT),    MBine(i, j+3, R, G, B, MAT);
    MBine(i+1, j, R, G, B, MAT),   MBine(i+2, j, R, G, B, MAT),    MBine(i+3, j, R, G, B, MAT),    MBine(i+4, j, R, G, B, MAT);
    MBine(i+1, j+4, R, G, B, MAT), MBine(i+2, j+4, R, G, B, MAT),  MBine(i+3, j+4, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT);
    MBine(i+4, j+1, R, G, B, MAT), MBine(i+4, j+2, R, G, B, MAT), MBine(i+4, j+3, R, G, B, MAT), MBine(i, j+4, R, G, B, MAT);
    MBine(i+2, j+1, R, G, B, MAT), MBine(i+2, j+2, R, G, B, MAT), MBine(i+2, j+3, R, G, B, MAT);
}

int Noua (int i, int j, int height, int width, char mat[110][110])
{
    if (Bine(i, j, height, width, mat) && Bine(i, j+1, height, width, mat) && Bine(i, j+2, height, width, mat)
        && Bine(i, j+3, height, width, mat) &&  Bine(i, j+4, height, width, mat)
            &&    Bine(i+1, j+4, height, width, mat) && Bine(i+3, j, height, width, mat) && Bine(i+3, j+4, height, width, mat)
            &&    Bine(i+2, j,height, width, mat) && Bine(i+2, j+1, height, width, mat) && Bine(i+2, j+2, height, width, mat)
         && Bine(i+2, j+3, height, width, mat) &&  Bine(i+2, j+4, height, width, mat)
            &&    Bine(i+4, j, height, width, mat) && Bine(i+4, j+1, height, width, mat) && Bine(i+4, j+2, height, width, mat)
         && Bine(i+4, j+3, height, width, mat) &&  Bine(i+4, j+4, height, width, mat))
        return 1;
    return 0;
}

void Pune_9(int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    MBine(i, j, R, G, B, MAT),     MBine(i, j+1, R, G, B, MAT),    MBine(i, j+2, R, G, B, MAT),    MBine(i, j+3, R, G, B, MAT);
    MBine(i+1, j+4, R, G, B, MAT), MBine(i+3, j, R, G, B, MAT),    MBine(i+3, j+4, R, G, B, MAT), MBine(i, j+4, R, G, B, MAT);
    MBine(i+2, j, R, G, B, MAT),   MBine(i+2, j+1, R, G, B, MAT),  MBine(i+2, j+2, R, G, B, MAT),  MBine(i+2, j+3, R, G, B, MAT);
    MBine(i+2, j+4, R, G, B, MAT), MBine(i+4, j, R, G, B, MAT),   MBine(i+4, j+1, R, G, B, MAT);
    MBine(i+4, j+2, R, G, B, MAT),  MBine(i+4, j+3, R, G, B, MAT), MBine(i+4, j+4, R, G, B, MAT);
}


int Rezolva(struct pozitii poz[1010], int t[100],  struct matrice MAT[150][150], int height, int width, char mat[110][110])
{
    int i, j;
    int top = 0;
    for (j=1; j<=width; j++)
    {
        for (i=1; i<=height; i++)
        {
            if (Opt(i, j, height, width, mat) == 1)
            {
                t[++top] = 8, poz[top].i = 8;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j].R;
                poz[top].G = MAT[i][j].G;
                poz[top].B = MAT[i][j].B;

            }
            else if (Zero(i, j, height, width, mat) == 1)
            {
                t[++top] = 0, poz[top].i = 0;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j].R;
                poz[top].G = MAT[i][j].G;
                poz[top].B = MAT[i][j].B;
            }
            else if (Noua(i, j, height, width, mat) == 1)
            {
                t[++top] = 9, poz[top].i = 9;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j].R;
                poz[top].G = MAT[i][j].G;
                poz[top].B = MAT[i][j].B;
            }
            else if (Trei(i, j, height, width, mat) == 1)
            {
                t[++top] = 3, poz[top].i = 3;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j].R;
                poz[top].G = MAT[i][j].G;
                poz[top].B = MAT[i][j].B;
            }
            else if (Sase(i, j, height, width, mat) == 1)
            {
                t[++top] = 6, poz[top].i = 6;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j].R;
                poz[top].G = MAT[i][j].G;
                poz[top].B = MAT[i][j].B;
            }
            else if (Doi(i, j, height, width, mat) == 1)
            {
                t[++top] = 2, poz[top].i = 2;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j].R;
                poz[top].G = MAT[i][j].G;
                poz[top].B = MAT[i][j].B;
            }
            else if (Patru(i, j, height, width, mat) == 1)
            {
                t[++top] = 4, poz[top].i = 4;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j+4].R;
                poz[top].G = MAT[i][j+4].G;
                poz[top].B = MAT[i][j+4].B;
            }
            else if (Cinci(i, j, height, width, mat) == 1)
            {
                t[++top] = 5, poz[top].i = 5;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j].R;
                poz[top].G = MAT[i][j].G;
                poz[top].B = MAT[i][j].B;
            }
            else if (Sapte(i, j, height, width, mat) == 1)
            {
                t[++top] = 7, poz[top].i = 7;
                poz[top].y = j;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j+4].R;
                poz[top].G = MAT[i][j+4].G;
                poz[top].B = MAT[i][j+4].B;
            }
            else if (Unu(i, j, height, width, mat) == 1)
            {
                t[++top] = 1, poz[top].i = 1;
                poz[top].y = j-4;
                poz[top].y = j;
                poz[top].x = i;
                poz[top].R = MAT[i][j+4].R;
                poz[top].G = MAT[i][j+4].G;
                poz[top].B = MAT[i][j+4].B;
            }
        }
    }

    return top;
}

void Pune(int cifra, int i, int j, unsigned int R, unsigned int G, unsigned int B, struct matrice MAT[150][150])
{
    if (cifra == 1)
        Pune_1(i, j, R, G, B, MAT);
    else if (cifra == 2)
        Pune_2(i, j, R, G, B, MAT);
    else if (cifra == 3)
        Pune_3(i, j, R, G, B, MAT);
    else if (cifra == 4)
        Pune_4(i, j, R, G, B, MAT);
    else if (cifra == 5)
        Pune_5(i, j, R, G, B, MAT);
    else if (cifra == 6)
        Pune_6(i, j, R, G, B, MAT);
    else if (cifra == 7)
        Pune_7(i, j, R, G, B, MAT);
    else if (cifra == 8)
        Pune_8(i, j, R, G, B, MAT);
    else if (cifra == 9)
        Pune_9(i, j, R, G, B, MAT);
    else if (cifra == 0)
        Pune_0(i, j, R, G, B, MAT);
}

struct culoare Citire(int f[11], char s[100], char c[100], char x[100], char num[100], char t2[100], char t3[100])
{
    FILE *fin;
    fin = fopen("input.txt", "rt");
    struct culoare cool;
    fgets(s, 100, fin);
    s[strlen(s)-1] = 0;

    fgets(num, 100, fin);
    int i=0;
    cool.B = 0;
    cool.G = 0;
    cool.R = 0;

    while (num[i] != ' ')
        cool.B = cool.B*10 + (num[i] - '0'), i++;
    i++;
    while (num[i] != ' ')
        cool.G = cool.G*10 + (num[i] - '0'), i++;
    i++;
    while (num[i] >= '0' && num[i] <= '9')
        cool.R = cool.R*10 + (num[i] - '0'), i++;

    for (i=0; s[i]; i++)
    {
        c[i]  = s[i];
        x[i]  = s[i];
        t2[i] = s[i];
        t3[i] = s[i];
    }

    x[i] = 0;  c[i] = 0;
    t2[i] = 0; t3[i+6] = 0;
    c[i-4] = '_'; c[i-3] = 't';
    t3[i] = 0; c[i-2] = 'a';
    c[i-1] = 's'; t3[i-4] = '_';
    c[i]   = 'k'; c[i+1] = '1';
    t3[i-3] = 't'; c[i+2] = '.';
    c[i+3] = 'b'; t3[i-2] = 'a';
    c[i+4] = 'm'; c[i+5] = 'p';
    t3[i-1] = 's'; c[i+6] = 0;
    t2[i+1] = '2'; t3[i]   = 'k';
    t2[i+2] = '.'; t2[i+3] = 't';
    t3[i+1] = '3'; t2[i+4] = 'x';
    t2[i+5] = 't'; t3[i+2] = '.';
    t2[i+6] = 0; t2[i-4] = '_';
    t3[i+3] = 'b'; t2[i-3] = 't';
    t2[i-2] = 'a'; t3[i+4] = 'm';
    t2[i-1] = 's'; t2[i]   = 'k';
    t3[i+5] = 'p';

    for (i=0; i<=9; i++)
        f[i] = 1;
    num[0] = 0;
    i = 0;
    fgets(num, 100, fin);
    /// acum extrag cifrele din num[]
    while (num[i] >= '0' && num[i] <= '9')
    {
        f[num[i] - '0'] = 0;
        i=i+2;
    }
    return cool;
}


int main ()
{
    FILE *in, *out, *out3, *fout;
    unsigned int B, G, R;
    unsigned char a[90010], b[90010];
    int i, j, f[11];
    char s[100], c[100], x[100], num[100], t2[100], t3[100];
    int height, width;
    char mat[110][110];
    int t[100], top = 0, k = 0, cifra = 0;
    int Height, Width, rest, humble, aux = 0;
    struct culoare cool;

    cool = Citire(f, s, c, x, num, t2, t3);
    R = cool.R;
    G = cool.G;
    B = cool.B;

    struct matrice MAT[150][150];
    struct pozitii poz[1010];

    in   = fopen(x, "rb");
    out  = fopen(c, "wb");
    out3 = fopen(t3, "wb");
    fout = fopen(t2, "wt");

    struct bmp_fileheader X;
    struct bmp_infoheader Y;

    fread(&X,                sizeof(X),   1, in);
    fread(&Y,                sizeof(Y),   1, in);
    fwrite(&X, 		         sizeof(X),   1, out);
    fwrite(&Y,               sizeof(Y),   1, out);
    fwrite(&X, 		         sizeof(X),   1, out3);
    fwrite(&Y,               sizeof(Y),   1, out3);

    height = Y.height;
    width = Y.width;
    Height = height;
    if ((3 * width) % 4 == 0)
        rest = 0;
    else
        rest = 4 - (3 * width) % 4; /// cati octeti de padding mai trebuie sa pun
    Width = 3 * width +rest;   /// latimea reala a matricei ce trebuie citita

    fread(a, 1, Height*Width, in);
    for (i=0; i<Height*Width; i++)
        b[i] = a[i];

    for (i=0; i<Height; i++)
    {
        for (j=0; j<3*width; j=j+3)
        {
            k = i*Width + j;
            if (!(a[k] == 255 && a[k+1] == 255 && a[k+2] == 255))
            {
                MAT[i+1][j/3+1].c = 'x';
                MAT[i+1][j/3+1].R = a[k+2];
                MAT[i+1][j/3+1].G = a[k+1];
                MAT[i+1][j/3+1].B = a[k];
                a[k]   = B;
                a[k+1] = G;
                a[k+2] = R;
                mat[i+1][j/3+1]   = 'x';
            }
            else
            {
                mat[i+1][j/3+1] = '.';
                MAT[i+1][j/3+1].c = '.';
                MAT[i+1][j/3+1].R = 255;
                MAT[i+1][j/3+1].G = 255;
                MAT[i+1][j/3+1].B = 255;
            }
        }
    }

    fwrite(a, 1, Height*Width, out);      /// AFISARE TASK 1
    top = Rezolva(poz, t, MAT, height, width, mat);

    for (i=1; i<=top; i++)
    {
        if (poz[i].i == 1)
        {
            poz[i].y = poz[i].y - 4;
            poz[i].R = MAT[poz[i].x][poz[i].y+4].R;
            poz[i].G = MAT[poz[i].x][poz[i].y+4].G;
            poz[i].B = MAT[poz[i].x][poz[i].y+4].B;
        }
    }

    for (i=1; i<=top; i++)
    {
        if (f[poz[i].i] == 0)
            poz[i].i = -1;
    }

    for (i=1; i<top; i++)
        if (t[i] == 0 && t[i+1] == 1)
       {
           aux = t[i];
           t[i] = t[i+1];
           t[i+1] = aux;
       }

    for (i=1; i<=top; i++)
        fprintf(fout, "%d", t[i]);   /// AFISARE
    fprintf(fout, "\n");             /// TASK 2


    humble = 0;
    while (humble == 0)
    {
        for (i=1; i<=top; i++)
        {

            if (poz[i].i == -1)
            {
                top--;
                for (j=i; j<=top; j++)
                {
                    poz[j].i = poz[j+1].i;
                    poz[j].R = poz[j+1].R;
                    poz[j].G = poz[j+1].G;
                    poz[j].B = poz[j+1].B;
                }
            }

            humble = 1;
            for (j=1; j<=top && humble ==1; j++)
                if (poz[j].i == -1) humble=0;
        }
    }

    for (i=1; i<=Height; i++)
    {
        for (j=1; j<=width; j++)
        {
            MAT[i][j].R = 255;
            MAT[i][j].G = 255;
            MAT[i][j].B = 255;
            MAT[i][j].c = '.';
        }
    }

    for (k=1; k<=top; k++)
    {
        i = poz[k].x;
        j = poz[k].y;
        cifra = poz[k].i;
        R = poz[k].R;
        G = poz[k].G;
        B = poz[k].B;
        /// am	 cifra "cifra" care incepe (rasturnata) la pozitia i,j  si e de culoarea RGB,
        /// deci practic tre sa colorez vreo 5-23 locuri din matrice de fiecare data
        Pune(cifra, i, j, R, G, B, MAT);
    }

    /// teoretic eu acum ar trebui sa am matricea MAT[][] codificata corespunzator si tot ce trebuie sa fac
    /// e sa o bag intr-un vector si sa o printez in fisierul binar

    for (i=0; i<Height; i++)
    {
        for (j=0; j<3*width; j=j+3)
        {
            k = i*Width + j;
            if (MAT[i+1][j/3+1].c == 'x')
            {
                b[k+2] = MAT[i+1][j/3+1].R;
                b[k+1] = MAT[i+1][j/3+1].G;
                b[k]   = MAT[i+1][j/3+1].B;
            }
            else
            {
                b[k+2] = 255;
                b[k+1] = 255;
                b[k]   = 255;
            }
        }
    }

    fwrite(b, 1, Height*Width, out3);   /// AFISARE TASK 3
    fclose(in);
    fclose(out);
    fclose(out3);
    fclose(fout);
    return 0;
}
