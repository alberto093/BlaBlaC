//
//  mock.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 03/11/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "mock.h"
#include "driver.h"
#include "passenger.h"
#include "ride.h"
#include <string.h>

void setup_drivers(driver drivers[], int *total_drivers);
void setup_passengers(passenger passengers[], int *total_passengers);
void setup_rides(ride rides[], int *total_rides);
ride setup_ride(hash_code driver_code, place source, place destination, date date, float price, unsigned short int seats);

void setup_default(void) {
    driver drivers[DRIVERS_MAX];
    int total_drivers = 0;
    passenger passengers[PASSENGERS_MAX];
    int total_passengers = 0;
    ride rides[RIDES_MAX];
    int total_rides = 0;
    
    setup_drivers(drivers, &total_drivers);
    setup_passengers(passengers, &total_passengers);
    setup_rides(rides, &total_rides);
    
    save_drivers(drivers, total_drivers);
    save_passengers(passengers, total_passengers);
    save_rides(rides, total_rides);
}

void setup_drivers(driver drivers[], int *total_drivers) {
    driver driver1;
    driver driver2;
    driver driver3;
    driver driver4;
    driver driver5;
    
    review review1a;
    review review1b;
    review review2a;
    review review2b;
    review review3a;
    review review3b;
    review review4a;
    review review4b;
    review review4c;
    review review5;
    
    strcpy(driver1.code, "SLTLRT93C22L109N");
    strcpy(driver2.code, "CTNFLV92H48G113V");
    strcpy(driver3.code, "SLTGNN51A07L109K");
    strcpy(driver4.code, "LTNMRA58M49F284M");
    strcpy(driver5.code, "SLTFBA87P01L109Y");
    
    strcpy(driver1.name, "Alberto");
    strcpy(driver2.name, "Flavia");
    strcpy(driver3.name, "Giovanni");
    strcpy(driver4.name, "Maria");
    strcpy(driver5.name, "Fabio");
    
    strcpy(driver1.surname, "Saltarelli");
    strcpy(driver2.surname, "Catanzaro");
    strcpy(driver3.surname, "Saltarelli");
    strcpy(driver4.surname, "Latino");
    strcpy(driver5.surname, "Saltarelli");
    
    driver1.age = 26;
    driver2.age = 27;
    driver3.age = 68;
    driver4.age = 61;
    driver5.age = 32;
    
    strcpy(driver1.description, "iOS Developer presso Open Reply e musicista polistrumentista classico");
    strcpy(driver2.description, "Chirurgo veterinario presso Clinica Veterinaria Roma SUD");
    strcpy(driver3.description, "Pensionato Ex dirigente postale presso CMP di Bari");
    strcpy(driver4.description, "Dipendente postale presso Ufficio Molfetta Centro");
    strcpy(driver5.description, "Dipendente postale presso Direzione centrale Bari");
    
    strcpy(review1a.passenger_code, "CTNFLV92H48G113V");
    strcpy(review1b.passenger_code, "SLTFBA87P01L109Y");
    strcpy(review2a.passenger_code, "SLTLRT93C22L109N");
    strcpy(review2b.passenger_code, "LTNMRA58M49F284M");
    strcpy(review3a.passenger_code, "CTNFLV92H48G113V");
    strcpy(review3b.passenger_code, "LTNMRA58M49F284M");
    strcpy(review4a.passenger_code, "SLTLRT93C22L109N");
    strcpy(review4b.passenger_code, "SLTGNN51A07L109K");
    strcpy(review4c.passenger_code, "SLTFBA87P01L109Y");
    strcpy(review5.passenger_code, "SLTLRT93C22L109N");
    
    review1a.rating = rating_oustanding;
    review1b.rating = rating_excellent;
    review2a.rating = rating_good;
    review2b.rating = rating_oustanding;
    review3a.rating = rating_excellent;
    review3b.rating = rating_oustanding;
    review4a.rating = rating_excellent;
    review4b.rating = rating_excellent;
    review4c.rating = rating_excellent;
    review5.rating = rating_good;
    
    driver1.reviews[0] = review1a;
    driver1.reviews[1] = review1b;
    driver2.reviews[0] = review2a;
    driver2.reviews[1] = review2b;
    driver3.reviews[0] = review3a;
    driver3.reviews[1] = review3b;
    driver4.reviews[0] = review4a;
    driver4.reviews[1] = review4b;
    driver4.reviews[2] = review4c;
    driver5.reviews[0] = review5;
    
    driver1.total_reviews = 2;
    driver2.total_reviews = 2;
    driver3.total_reviews = 2;
    driver4.total_reviews = 3;
    driver5.total_reviews = 1;
    
    driver1.total_rides = 7;
    driver2.total_rides = 9;
    driver3.total_rides = 5;
    driver4.total_rides = 6;
    driver5.total_rides = 3;
    
    drivers[0] = driver1;
    drivers[1] = driver2;
    drivers[2] = driver3;
    drivers[3] = driver4;
    drivers[4] = driver5;
    
    *total_drivers = 5;
}

