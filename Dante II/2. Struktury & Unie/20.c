#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

void getstr(char *nz, int n) {
    char ch = getchar();
    int i = 0;
    while (i < n && ch != '\n') {
        *(nz + i) = ch;
        ch = getchar();
        ++i;
    }
    *(nz + i) = '\0';
    if (i == n && ch != '\n')
        while (getchar() != '\n');


}

struct bajt {
    unsigned char b0: 1;
    unsigned char b1: 1;
    unsigned char b2: 1;
    unsigned char b3: 1;
    unsigned char b4: 1;
    unsigned char b5: 1;
    unsigned char b6: 1;
    unsigned char b7: 1;
};

union bitsy {
    unsigned char tk;
    struct bajt b;
};

int encode(const char *input, char *txt, const char *output) {
    if (input == NULL || txt == NULL || output == NULL)
        return 1;
    FILE *fi = fopen(input, "r");
    if (fi == NULL) {
        return 2;
    }
    FILE *fo = fopen(output, "w");
    if (fo == NULL) {
        fclose(fi);
        return 4;
    }
    unsigned char tab[1000][1000] = {0};
    int i = 0;
    union bitsy xd;
    xd.tk = 0;
    xd.b.b0 = 0;
    xd.b.b1 = 0;
    xd.b.b2 = 0;
    xd.b.b3 = 0;
    xd.b.b4 = 0;
    xd.b.b5 = 0;
    xd.b.b6 = 0;
    xd.b.b7 = 0;

    fpos_t pos;
    fgetpos(fi, &pos);
    while (!feof(fi)) {
        char p = fgetc(fi);
        if (!isdigit(p) && p != '\0' && p != '\n' && p != ' ' && p != EOF) {
            fclose(fi);
            fclose(fo);
            return 3;
        }
    }
    fsetpos(fi, &pos);

    int w = 0, kol = 0, t, q = 0;

    fgetpos(fi, &pos);
    while (!feof(fi)) {
        char ch = fgetc(fi);
        if (ch == '\n') {
            q++;
        }
    }
    fsetpos(fi, &pos);
    w = q;

    int x;
    fgetpos(fi, &pos);
    q = 0;
    while (!feof(fi)) {
        t = fscanf(fi, "%d", &x);
        if (t != 1) {
            break;
        }
        q++;
    }
    kol = w == 0 ? q : q / w;
    fsetpos(fi, &pos);

    if (q / 8 < (int) strlen(txt)) {
        fclose(fi);
        fclose(fo);
        return 3;
    }
    int nw = 0, nk = 0;
    fgetpos(fi, &pos);
    int u = 0;
    while (!feof(fi)) {
        if (u == q)
            break;
        if (nk == kol) {
            nk = 0;
            nw++;
        }
        t = fscanf(fi, "%hhu", (*(tab + nw) + nk));
        if (t != 1) {
            fclose(fi);
            fclose(fo);
            return 3;
        }
        u++;
        nk++;
    }
    fsetpos(fi, &pos);

    nw = 0, nk = 0;
    u = 0;

    while (u < kol * w) {
        xd.tk = (unsigned char) *(txt + i);
        int k = 0;
        ++i;
        while (k < 8) {
            if (nk == kol) {
                nk = 0;
                nw++;
            }
            *(*(tab + nw) + nk) &= 0xFE;
            *(*(tab + nw) + nk) += xd.b.b7;
            xd.tk <<= 1;
            nk++;
            ++k;
            ++u;
        }
        if (u == (int) strlen(txt)*8)
            break;
    }

    while (u < kol * w) {
        if (nk == kol) {
            nk = 0;
            nw++;
        }
        if(*(*(tab + nw) + nk)%2==1)
            *(*(tab + nw) + nk) -= 1;
        nk++;
        ++u;
    }


    nw = 0, nk = 0;
    u = 0;
    while (!feof(fi)) {
        if (u == q)
            break;
        if (nk == kol) {
            nk = 0;
            nw++;
            fputc('\n', fo);
        }
        fprintf(fo, "%hhu ", *(*(tab + nw) + nk));
        nk++;
        u++;
    }

    fclose(fi);
    fclose(fo);

    return 0;
}


int decode(const char *filename, char *txt, int size) {
    if (filename == NULL || txt == NULL || size <= 0)
        return 1;
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return 2;
    }
    int i = 0;
    while (!feof(f)) {
        if (i == size - 1)
            break;
        union bitsy xd;
        int k = 0;
        unsigned char ch = 0;
        while (k < 8) {
            ch = ch << 1;
            int t = fscanf(f, "%hhu", &xd.tk);
            if (t != 1) {
                fclose(f);
                return 3;
            }
            ch += xd.b.b0;
            ++k;
        }

        *(txt + i) = (char) ch;
        if (ch == '\0')
            break;
        ++i;

    }
    *(txt + i) = '\0';
    fclose(f);
    return 0;
}

int main() {
    char c;
    int t;
    printf("Daj: ");
    scanf("%c", &c);
    if (c == 'e' || c == 'E') {
        char txt[1001];
        char nz[30];
        char nz1[30];
        while (getchar() != '\n');
        printf("Daj: ");
        getstr(txt, 1001);
        printf("Daj: ");
        getstr(nz, 29);
        printf("Daj: ");
        getstr(nz1, 29);
        t = encode(nz, txt, nz1);
        if (t == 1) {
            printf("Incorrect input");
            return 1;
        }
        else if (t == 2) {
            printf("Couldn't open file");
            return 4;
        }
        else if (t == 4) {
            printf("Couldn't create file");
            return 5;
        }
        else if (t == 3) {
            printf("File corrupted");
            return 6;
        }
        printf("File saved");
    } else if (c == 'd' || c == 'D') {
        char txt[1001];
        char nz[30];
        while (getchar() != '\n');
        printf("Daj: ");
        getstr(nz, 29);
        t = decode(nz, txt, 1000);
        if (t == 1) {
            printf("Incorrect input");
            return 1;
        }
        if (t == 2) {
            printf("Couldn't open file");
            return 4;
        }
        if (t == 3) {
            printf("File corrupted");
            return 6;
        }
        printf("%s", txt);
    } else {
        printf("Incorrect input data");
        return 1;
    }
    return 0;
}


