# Cinema Ticket Booking System

A menu-driven **Cinema Ticket Booking System developed in C++** using Object-Oriented Programming (OOP) concepts. The system allows users to browse movies, select shows, check seat availability, book tickets, make payments, view tickets, and cancel bookings.

## Features

* View available movies
* View shows for a selected movie
* Display cinema seat layout
* Book one or multiple seats
* Prevent booking of already booked seats
* Automatic ticket price calculation
* Multiple payment methods:

  * UPI
  * Card
  * Cash
* Generate unique Booking IDs
* Generate and print tickets
* View all booked tickets
* Cancel bookings
* Release seats after cancellation
* Handle invalid menu and seat selections

## Class Structure

| Class             | Responsibility                                           |
| ----------------- | -------------------------------------------------------- |
| `Movie`           | Stores movie details such as name, language and duration |
| `Seat`            | Represents individual cinema seats                       |
| `Screen`          | Manages seats available on a screen                      |
| `Cinema`          | Manages cinema screens                                   |
| `Show`            | Connects a movie with a screen and show time             |
| `ShowSeat`        | Represents a seat for a particular show                  |
| `Customer`        | Stores customer information                              |
| `Booking`         | Stores booking and selected seat information             |
| `Payment`         | Abstract base class for payment processing               |
| `UpiPayment`      | Handles UPI payments                                     |
| `CardPayment`     | Handles card payments                                    |
| `CashPayment`     | Handles cash payments                                    |
| `BookingService`  | Handles booking, cancellation and ticket operations      |
| `TicketPrinter`   | Displays ticket details                                  |
| `PriceCalculator` | Calculates ticket prices                                 |

## System Workflow

```text
              ┌──────────────┐
              │    START     │
              └──────┬───────┘
                     │
                     ▼
             ┌───────────────┐
             │   Main Menu   │
             └───────┬───────┘
                     │
       ┌─────────────┼──────────────┐
       │             │              │
       ▼             ▼              ▼
  View Movies      Book Ticket    My Tickets
                     │
                     ▼
               Select Movie
                     │
                     ▼
                Select Show
                     │
                     ▼
              Display Seats
                     │
                     ▼
               Select Seats
                     │
                     ▼
             Calculate Price
                     │
                     ▼
              Select Payment
                     │
                     ▼
              Process Payment
                     │
                ┌────┴────┐
                │         │
              Success    Failed
                │         │
                ▼         ▼
          Confirm Booking  Stop
                │
                ▼
            Print Ticket
                │
                ▼
             Main Menu
```

## OOP Concepts Used

### 1. Encapsulation

Data and related functions are grouped inside classes. Private/protected members are accessed through appropriate member functions.

### 2. Abstraction

The `Payment` class provides an abstract interface using the pure virtual function:

```cpp
virtual bool pay(double amount) = 0;
```

The actual payment implementation is handled by derived classes.

### 3. Inheritance

The payment classes inherit from the `Payment` base class:

```text
             Payment
             /  |  \
            /   |   \
         UPI   Card  Cash
```

### 4. Runtime Polymorphism

`Payment*` can point to different payment objects such as `UpiPayment`, `CardPayment`, or `CashPayment`.

### 5. Compile-Time Polymorphism

Constructor overloading is used in the `Movie` class to create movies using different sets of parameters.

### 6. Composition

Strong "has-a" relationships are used between objects:

```text
Cinema → Screen
Screen → Seat
Show → ShowSeat
```

### 7. Aggregation

Objects can exist independently while being associated with another object:

```text
Show → Movie
Booking → ShowSeat
```

### 8. Association

`Customer` interacts with `BookingService` to perform booking-related operations.

## Ticket Pricing

| Seat Category | Price |
| ------------- | ----: |
| SILVER        |  ₹150 |
| GOLD          |  ₹250 |
| PLATINUM      |  ₹350 |

> Note: The current implementation uses ₹350 for PLATINUM seats.

## Technologies Used

* Language: C++
* Programming Paradigm: Object-Oriented Programming
* Compiler: GCC / MinGW
* Standard: C++17
* Interface: Console / Command Line

## How to Run

### 1. Clone the repository

```bash
git clone <YOUR-REPOSITORY-URL>
```

### 2. Navigate to the project directory

```bash
cd CinemaBookingSystem
```

### 3. Compile the project

```bash
g++ main.cpp -o CinemaBookingSystem
```

### 4. Run the program

Windows:

```bash
CinemaBookingSystem.exe
```

Linux/macOS:

```bash
./CinemaBookingSystem
```

> Note: The project currently includes `.cpp` source files directly from `main.cpp`, so all required `.cpp` files should remain in the project directory.

## Main Menu

```text
===== CINEMA BOOKING =====
1. Movies
2. Book
3. Cancel
4. My tickets
0. Exit
```

## Seat Categories

The cinema provides three different seat categories:

```text
SILVER     → ₹150
GOLD       → ₹250
PLATINUM   → ₹350
```

Seats are displayed according to their availability, allowing users to select seats before confirming their booking.

## Payment Methods

The system supports three payment methods:

```text
1. UPI
2. Card
3. Cash
```

A booking is confirmed only after successful payment processing.

## Project Structure

```text
CinemaBookingSystem/
│
├── main.cpp
├── Movie.cpp
├── Seat.cpp
├── Screen.cpp
├── Cinema.cpp
├── Show.cpp
├── ShowSeat.cpp
├── Customer.cpp
├── Booking.cpp
├── BookingService.cpp
├── Payment.cpp
├── UpiPayment.cpp
├── CardPayment.cpp
├── CashPayment.cpp
├── TicketPrinter.cpp
│
└── README.md
```

## Design Principles

The project follows several software design principles:

* Single Responsibility Principle (SRP)
* Open/Closed Principle (OCP)
* Liskov Substitution Principle (LSP)
* Interface Segregation Principle (ISP)
* Dependency Inversion Principle (DIP)

These principles help keep the system modular, maintainable and easier to extend.

## Screenshots

Add screenshots of the application here.

### Main Menu

```text
screenshots/main-menu.png
```

### Movie List

```text
screenshots/movies.png
```

### Seat Layout

```text
screenshots/seat-layout.png
```

### Payment

```text
screenshots/payment.png
```

### Ticket

```text
screenshots/ticket.png
```

### Cancellation

```text
screenshots/cancellation.png
```

> To display screenshots on GitHub, create a `screenshots` folder in the repository and upload the corresponding images.

## Future Improvements

* Add a graphical user interface
* Store bookings in a database
* Add user authentication
* Add admin functionality
* Add more cinemas and screens
* Add online payment gateway integration
* Add date-wise show management
* Add booking history

## Author

**ANUJ NEGI**

**SECTION-C1**

**ROLL NO-12**
