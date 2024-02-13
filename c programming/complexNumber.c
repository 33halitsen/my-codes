#include <stdio.h>
#include <math.h>

typedef struct
{
    double real, img;
} Complexnum;

int getComplex(Complexnum *c);
void printComplex(Complexnum c);
void printresult(Complexnum x, Complexnum y, Complexnum result, char process);
Complexnum addComplex(Complexnum x, Complexnum y);
Complexnum subtractComplex(Complexnum x, Complexnum y);
Complexnum multiplyComplex(Complexnum x, Complexnum y);

int main()
{

    Complexnum x, y;

    printf("Enter the real and imaginary side of your first complex number\n");
    printf("use a space between real side and img side ");
    getComplex(&x);
    printf("Enter the real and imaginary side of your second complex number\n ");
    getComplex(&y);

    printresult(x, y, addComplex(x, y), '+');
    printresult(x, y, subtractComplex(x, y), '-');
    printresult(x, y, multiplyComplex(x, y), '*');

    return 0;
}

int scanComplex(Complexnum *c)
{
    int status;

    scanf("%lf %lf", &c->real, &c->img);

    status = 1;
    return status;
}

void printComplex(Complexnum c)
{
    double a, b;
    char process;

    a = c.real;
    b = c.img;

    printf("(");
    if (b < 0)
    {
        process = "-";
    }

    else
    {
        process = "+";
    }

    printf("%.2f %c %.2fi", a, process, fabs(b));
    printf(")");
}

Complexnum addComplex(Complexnum x, Complexnum y)
{
    Complexnum result;

    result.real = x.real + y.real;
    result.img = x.img + y.img;

    return result;
}

Complexnum subtractComplex(Complexnum x, Complexnum y)
{
    Complexnum result;

    result.real = x.real - y.real;
    result.img = x.img - y.img;

    return result;
}

Complexnum multiplyComplex(Complexnum x, Complexnum y)
{
    Complexnum result;

    result.real = x.real * y.real - x.img * y.img;
    result.img = x.real * y.img + x.img * y.real;

    return result;
}

void printresult(Complexnum x, Complexnum y, Complexnum result, char process)
{
    if (process == '+')
    {
        printf("\n");
        printComplex(x);
        printf(" + ");
        printComplex(y);
        printf(" = ");
        printComplex(result);
    }

    if (process == '-')
    {
        printf("\n");
        printComplex(x);
        printf(" - ");
        printComplex(y);
        printf(" = ");
        printComplex(result);
    }

    if (process == '*')
    {
        printf("\n");
        printComplex(x);
        printf(" * ");
        printComplex(y);
        printf(" = ");
        printComplex(result);
    }
}