void setup_passengers(passenger passengers[], int *total_passengers) {
    passenger passenger1;
    passenger passenger2;
    passenger passenger3;
    passenger passenger4;
    passenger passenger5;
    
    strcpy(passenger1.code, "SLTLRT93C22L109N");
    strcpy(passenger2.code, "CTNFLV92H48G113V");
    strcpy(passenger3.code, "SLTGNN51A07L109K");
    strcpy(passenger4.code, "LTNMRA58M49F284M");
    strcpy(passenger5.code, "SLTFBA87P01L109Y");
    
    strcpy(passenger1.name, "Alberto");
    strcpy(passenger2.name, "Flavia");
    strcpy(passenger3.name, "Giovanni");
    strcpy(passenger4.name, "Maria");
    strcpy(passenger5.name, "Fabio");
    
    strcpy(passenger1.surname, "Saltarelli");
    strcpy(passenger2.surname, "Catanzaro");
    strcpy(passenger3.surname, "Saltarelli");
    strcpy(passenger4.surname, "Latino");
    strcpy(passenger5.surname, "Saltarelli");
    
    passenger1.age = 26;
    passenger2.age = 27;
    passenger3.age = 68;
    passenger4.age = 61;
    passenger5.age = 32;
    
    strcpy(passenger1.description, "iOS Developer presso Open Reply e musicista polistrumentista classico");
    strcpy(passenger2.description, "Chirurgo veterinario presso Clinica Veterinaria Roma SUD");
    strcpy(passenger3.description, "Pensionato Ex dirigente postale presso CMP di Bari");
    strcpy(passenger4.description, "Dipendente postale presso Ufficio Molfetta Centro");
    strcpy(passenger5.description, "Dipendente postale presso Direzione centrale Bari");
    
    passengers[0] = passenger1;
    passengers[1] = passenger2;
    passengers[2] = passenger3;
    passengers[3] = passenger4;
    passengers[4] = passenger5;
    
    *total_passengers = 5;
}

