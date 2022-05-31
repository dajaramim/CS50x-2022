#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Requerimientos

// 1 el programa solo debe aceptar un argumento en la línea de comandos, no puede ser negativo. Es la llave "k"
// 2 si no se ingresa un argumento o si se ingresa más de uno debe aparecer un mensaje de error usando printf y que retorne desde main el valor 1 que significa que hubo un error
// 3 si alguno de los caracteres del argumento en la línea de comando NO ES un digito decimal, el programa deberá imprimir el mensaje Usage: ./caesar key y retornar desde main el valor de 1
// 4 No asumir que k será menor a 26, por lo que si es mayor, por ejemplo 27 y p[0] es A, entonces c[0] es B.
// 5 El programa cuando se ingresa bien una k mostrará "plaintext: " pidiendo al usuario un texto cualquiera usando get_string*
// 6 el programa deberá mostrar "ciphertext: " más el texto cifrado, los caracteres no alfabéticos no cambiarán.
// 7 El programa deberá mantener mayúsculas y minúsculas.
// 8 Después de obtener el texto cifrado se deberá imprimir un salto de línea. El programa deberá luego salir retornando 0 desde main.*

char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Condición para que sólo se acepte un argumento
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Verificar si hay algún caracter de la key que no es un número
    string k = argv[1];
    // recorro todos los caracteres de la key
    for (int i = 0; i < strlen(k); i++)
    {
        // si no es un dígito imprimirá el mensaje de Usage
        if (!isdigit(k[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // convertir la key a un int
    int key = atoi(k);

    char cipherletter;

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // imprimir cada letra cifrada
    int lengthText = strlen(plaintext);

    for (int j = 0; j < lengthText; j++)
    {
        char letter = plaintext[j];

        cipherletter = rotate(letter, key);

        printf("%c", cipherletter);
    }
    printf("\n");
    return 0;
}

char rotate(char letter, int key)
{
    int cipherletter;

    // Verificar que solo vaya hasta 26 caracteres contando el 0
    if (key > 25)
    {
        key = key % 26;
    }

    if (letter >= 'a' && letter <= 'z')
    {
        cipherletter = ((letter - 97 + key) % 26) + 97; //obtengo la posición de la letra, le sumo la key, luego obtengo la posición de las letras en nuestro abecedario y por último lo convierto en ASCII
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        cipherletter = ((letter - 65 + key) % 26) + 65;
    }

    else
    {
        cipherletter = letter;
    }

    return cipherletter;
}
