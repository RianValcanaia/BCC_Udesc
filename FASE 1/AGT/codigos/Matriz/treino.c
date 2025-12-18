int MMC(int a, int b, int c) {
    int divisor = 2;
    int mmc = 1;

    while (a > 1 || b > 1 || c > 1) {
    int dividiu = 0;

    while (a % divisor == 0 || b % divisor == 0 || c % divisor == 0) {
    if (a % divisor == 0) {
    a /= divisor;
    }
    if (b % divisor == 0) {
    b /= divisor;
    }
    if (c % divisor == 0) {
    c /= divisor;
    }

    mmc *= divisor;
    dividiu = 1;
    }

    if (!dividiu) {
    divisor++;
    }
    }
    }
}