void setup_rides(ride rides[], int *total_rides) {
    place molfetta;
    place ciampino;
    place napoli;
    place frascati;
    place torino;
    
    date date1;
    date date2;
    date date3;
    date date4;
    date date5;
    date date6;
    date date7;
    date date8;
    
    strcpy(molfetta.address, "Via Tenente Silvestri 56");
    strcpy(ciampino.address, "Via di Morena 144");
    strcpy(napoli.address, "Via Manzoni 1");
    strcpy(frascati.address, "Via Marinetti 27");
    strcpy(torino.address, "Corso Spezia 126");
    
    strcpy(molfetta.city, "Molfetta");
    strcpy(ciampino.city, "Ciampino");
    strcpy(napoli.city, "Napoli");
    strcpy(frascati.city, "Frascati");
    strcpy(torino.city, "Torino");
    
    strcpy(molfetta.province, "Bari");
    strcpy(ciampino.province, "Roma");
    strcpy(napoli.province, "Napoli");
    strcpy(frascati.province, "Roma");
    strcpy(torino.province, "Torino");
    
    molfetta.postal_code = 70056;
    ciampino.postal_code = 43;
    napoli.postal_code = 80046;
    frascati.postal_code = 46;
    torino.postal_code = 10126;
    
    date1.day = 10;
    date2.day = 10;
    date3.day = 10;
    date4.day = 11;
    date5.day = 11;
    date6.day = 11;
    date7.day = 12;
    date8.day = 12;
    
    date1.month = 11;
    date2.month = 11;
    date3.month = 11;
    date4.month = 11;
    date5.month = 11;
    date6.month = 11;
    date7.month = 11;
    date8.month = 11;
    
    date1.year = 2019;
    date2.year = 2019;
    date3.year = 2019;
    date4.year = 2019;
    date5.year = 2019;
    date6.year = 2019;
    date7.year = 2019;
    date8.year = 2019;
    
    date1.hour = 9;
    date2.hour = 10;
    date3.hour = 11;
    date4.hour = 12;
    date5.hour = 13;
    date6.hour = 14;
    date7.hour = 15;
    date8.hour = 16;
    
    date1.minutes = 0;
    date2.minutes = 30;
    date3.minutes = 15;
    date4.minutes = 45;
    date5.minutes = 0;
    date6.minutes = 0;
    date7.minutes = 30;
    date8.minutes = 30;
    
    rides[0] = setup_ride("SLTLRT93C22L109N", molfetta, ciampino, date1, 10, 4);
    rides[1] = setup_ride("SLTLRT93C22L109N", ciampino, molfetta, date2, 15, 3);
    rides[2] = setup_ride("SLTLRT93C22L109N", napoli, frascati, date3, 7, 3);
    rides[3] = setup_ride("CTNFLV92H48G113V", frascati, molfetta, date4, 20, 3);
    rides[4] = setup_ride("CTNFLV92H48G113V", ciampino, napoli, date5, 30, 2);
    rides[5] = setup_ride("SLTGNN51A07L109K", torino, molfetta, date6, 22, 2);
    rides[6] = setup_ride("LTNMRA58M49F284M", molfetta, torino, date7, 22.50, 4);
    rides[7] = setup_ride("LTNMRA58M49F284M", ciampino, torino, date8, 13, 6);
    rides[8] = setup_ride("SLTFBA87P01L109Y", napoli, torino, date1, 16, 1);
    rides[9] = setup_ride("SLTFBA87P01L109Y", torino, frascati, date2, 30, 1);
    rides[10] = setup_ride("CTNFLV92H48G113V", molfetta, ciampino, date3, 32, 4);
    rides[11] = setup_ride("CTNFLV92H48G113V", ciampino, molfetta, date4, 31.50, 3);
    rides[12] = setup_ride("CTNFLV92H48G113V", napoli, frascati, date5, 16, 3);
    rides[13] = setup_ride("SLTLRT93C22L109N", frascati, molfetta, date6, 18, 3);
    rides[14] = setup_ride("SLTLRT93C22L109N", ciampino, napoli, date7, 10, 2);
    rides[15] = setup_ride("LTNMRA58M49F284M", torino, molfetta, date8, 15, 2);
    rides[16] = setup_ride("SLTGNN51A07L109K", molfetta, torino, date1, 7, 4);
    rides[17] = setup_ride("SLTGNN51A07L109K", ciampino, torino, date2, 20, 6);
    rides[18] = setup_ride("SLTLRT93C22L109N", napoli, torino, date3, 30, 1);
    rides[19] = setup_ride("SLTLRT93C22L109N", torino, frascati, date4, 22, 1);
    rides[20] = setup_ride("LTNMRA58M49F284M", molfetta, ciampino, date5, 22.50, 4);
    rides[21] = setup_ride("LTNMRA58M49F284M", ciampino, molfetta, date6, 13, 3);
    rides[22] = setup_ride("LTNMRA58M49F284M", napoli, frascati, date7, 16, 3);
    rides[23] = setup_ride("SLTGNN51A07L109K", frascati, molfetta, date8, 30, 3);
    rides[24] = setup_ride("SLTGNN51A07L109K", ciampino, napoli, date1, 32, 2);
    rides[25] = setup_ride("SLTFBA87P01L109Y", torino, molfetta, date2, 31.50, 2);
    rides[26] = setup_ride("CTNFLV92H48G113V", molfetta, torino, date3, 16, 4);
    rides[27] = setup_ride("CTNFLV92H48G113V", ciampino, torino, date4, 18, 6);
    rides[28] = setup_ride("CTNFLV92H48G113V", napoli, torino, date5, 10, 1);
    rides[29] = setup_ride("CTNFLV92H48G113V", torino, frascati, date6, 15, 1);
    
    strcpy(rides[1].passenger_codes[0], "SLTFBA87P01L109Y");
    strcpy(rides[1].passenger_codes[1], "CTNFLV92H48G113V");
    rides[1].total_passenger_codes = 2;
    strcpy(rides[3].passenger_codes[0], "LTNMRA58M49F284M");
    rides[3].total_passenger_codes = 1;
    strcpy(rides[5].passenger_codes[0], "CTNFLV92H48G113V");
    rides[5].total_passenger_codes = 1;
    strcpy(rides[6].passenger_codes[0], "SLTLRT93C22L109N");
    strcpy(rides[6].passenger_codes[1], "SLTFBA87P01L109Y");
    rides[6].total_passenger_codes = 2;
    strcpy(rides[15].passenger_codes[0], "SLTGNN51A07L109K");
    rides[15].total_passenger_codes = 1;
    strcpy(rides[16].passenger_codes[0], "LTNMRA58M49F284M");
    rides[16].total_passenger_codes = 1;
    strcpy(rides[25].passenger_codes[0], "SLTLRT93C22L109N");
    rides[25].total_passenger_codes = 1;
    strcpy(rides[29].passenger_codes[0], "SLTLRT93C22L109N");
    rides[29].total_passenger_codes = 1;
    
    *total_rides = 30;
}

ride setup_ride(hash_code driver_code, place source, place destination, date date, float price, unsigned short int seats) {
    ride new_ride;
    strcpy(new_ride.driver_code, driver_code);
    new_ride.source = source;
    new_ride.destination = destination;
    new_ride.date = date;
    new_ride.price = price;
    new_ride.total_seats = seats;
    new_ride.total_messages = 0;
    new_ride.total_passenger_codes = 0;
    return new_ride;
}
