# Cinema Ticket Booking System

A menu-driven **C++ console application** for managing movie ticket bookings in a cinema. The system allows customers to view movies, select shows, check seat availability, book seats, make payments, view tickets, and cancel bookings.

## Features

- View available movies with language and duration
- Select a movie and show
- Display available and booked seats
- Seat categories:
  - SILVER
  - GOLD
  - PLATINUM
- Book one or more seats
- Prevent booking of already-booked seats
- Calculate ticket price based on seat category
- Support multiple payment methods:
  - UPI
  - Card
  - Cash
- Generate a unique booking ID
- Print a formatted ticket
- View all booked tickets
- Cancel bookings using Booking ID
- Automatically release seats after cancellation
- Handle invalid menu and selection choices
- Separate classes for different responsibilities

## Class Structure

| Class | Responsibility |
|---|---|
| `Movie` | Stores movie title, language, and duration |
| `Seat` | Represents a physical seat and its category |
| `Screen` | Manages the seats belonging to a screen |
| `Cinema` | Manages the cinema and its screens |
| `Show` | Connects a movie with a screen and show time |
| `ShowSeat` | Maintains seat availability for a particular show |
| `Customer` | Stores customer information |
| `Booking` | Stores booking ID, customer, show, seats, amount, and status |
| `Payment` | Abstract payment interface |
| `UpiPayment` | Handles UPI payment |
| `CardPayment` | Handles card payment |
| `CashPayment` | Handles cash payment |
| `PriceCalculator` | Calculates ticket prices |
| `TicketPrinter` | Displays ticket information |
| `BookingService` | Manages booking, payment, and cancellation |

## Workflow

```text
START
  |
  v
Main Menu
  |
  +----> Movies
  |        |
  |        v
  |   Display Movies
  |
  +----> Book
  |        |
  |        v
  |   Select Movie
  |        |
  |        v
  |   Select Show
  |        |
  |        v
  |   Display Seat Layout
  |        |
  |        v
  |   Select Seats
  |        |
  |        v
  |   Calculate Price
  |        |
  |        v
  |   Select Payment
  |        |
  |        v
  |   Payment Successful?
  |       /   |     YES  NO
  |      |    |
  |      v    v
  |   Confirm  Release Seats
  |      |
  |      v
  |   Print Ticket
  |
  +----> My Tickets
  |
  +----> Cancel
  |        |
  |        v
  |   Enter Booking ID
  |        |
  |        v
  |   Cancel Booking
  |        |
  |        v
  |   Release Seats
  |
  +----> Exit
           |
           v
          END
```

## OOP Concepts Used

### Encapsulation

Class data such as booking status and seat status is controlled through member functions.

### Abstraction

The `Payment` class provides a common abstract interface for payment processing.

### Inheritance

`UpiPayment`, `CardPayment`, and `CashPayment` derive from the `Payment` class.

### Runtime Polymorphism

Different payment classes can be accessed through a common `Payment*` pointer and processed through the payment interface.

### Compile-Time Polymorphism

The project uses overloaded constructors, including constructors in the `Movie` class.

### Composition

Examples:

```text
Cinema → Screen
Screen → Seat
Show → ShowSeat
```

### Aggregation

Examples:

```text
Show → Movie
Booking → Customer
Booking → ShowSeat
```

### Association

The `BookingService` interacts with customers and other system components to manage the booking workflow.

## Pricing

| Seat Category | Price |
|---|---:|
| SILVER | ₹150 |
| GOLD | ₹250 |
| PLATINUM | ₹350 |

> **Note:** The current `main.cpp` calculates the PLATINUM price as **₹350**.

## How to Run

### Prerequisites

- C++ compiler
- GCC / MinGW, Clang, or Microsoft Visual C++
- VS Code or any C++ IDE

### Clone the Repository

```bash
git clone <YOUR-REPOSITORY-URL>
cd CinemaBookingSystem
```

### Compile

Using GCC:

```bash
g++ main.cpp -o CinemaBookingSystem
```

### Run

**Windows:**

```bash
CinemaBookingSystem.exe
```

**Linux/macOS:**

```bash
./CinemaBookingSystem
```

Make sure all required `.cpp` files are present in the project directory because `main.cpp` includes the individual source files directly.

## Main Menu

```text
===== MOVIE TICKET BOOKING =====
1. Movies   2. Book   3. Cancel   4. My tickets   0. Exit
Choose:
```

## Screenshots

Create a `screenshots` folder and add screenshots of the running application.

### Main Menu

![Main Menu](screenshots/main-menu.png)

### Movie Selection

![Movies](screenshots/movies.png)

### Seat Layout

![Seat Layout](screenshots/seat-layout.png)

### Payment

![Payment](screenshots/payment.png)

### Generated Ticket

![Ticket](screenshots/ticket.png)

### Booking Cancellation

![Cancellation](screenshots/cancellation.png)

## Project Structure

```text
CinemaBookingSystem/
│
├── main.cpp
├── Seat.cpp
├── Screen.cpp
├── Movie.cpp
├── ShowSeat.cpp
├── Show.cpp
├── Cinema.cpp
├── Customer.cpp
├── Payment.cpp
├── UpiPayment.cpp
├── CardPayment.cpp
├── CashPayment.cpp
├── Booking.cpp
├── BookingService.cpp
├── TicketPrinter.cpp
├── screenshots/
│   ├── main-menu.png
│   ├── movies.png
│   ├── seat-layout.png
│   ├── payment.png
│   ├── ticket.png
│   └── cancellation.png
└── README.md
```

## Design Principles

The system separates responsibilities among different classes. `BookingService` manages the booking workflow, payment classes handle individual payment methods, and `TicketPrinter` handles ticket presentation.

The design demonstrates the following SOLID principles:

- **Single Responsibility Principle (SRP)**
- **Open-Closed Principle (OCP)**
- **Liskov Substitution Principle (LSP)**
- **Interface Segregation Principle (ISP)**
- **Dependency Inversion Principle (DIP)**

## Author

**ANUJ NEGI**  
**SECTION-C1**  
**ROLL NO-12**
