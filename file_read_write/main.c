// // #include <stdio.h>
// // #include <string.h>
// // #include <stdlib.h>

// // int main()
// // {

// //     FILE *fp = NULL;
    
// //     fp = fopen("E:/DeskTop/GY-80/test.txt", "a");
// //     fprintf(fp, "This is testing for fprintf...\n");
// //     fputs("This is testing for fputs...\n", fp);
// //     fclose(fp);

// //     char buff[255];
    
// //     fp = fopen("E:/DeskTop/GY-80/test.txt", "r");
// //     fscanf(fp, "%s", buff);
// //     printf("1: %s\n", buff );
    
// //     fgets(buff, 255, (FILE*)fp);
// //     printf("2: %s\n", buff );
    
// //     fgets(buff, 255, (FILE*)fp);
// //     printf("3: %s\n", buff );
// //     fgets(buff, 255, (FILE*)fp);
// //     printf("4: %s\n", buff );
// //     fgets(buff, 255, (FILE*)fp);
// //     printf("5: %s\n", buff );
// //     fclose(fp);

// //     system("pause");
// //     return 0;
// // }
// #include <stdio.h>
// #include <stdlib.h>  /* exit() º¯Êý */
 
// int main()
// {
//    char sentence[1000];
//    FILE *fptr;
 
//    fptr = fopen("E:/DeskTop/GY-80/test.txt", "w");
//    if(fptr == NULL)
//    {
//       printf("Error!");
//       exit(1);
//    }
   
//    printf("ÊäÈë×Ö·û´®:\n");
//    fgets(sentence, (sizeof sentence / sizeof sentence[0]), stdin);
 
//    fprintf(fptr,"%s", sentence);
//    fclose(fptr);
//     system("pause");
//    return 0;
// }