#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
    Requerimientos
1 Al programa no le importará si la key es lowercase o uppercase
2 Si el programa es ejecutado sin argumentos en la linea de comando mostrará un mensaje de error y retornará 1 desde main****
3 Si la key es inválida, no tiene 26 caracteres **, tiene caracteres no alfabéticos*** o que no contenga cada letra sólo una vez***, se imprimirá un mensaje de error y main retornará 1
4 El programa mostrará "plaintext: " para indicar al usuario que debe ingresar un texto
5 El programa mostrará "ciphertext: " (sin \n) para indicar el mensaje el cual se convirtió plaintext, caracteres no alfabéticos no cambiarán.
6 El programa mantendrá las mayúsculas o minúsculas al cifrar plaintext
7 Después de mostrar el texto cifrado el programa imprimirá un salto de línea y retornará 0 desde main.
*/

char rotate(string plaintext, string key);

int main(int argc, string argv[])
{
    // Condición para que sólo se acepte un argumento
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Validar que la key tiene 26 caracteres
    if (strlen(argv[1]) % 26 != 0)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    string key = argv[1];

    // Verificar si hay algún caracter de la key que no es un alfabético
    for (int i = 0; i < strlen(key); i++)
    {
        // lograr que no importe si es lowecase o uppercase
        key[i] = tolower(key[i]);
        // si no es una letra imprimirá el mensaje de Usage
        if (!isalpha(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        // Contador de letras repetidas
        int count = 0;

        for (int j = 0; j < strlen(key); j++)
        {
            //verificar que no importe si es uppercase o lowercase
            key[j] = tolower(key[j]);
            if (key[i] == key[j])
            {
                count++;
            }
            if (count > 1)
            {
                printf("2 IGUALES ./caesar key\n");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    int lengthText = strlen(plaintext);
    char cipherletter;

    for (int i = 0; i < lengthText; i++)
    {
        int positionLetter = 0;
        char letter = plaintext[i];

        if (letter >= 'a' && letter <= 'z')
        {
            // posición de la letra en abecedario
            positionLetter = (letter - 97) % 26;
            cipherletter = key[positionLetter];
        }
        else if (letter >= 'A' && letter <= 'Z')
        {
            positionLetter = (letter - 65) % 26;
            //como cambié todo a lowercase, es necesario que lo que sea upper se mantenga en upper
            cipherletter = toupper(key[positionLetter]);
        }
        else
        {
            cipherletter = letter;
        }

        printf("%c", cipherletter);
    }
    printf("\n");
    return 0;
}