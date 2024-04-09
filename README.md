# Airline-Management-System
This program is a simple airline reservation system written in C++. It allows users to:

- View a list of available flights with their destinations, departure locations, and remaining seats.
- Reserve a seat on a specific flight (if available).
The program stores flight data in a text file named "Flights.txt" located on drive H.

### Here's a breakdown of the code:

#### Classes:
- Airline: This class represents an airline flight. It has member variables for flight number, destination, departure location, and number of available seats. It also has member functions to get these details and update the number of seats when a reservation is made.

#### Functions:
- display(): This function reads the flight data from the text file and displays it on the console.
- update(string flight): This function takes a flight number as input and updates the corresponding seat count in the text file if a seat is available.

#### Main Function:

1- Creates three Airline objects (flight1, flight2, flight3) with sample data.
2- Writes the initial flight data to the text file "Flights.txt".
3- Presents a menu to the user with options to reserve a seat or exit the program.
- If the user chooses to reserve a seat:
  - The program displays the available flights.
  - The user enters the flight number they want to reserve a seat on.
  - The program checks if the seat is available and updates the seat count in the text file if the reservation is successful.
- If the user chooses to exit, the program terminates.

#### Note:

- This is a basic implementation and can be extended to include features like user login, cancellation of reservations, etc.
- The code uses Windows.h header file for Sleep function. You might need to modify the code if you plan to run it on a non-Windows system.
