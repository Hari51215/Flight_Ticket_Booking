#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
fstream file;
int No_Rows,No_C1,No_C2,No_C3;
string ***ptr[3];
vector<struct Passenger_Details> Passenger_data;

typedef struct Ticket_Details
{
    string Seat_number;
    bool Meal_preference;
    Ticket_Details(string S_num, bool Meal)
    {
        Seat_number = S_num;
        Meal_preference = Meal;
    }
    void Print_ticket()
    {
        cout<<"Seat Number : "<<Seat_number<<endl;
        cout<<"Meal Preference : "<<Meal_preference<<endl;
    }
}Ticket;

typedef struct Passenger_Details
{
    int Flight_ID,Booking_ID;
    string Class_type;
    vector<struct Ticket_Details> Ticket_count;
    Passenger_Details(){}
    Passenger_Details(int F_id, int B_id, string S_type, vector<struct Ticket_Details> &temp)
    {
        Flight_ID = F_id;
        Class_type = S_type;
        Booking_ID = B_id;
        for(int i=0; i<temp.size(); ++i)
        {
            Ticket_count.push_back(Ticket_Details(temp[i].Seat_number,temp[i].Meal_preference));
        }
    }

    void Print_summary(int B_id)
    {
        int User_booking_ID = B_id;
        for(int i=0;i<Passenger_data.size();++i)
        {
            if(Passenger_data[i].Booking_ID = User_booking_ID)
            {
                cout<<"Flight Number : "<<Passenger_data[i].Flight_ID<<endl;
                Ticket_count[i].Print_ticket();
            }
        }
        cout<<endl<<endl<<endl;
    }
}Passenger;

void Seat_arrangement(int C1, int C2, int C3, int Rows)
{
    No_C1 = C1;
    No_C2 = C2;
    No_C3 = C3;
    No_Rows = Rows;
    
    ptr[0] = new string**[No_Rows];
    ptr[1] = new string**[No_Rows];
    ptr[2] = new string**[No_Rows];

    for(int i=0;i<No_Rows;i++)
    {
        ptr[0][i]=new string*[No_C1];
        for(int a=0; a<No_C1; ++a)
            ptr[0][i][a] = new string;

        ptr[1][i]=new string*[No_C2];
        for(int b=0; b<No_C2; ++b)
            ptr[1][i][b] = new string;

        ptr[2][i]=new string*[No_C3];
        for(int c=0; c<No_C3; ++c)
            ptr[2][i][c] = new string;
    }

    for(int i=0;i<No_Rows;++i)
    {
        for(int a=0;a<No_C1;++a)
        {
            if(a==0)
                *ptr[0][i][a]="W";

            else if (a==No_C1-1)
                *ptr[0][i][a]="A";

            else
                *ptr[0][i][a]="M";
        }

        for(int b=0;b<No_C2;++b)
        {
            if(b==0 || b==No_C2-1)
                *ptr[1][i][b]="A";
            else
                *ptr[1][i][b]="M";
        }

        for(int c=0;c<No_C3;++c)
        {
            if(c==0)
                *ptr[2][i][c]="A";

            else if (c==No_C3-1)
                *ptr[2][i][c]="W";

            else
                *ptr[2][i][c]="M";
        }
    }
}

void Print_available_seats()
{
    int No_C = No_C1 + No_C2 + No_C3;

    cout<<endl<<endl;
    cout<<"    ";
    for(int n=0; n<No_C; ++n)
    {
        if(n==No_C1)
            cout<<" ";
        cout.width(3);cout.fill(' ');
        cout<<(char)(n+65);
    }

    cout<<endl<<endl;
    for(int i=0; i<No_Rows; ++i)
    {
        cout<<"  ";
        cout.width(2);cout.fill(' ');
        cout<<i+1;
        for(int a=0;a<No_C1;++a)
        {
            cout.width(3);cout.fill(' ');
            cout<<*ptr[0][i][a];
        }
        cout<<" ";

        for(int b=0;b<No_C2;++b)
        {
            cout.width(3);cout.fill(' ');
            cout<<*ptr[1][i][b];
        }
        cout<<" ";

        for(int c=0;c<No_C3;++c)
        {   
            cout.width(3);cout.fill(' ');
            cout<<*ptr[2][i][c];
        }
        cout<<endl;
    }
}
