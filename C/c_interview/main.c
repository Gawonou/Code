/* Problème : Écrire une fonction qui inverse une 
    chaîne de caractères. */

    #include <stdio.h>
    #include <string.h>


    void reverse(char str[]){
    unsigned int n = strlen(str);
    char strn[n];

    for (int i = 0; i < n/2; i++){
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
       }
    }


int main(){
    
    char str[] = "Gawonou";
    reverse(str);
    printf("Le mot inverse est %s", str  );
    return 0;
}