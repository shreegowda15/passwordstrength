#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 200
char *com[] = {
    "123456", "password", "12345678", "qwerty", "abc123",
    "111111", "123123", "dragon", "letmein", "monkey"
};
int com_n = 10;
int chk_com(char p[]) {
    for (int i = 0; i < com_n; i++)
        if (strcmp(p, com[i]) == 0) return 1;
    return 0;
}
int chk_seq(char p[], int n) {
    for (int i = 0; i < n - 2; i++) {
        char a = p[i], b = p[i+1], c = p[i+2];

        if (isalpha(a)) a = tolower(a);
        if (isalpha(b)) b = tolower(b);
        if (isalpha(c)) c = tolower(c);

        if (b == a + 1 && c == b + 1) return 1; // ascending
        if (b == a - 1 && c == b - 1) return 1; // descending
    }
    return 0;
}
int sc(char p[], int n, double *ent) {
    int low = 0, up = 0, dig = 0, sp = 0;
    int pool = 0, s = 0;
    if (n < 8) {
        *ent = 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        unsigned char c = p[i];
        if (islower(c)) low = 1;
        else if (isupper(c)) up = 1;
        else if (isdigit(c)) dig = 1;
        else sp = 1;
    }
    if (low) pool += 26;
    if (up)  pool += 26;
    if (dig) pool += 10;
    if (sp)  pool += 30;
    if (pool == 0) pool = 30;
    *ent = n * (log(pool) / log(2.0));
    if (n <= 11) s += 25;
    else if (n <= 15) s += 35;
    else s += 45;
    if (low) s += 8;
    if (up)  s += 8;
    if (dig) s += 8;
    if (sp)  s += 10;
    if (!chk_seq(p, n)) s += 10;
    if (!chk_com(p)) s += 10;
    if (*ent >= 60) s += 10;

    if (s > 100) s = 100;
    return s;
}
char* ver(int s) {
    if (s <= 25) return "Very Weak";
    if (s <= 45) return "Weak";
    if (s <= 70) return "Medium";
    if (s <= 90) return "Strong";
    return "Very Strong";
}
int main() {
    char p[MAX];
      char tmp[MAX];

    while (1) {
        printf("\nEnter password (or type 'exit' to quit): ");

        if (!fgets(p, MAX, stdin)) {
            printf("\nInput ended. Exiting...\n");
            break;
        }
        int n = strlen(p);
        while (n > 0 && (p[n-1] == '\n' || p[n-1] == '\r')) {
            p[n-1] = '\0';
            n--;
        }
        int start = 0;
        while (p[start] == ' ' || p[start] == '\t') start++;
        int end = n - 1;
        while (end >= start && (p[end] == ' ' || p[end] == '\t')) {
            p[end] = '\0';
            end--;
        }
        char *q = p + start;
        int i = 0;
        while (q[i] && i < MAX - 1) {
         tmp[i] = tolower((unsigned char)q[i]);
            i++;
        }
        tmp[i] = '\0';
        if (strcmp(tmp, "exit") == 0 || strcmp(tmp, "quit") == 0) {
            printf("Exiting...\n");
            break;
        }
        n = strlen(q);
        double e;
        int score = sc(q, n, &e);

        printf("\nScore   : %d / 100\n", score);
        printf("Strength: %s\n", ver(score));
        printf("Entropy : %.2f bits\n", e);

        printf("\nHints:\n");
        if (n < 8) printf("- Password must be at least 8 characters long.\n");
        if (chk_com(q)) printf("- This is a common password! Change it.\n");
        if (chk_seq(q, n)) printf("- Avoid sequences like abc or 123.\n");
    }

    return 0;
}
