#include "Booking_Process.h"

vector<struct Ticket_Details> temp;
int B_id = 1001;
int main()
{
    Passenger obj;
    while(1)
    {
        int F_id,S_count,option;
        int C1,C2,C3,Rows;
        string S_num,S_type;
        bool Meal;
        cout<<"__________________________________________________________________"<<endl;
        cout<<"_____*****_____ Sky Airlines Ticket Booking System_____*****_____"<<endl;
        cout<<"__________________________________________________________________"<<endl<<endl;
        cout<<endl<<"1. Tickect Booking"<<endl<<"2. Ticket Cancellation"<<endl;
        cout<<"3. Print Available Seats"<<endl<<"4. Print Seat numbers for which meal is ordered"<<endl;
        cout<<"5. Print Individual and Flight summary"<<endl<<"6. Exit"<<endl<<endl;

        cout<<"Select the Option, You need to Perform : ";
        cin>>option;
        
        switch(option)
        {
            case 1:
                    cout<<"Enter the Flight Number : ";
                    cin>>F_id;
                    cout<<"Enter the Class(Economy/Business) Type : ";
                    cin>>S_type;
                    cout<<"Enter the Number of seats to be Booked : ";
                    cin>>S_count;

                    for(int i=0;i<S_count;++i)
                    {
                        cout<<"Enter the Seat Number : ";
                        cin>>S_num;
                        cout<<"Enter the Meal Preference : ";
                        cin>>Meal;

                        temp.push_back(Ticket_Details(S_num,Meal));
                    }

                    Passenger_data.push_back(Passenger_Details(F_id,B_id++,S_type,temp));
                    break;

            case 2:
                    
                    break;

            case 3:
                    cout<<"Enter the Flight Number : ";
                    cin>>F_id;

                    file.open(to_string(F_id)+".txt",ios::in);
                    if(file.is_open())
                    {
                        while(file>>C1>>C2>>C3>>Rows)
                        {
                            Seat_arrangement(C1,C2,C3,Rows);
                            Print_available_seats();
                        }

                    }
                    file.close();

                    break;
            
            case 4:
            
                    break;

            case 5:
                    cout<<"Enter the Booking ID : ";
                    cin>>B_id;
                    obj.Print_summary(B_id);
                    break;
            
            case 6:
                    exit (0);

            default:
                    cout<<"Invalid Option !"<<endl;
        }
    }

    return 0;
}