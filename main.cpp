#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Seat.cpp"
#include "Screen.cpp"
#include "Movie.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Cinema.cpp"
#include "Customer.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "Booking.cpp"
#include "BookingService.cpp"
#include "TicketPrinter.cpp"

using namespace std;

vector<string> splitSeats(string input)
{
    vector<string> result;
    stringstream ss(input);
    string seat;

    while (getline(ss, seat, ','))
    {
        int start = 0;
        while (start < (int)seat.size() && seat[start] == ' ')
            start++;

        int end = seat.size() - 1;
        while (end >= 0 && seat[end] == ' ')
            end--;

        if (start <= end)
            result.push_back(seat.substr(start, end - start + 1));
    }

    return result;
}

void printMovieList(const vector<Movie>& movies)
{
    cout << "\n--- AVAILABLE MOVIES ---\n";

    for (int i = 0; i < (int)movies.size(); i++)
    {
        cout << "[" << i + 1 << "] "
             << movies[i].getTitle() << "\t"
             << movies[i].getLanguage() << " "
             << movies[i].getDurationMinutes() << " min\n";
    }
}

void printSeats(Show* show)
{
    cout << "\n" << show->getMovie()->getTitle()
         << "   " << show->getShowTime() << "\n";

    string types[] = {"SILVER", "GOLD", "PLATINUM"};

    for (string type : types)
    {
        cout << type << "    ";

        for (auto& seat : show->getShowSeats())
        {
            if (seat.getSeat().getCategory() == type)
            {
                cout << seat.getSeat().getSeatNumber()
                     << (seat.isBooked() ? "[X] " : "[ ] ");
            }
        }

        cout << "\n";
    }

    cout << "\n( [ ] = available   [X] = booked )\n\n";
}

double seatPrice(string category)
{
    if (category == "GOLD")
        return 250;
    if (category == "PLATINUM")
        return 350;
    return 150;
}

int main()
{
    Cinema cinema("HJCINEMA");

    Screen screen1("Screen-1");
    screen1.addSeat(Seat("A1", "SILVER"));
    screen1.addSeat(Seat("A2", "SILVER"));
    screen1.addSeat(Seat("A3", "SILVER"));
    screen1.addSeat(Seat("A4", "SILVER"));
    screen1.addSeat(Seat("B1", "GOLD"));
    screen1.addSeat(Seat("B2", "GOLD"));
    screen1.addSeat(Seat("B3", "GOLD"));
    screen1.addSeat(Seat("C1", "PLATINUM"));
    screen1.addSeat(Seat("C2", "PLATINUM"));

    Screen screen2("Screen-2");
    screen2.addSeat(Seat("A1", "SILVER"));
    screen2.addSeat(Seat("A2", "SILVER"));
    screen2.addSeat(Seat("B1", "GOLD"));

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    Movie m1("3 Idiots", "Hindi", 170);
    Movie m2("Interstellar", "English", 169);

    Show show1(101, &m1, &screen1, "06:00 PM");
    Show show2(102, &m2, &screen2, "09:00 PM");

    vector<Movie> movies = {m1, m2};
    vector<Show> shows = {show1, show2};

    BookingService service(&cinema);
    vector<Booking*> tickets;

    int choice;

    do
    {
        cout << "\n===== MOVIE TICKET BOOKING =====\n";
        cout << "1. Movies   2. Book   3. Cancel   4. My tickets   0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                printMovieList(movies);
                break;

            case 2:
            {
                printMovieList(movies);

                cout << "\nChoose movie: ";
                int movieChoice;
                cin >> movieChoice;

                if (movieChoice < 1 || movieChoice > (int)movies.size())
                {
                    cout << "Invalid movie choice!\n";
                    break;
                }

                cout << "\n[1] Screen-1   06:00 PM\n";
                cout << "[2] Screen-2   09:00 PM\n";
                cout << "Choose show: ";

                int showChoice;
                cin >> showChoice;

                if (showChoice != 1 && showChoice != 2)
                {
                    cout << "Invalid show choice!\n";
                    break;
                }

                Show* selectedShow = &shows[showChoice - 1];

                printSeats(selectedShow);

                cout << "Seats (e.g. A1,B2): ";
                string input;
                cin >> input;

                vector<string> selectedSeats = splitSeats(input);
                Customer customer("Himanshu", "9876543210");

                Booking* booking =
                    service.createBooking(customer, selectedShow, selectedSeats);

                if (booking == nullptr)
                    break;

                double total = 0;

                cout << "\n--- PRICE DETAILS ---\n";

                for (auto* seat : booking->getBookedSeats())
                {
                    double price = seatPrice(seat->getSeat().getCategory());

                    cout << seat->getSeat().getSeatNumber()
                         << " " << seat->getSeat().getCategory()
                         << " Rs." << price << "\n";

                    total += price;
                }

                cout << "TOTAL          Rs." << total << "\n\n";

                cout << "Pay by: 1.UPI   2.Card   3.Cash > ";
                int payChoice;
                cin >> payChoice;

                Payment* payment = nullptr;

                if (payChoice == 1)
                    payment = new UpiPayment("user@upi");
                else if (payChoice == 2)
                    payment = new CardPayment("4111-XXXX-XXXX-1111");
                else if (payChoice == 3)
                    payment = new CashPayment();
                else
                {
                    cout << "Invalid payment choice!\n";
                    delete booking;
                    break;
                }

                if (service.processPayment(booking, payment))
                {
                    tickets.push_back(booking);
                    TicketPrinter::printTicket(booking);
                }

                delete payment;
                break;
            }

            case 3:
            {
                if (tickets.empty())
                {
                    cout << "\nNo bookings found to cancel.\n";
                    break;
                }

                cout << "\n--- CANCEL BOOKING ---\n";
                cout << "Enter Booking ID: ";

                int id;
                cin >> id;

                bool found = false;

                for (auto* ticket : tickets)
                {
                    if (ticket->getBookingId() == id)
                    {
                        service.cancelBooking(ticket);
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Booking ID not found.\n";

                break;
            }

            case 4:
            {
                cout << "\n--- MY TICKETS ---\n";

                if (tickets.empty())
                {
                    cout << "No tickets booked yet.\n";
                    break;
                }

                for (auto* ticket : tickets)
                    TicketPrinter::printTicket(ticket);

                break;
            }

            case 0:
                cout << "\nExiting System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    for (auto* ticket : tickets)
        delete ticket;

    return 0;
}
