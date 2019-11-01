//
//  route.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "route.h"
#include "utils.h"

home_result show_main_menu(void) {
    printf("\n\nHOME\n\n");
    int result = 0;
    
    do {
        printf("• Premi 1 per accedere alla sezione conducenti\n");
        printf("• Premi 2 per accedere alla sezione passeggeri\n");
        printf("• Premi 3 per accedere alla sezione viaggi\n");
        printf("• Premi 4 per uscire dal programma\n\n");
        scanf("%i", &result);
        fflush(stdin);
        result--;
        if (!is_included(result, 0, 3)) {
            printf("\nScelta non valida\n\n");
        }
    } while (!is_included(result, 0, 3));
    
    return result;
}

drivers_result show_driver_menu(void) {
    printf("\n\nSEZIONE CONDUCENTI\n\n");
    int result = 0;
    
    do {
        printf("• Premi 1 per creare un nuovo conducente\n");
        printf("• Premi 2 per modificare un conducente\n");
        printf("• Premi 3 per eliminare un conducente\n");
        printf("• Premi 4 per visualizzare i migliori conducenti\n");
        printf("• Premi 5 per tornare alla home\n\n");
        scanf("%i", &result);
        fflush(stdin);
        result--;
        if (!is_included(result, 0, 4)) {
            printf("\nScelta non valida\n\n");
        }
    } while (!is_included(result, 0, 4));
    
    return result;
}

passengers_result show_passengers_menu(void) {
    printf("\n\nSEZIONE PASSEGGERI\n\n");
    int result = 0;
    
    do {
        printf("• Premi 1 per creare un nuovo passeggero\n");
        printf("• Premi 2 per modificare un passeggero\n");
        printf("• Premi 3 per eliminare un passeggero\n");
        printf("• Premi 4 per tornare alla home\n\n");
        scanf("%i", &result);
        fflush(stdin);
        result--;
        if (!is_included(result, 0, 3)) {
            printf("\nScelta non valida\n\n");
        }
    } while (!is_included(result, 0, 3));
    
    return result;
}

rides_result show_rides_menu(void) {
    printf("\n\nSEZIONE VIAGGI\n\n");
    int result = 0;
    
    do {
        printf("• Premi 1 per creare un nuovo viaggio\n");
        printf("• Premi 2 per modificare un viaggio\n");
        printf("• Premi 3 per eliminare un viaggio\n");
        printf("• Premi 4 per cercare un viaggio\n");
        printf("• Premi 5 per lasciare una recensione\n");
        printf("• Premi 6 per tornare alla home\n\n");
        scanf("%i", &result);
        fflush(stdin);
        result--;
        if (!is_included(result, 0, 5)) {
            printf("\nScelta non valida\n\n");
        }
    } while (!is_included(result, 0, 5));
    
    return result;
}
