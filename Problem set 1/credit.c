#include <cs50.h>
#include <stdio.h>

// luhn's Algorithm
/*
1-Desde el penúltimo número se seleccionan cada dos números *
2-Cada número seleccionado se multiplica por 2
3-luego se suman los digitos del resultado de los números mutiplicados por 2, es decir, si hay 1 0 0 0 12 1 0 3, el 12 no se suma como 12 sino como 1 y 2.
4-La checkSuma de digitos se suma a la SUMA de digitos de los números que no fueron multiplicados por 2
5- si la suma termina en 0 es porque está correcto.*/
string creditCard(long card);
int main(void)
{
    // Ask for credit card
    //  Ciclo iterativo para siga preguntando si es que el usuario se equivoca
    long card;

    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    string typeCard = creditCard(card);
    printf("%s", typeCard);
}

string creditCard(long card)
{
    // Obtener la suma de los números que se multiplicaran por 2
    int digit;
    int product;
    int checkSum = 0;
    long number = card;
    string creditCard;
    int countDigit = 0;

    while (number > 0)
    {
        // Obtener digito par
        digit = number % 10;

        // Contar digitos
        countDigit++;

        checkSum = checkSum + digit;

        // elimina 1 digito de la derecha
        number = number / 10;

        // Verificar que no se cuente un digito de más
        if (number > 0)
        {
            countDigit++;
        }

        // guarda el último digito en una variable
        digit = number % 10;

        // Calcular el digito * 2
        product = digit * 2;

        if (product > 9)
        {
            // se suma el último dígito de producto a la variable checkSuma
            checkSum = checkSum + product % 10;
            // se suma el primer dígito de producto a la variable checkSuma
            checkSum = checkSum + product / 10;
        }
        else
        {
            checkSum = checkSum + product;
        }

        // elimina digito impar de la derecha
        number = number / 10;
    }

    // Verificar que el checkSum es válido
    if (checkSum > 0 && checkSum % 10 == 0)

    {
        // Obtener primeros digitos para saber si son AMEX O MASTERCARD O VISA O INVALID
        while (card > 100)
        {
            card = card / 10;
        }

        // Condicion para asignar el tipo de tarjeta de crédito
        if (card / 10 == 4 && (countDigit == 13 || countDigit == 16))
        {
            creditCard = "VISA\n";
        }
        else if (card == 34 || card == 37 && countDigit == 15)
        {
            creditCard = "AMEX\n";
        }
        else if (card == 51 || card == 52 || card == 53 || card == 54 || card == 55 && countDigit == 16)
        {
            creditCard = "MASTERCARD\n";
        }
        else
        {
            creditCard = "INVALID\n";
        }
    }
    else
    {
        creditCard = "INVALID\n";
    }

    return creditCard;
}