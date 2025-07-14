#include <iostream>
#include<cstring>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <unistd.h>
#define TOTAL_VACCINE 400
using namespace std;

class vaccine_management
{
protected:
    string username;
    string password;
    string usn;
    //FOR VACCINE CENTER
    string center1= "1center";
    string center2= "2center";
    string center3= "3center";
    int sum_vaccine_c1 = 0; //Center1 vaccine Dose
    int sum_vaccine_c2 = 0; //Center2 vaccine Dose
    int sum_vaccine_c3 = 0; //Center3 vaccine Dose
    int add, center_no;
    //For Doctor Details
    string identification_id;
    char specialization[100];
    string center;
    //For User Details
    char name[100];
    char gender[100];
    int age;
    string adhaar;
    int c;
    string phone_no, profession, address, vaccine_name;
    int dose;


public:
  void menu();
  void admin();
  void admin_password();
  void user();
  void user_password();

  //For ADMIN
  void add_vaccine_stock();     //1
  void display_vaccine_stock(); //2
  void show_patient_data();     //3
  void show_data();             //3-a
  void applied_vaccine();       //4
  void add_doctor();            //5
  void search_doctor_data();    //6
  void display_doctor_data();   //7
  void doctor_show_data();      //7-a

  //FOR USER
  void search_center(); //1
};

void vaccine_management::menu()
{
  system("cls");
  int choice;
  cout << "\n\t\t\t\t************************************";
  cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
  cout << "\n\t\t\t\t*************************************";
  //MAIN MENU
  cout <<"\n\n\t\t -->> MAIN MENU <<--";
  cout <<"\n\n\t\t -->>1. ADMIN";
  cout <<"\n\n\t\t -->>2. USER";
  cout <<"\n\n\t\t -->>3. EXIT";
  cout <<"\n\n\t\tEnter Choice:";
  cin>> choice;
  //Calling relevant function as per choice
  switch (choice)
  {
    case 1:
      admin();
      break;
    case 2:
      user();
      break;
    case 3:
      system("cls");
      cout << "\n\n\t\t\t VACCINATION MANAGEMENT SYSTEM";
      Sleep(10);
      exit(0);
    default:
      cout <<"\n\n\t\t\t Invalid Choice... Please Enter Valid Option";
      cout <<"\n\n Press Any Key to Continue ";
      getch();
      menu();     
  }
}

void vaccine_management :: admin()
{
    admin_password();
A:    
    system("cls");
    int admin_choice;
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    //Admin Menu Options
    cout << "\n\n\t\t -->> ADMIN MENU <<--";
    cout << "\n\n\t\t 1. Add Vaccine Stock";
    cout << "\n\t\t 2. Show Vaccine Center";
    cout << "\n\t\t 3. Show Vaccine Stock";
    cout << "\n\t\t 4. Show Patient Data";
    cout << "\n\t\t 5. Show Total Number of Vaccines Applied";
    cout << "\n\t\t 6. Add New Doctor Data";
    cout << "\n\t\t 7. Search Doctor Data";
    cout << "\n\t\t 8. Show Doctor Data";
    cout << "\n\t\t 9. LOG OUT";
    cout << "\n\n\t\tEnter Choice:";
    cin >> admin_choice;
    switch (admin_choice)
    {
      case 1:
          add_vaccine_stock();
          goto A;
          break;
      case 2:
          search_center();
          goto A;
          break;
      case 3:
          display_vaccine_stock();
          goto A;
          break;    
      case 6:
          add_doctor();
          goto A;
          break;
      case 7:
          search_doctor_data();
          goto A;
          break;    
      case 8:
          display_doctor_data();
          goto A;
          break;         
              
      default:
          cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
          cout << "\n\n Press Any Key To Continue ";
          getch();
          goto A;
          break;    
    }
}

void vaccine_management :: user()
{
    system("cls");
    user_password();
    int user_choice;
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    //USER MENU OPTIONS
    cout << "\n\n\t\t -->> USER MENU <<--";
    cout << "\n\n\t\t 1. Search Vaccination Center";
    cout << "\n\t\t 2. Apply for Vaccine";
    cout << "\n\t\t 3. Show Details";
    cout << "\n\t\t 4. LOG OUT";
    cout << "\n\n\t\tEnter Choice:";
    cin >> user_choice; 
}

void vaccine_management ::admin_password()
{
  system("cls");
  char a_name[20];
  char a_password[20];
  int ch, capt = 0, capta = 0;
  int i=0;
  cout << "\n\t\t\t\t************************************";
  cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
  cout << "\n\t\t\t\t*************************************";
  cout << "\n\n\t\t -->> LOGIN ADMIN <<--";
  cout << "\n\n\t\tEnter Your Name: ";
  cin>> a_name;
  cout << "\n\t\tEnter Your Password: ";
  while ((ch = getch()) != 13)
  {
    cout << "*";
    a_password [i] = ch;
    i++;
  }
  a_password [i] = '\0';
  srand(time(0));
  capt = rand();
  cout << "\n\n\t\tCaptcha: " << capt;
  cout << "\n\t\tEnter Valid Captcha: ";
  cin >> capta;
  if((strcmp(a_name,"alankar")==0) && (strcmp(a_password,"als123") == 0) && (capt ==capta))
  {
      cout << "\n\n\n\t\t\t\t | Verifying Admin | \n\t\t\t\t";
      for (int a = 1; a < 8; a++)
      {
          Sleep(500);
          cout << "---";

      }
      cout << "\n\n Access Granted....\n\n";
      system("PAUSE");
      system("cls");
  }
  else
  {
      cout << "\n\n\n\t\t\t\t | Verifying Admin | \n\t\t\t\t";
      for (int a = 1; a < 8; a++)
      {
          Sleep(500);
          cout << "---";

      }
      cout << "\n\n Access Aborted....\n\n";
      system("PAUSE");
      system("cls");
      menu();

  }

}
void vaccine_management :: user_password()
{
  system("cls");
  char c;
  int user_choice;
  string fname,usern;
  ofstream fileo;
  ifstream filei;
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    cout<< "\n\n\t\t -->> USER SUB-MENU <<--";
    cout << "\n\t\t 1. Create Account";
    cout << "\n\t\t 2. Login";
    cout << "\n\t\t 3. Back";
    cout << "\n\t\tEnter Choice: ";
    cin >> user_choice;
    if (user_choice == 1)
    {
        system("cls");
        cout << "\n\n\t\t -->> REGISTRATION USER <<--";
        cout << "\n\n\t\tEnter Your Name: ";
        cin.ignore();
        getline(cin,username);
        cout<<"\n\t\tEnter Your Username:";
        cin >> usn;
        cout<<"\n\t\tEnter Your password: ";
        cin >> password;
        fname = usn + ".txt";
        fileo.open(fname.c_str());
        fileo << usn << endl << username<< endl << password;
        cout << "\n You are successfully registered";
        cout << "\n\nPress Any Key To Continue..";
        Sleep(500);
        getch();
        fileo.close();
        user();
    }
    else if(user_choice == 2)
    {
    system("cls");
    string u_name,u_pass;
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    //LOGIN USER
    cout << "\n\n\t\t -->> LOGIN USER <<--";
    cout << "\n\n\t\tEnter Your Username: ";
    cin>>u_name;
    cout << "\n\t\tEnter Your Password: ";
    cin >> u_pass;
    fname = usn + ".txt";
    fileo.open(fname.c_str());
    if(!filei.is_open() && filei.fail())
    {
      cout << "\nYou are not registered, PLease register before loggin in. \n";
      filei.close();
      getch();
      user_password();
    }
    getline(filei, usern);
    getline(filei,u_pass);
    if (u_name == usn && u_pass==password)
    {
        cout << "\nYou are successfully logged in.";
        cout << "\n\nPress Any KEy To Continue..";
        Sleep(500);
        getch();
    }
  }
  else if(user_choice == 3)
  {
      menu();
  }
  else
  {
      cout <<"\n\n\t\t\t Invalid C5hoice... Please Enter Valid Option";
      cout <<"\n\n Press Any Key to Continue ";
      getch();
      user_password();
  }
}    

//******************ADMIN*******************

void vaccine_management :: add_vaccine_stock()
{
A:
    fstream file;
    system ("cls");
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    cout << "\n\n\t\t-->> ADD VACCINE IN CENTER <<--";
    cout << "\n\n\t\t1." << center1 <<"\t\t2." << center2;
    cout << "\n\n\t\t3." << center3 <<"\t\t4. BACK";
    cout << "\n\t\tEnter Choice: ";
    cin>> center_no;
    switch (center_no)
    {
      case 1:
      {
        file.open("center1.txt",ios :: app);
        cout << "\n\t\t -->> For Center 1 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> add;
        sum_vaccine_c1 = sum_vaccine_c1 + add;
        file << sum_vaccine_c1;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c1;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\nPress Any Key to Continue..";
        getch();
        goto A;
        break;
      }
      case 2:
      {
        file.open("center2.txt",ios :: app);
        cout << "\n\t\t -->> For Center 2<<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> add;
        sum_vaccine_c2 = sum_vaccine_c2 + add;
        file << sum_vaccine_c2;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c2;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\nPress Any Key to Continue..";
        getch();
        goto A;
        break;
      }
      case 3:
      {
        file.open("center3.txt",ios :: app);
        cout << "\n\t\t -->> For Center 3 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> add;
        sum_vaccine_c3 = sum_vaccine_c3 + add;
        file << sum_vaccine_c1;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c3;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\nPress Any Key to Continue..";
        getch();
        goto A;
        break;
      }
      case 4:
          break;
      default:
          cout <<"\n\n\t\t\t Invalid Choice... Please Enter Valid Option";
          cout <<"\n\n Press Any Key to Continue ";
          getch();
          add_vaccine_stock();
          break;
    }
}

void vaccine_management :: search_center()
{
    system("cls");
    ifstream file;
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    cout << "\n\n\t\t-->> Various Vaccination Centers in Your City <<--";
    file.open("center1.txt");
    if(!file)
    {
        cout << "\nFile Not Found";
    }
    else
    {
      file >>sum_vaccine_c1;
      cout << "\n\n\t\t-->>" << center1 <<"<<--";
      cout << "\n\n\tTotal Vaccine: "<< sum_vaccine_c1;

    }
    file.close();
    file.open("center2.txt");
    if(!file)
    {
        cout << "\nFile Not Found";
    }
    else
    {
      file >>sum_vaccine_c2;
      cout << "\n\n\t\t-->>" << center2 <<"<<--";
      cout << "\n\n\tTotal Vaccine: "<< sum_vaccine_c2;

    }
    file.close();
    file.open("center3.txt");
    if(!file)
    {
        cout << "\nFile Not Found";
    }
    else
    {
      file >>sum_vaccine_c3;
      cout << "\n\n\t\t-->>" << center3 <<"<<--";
      cout << "\n\n\tTotal Vaccine: "<< sum_vaccine_c3;

    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
}

void vaccine_management::display_vaccine_stock()
{
    system("cls");
    ifstream ind;
    fstream file1, file2, file3;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t->> Available Vaccine Stock <<--\n\n";
    int i = 0;
    file1.open("center1.txt"); // Open Center1
    file2.open("center2.txt"); // Open Center2
    file3.open("center3.txt"); // Open Center3
    file1 >> sum_vaccine_c1;
    file2 >> sum_vaccine_c2;
    file3 >> sum_vaccine_c3;
    ind.open("Patient_Data.dat"); // Data take from Patient file
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(vaccine_management)))
        ;
    {
        i++;
    }
    ind.close();
    int s = TOTAL_VACCINE + sum_vaccine_c1 + sum_vaccine_c2 + sum_vaccine_c3 - i;
    file1.close();
    file2.close();
    file3.close();
    cout << "\n\nAvailable Number Of Vaccines are: " << s;
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void vaccine_management :: add_doctor()
{
    system("cls");
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    cout << "\n\n\t\t-->> ADD DOCTOR <<--";
    fstream file;
    cout << "\n\n\t\tEnter Name: ";
    fflush(stdin);
    cin >> name;
    cout << "\n\n\t\tEnter Identification Number: ";
    fflush(stdin);
    cin >> identification_id;
C:    
    cout << "\n\n\t\tEnter Aadhaar No.: ";
    cin >> adhaar;
    if(adhaar.length() !=12)
    {
      cout << "\nInvalid Adhaar Card Number";
      goto C;
    }
    else
    {
         //The first letter should not start with 0 and 1
         if(adhaar[0] == '0' || adhaar[0] == '1')
         {
            cout << "\nInvalid Adhaar Card Number";
            goto C;
         }
         else
         {
            cout << "\nValid Adhaar Card Number";
         }

    }
B:    
    cout<<"\n\n\t\tEnter Your Mobile Number:";
    cin >> phone_no;
    if(phone_no.length() != 10)
    {
        cout << "\nInvalid Phone Number";
        goto B;
    }
    else
    {
        //The first letter should not start with 0 and 1
        if (phone_no [0] =='0' || phone_no[0] == '1')
        {
            cout << "\nInvalid Phone Number";
            goto B;
        }
        else
        {
            cout << "\nValid Phone Number";
        }
    }
    cout << "\n\n\t\tEnter Gender (M/F): ";
    cin >> gender;
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    cout << "\n\n\t\tEnter Specialization: ";
    fflush(stdin);
    cin >> specialization;
    cout <<"\n\n\t\tEnter Center Alloted: ";
    cin >> center;
    file.open("Doctor_Data.dat", ios ::app | ios :: binary);
    file.write((char *)this, sizeof(vaccine_management));
    cout << "\n\nYOUR DATA HAS BEEN SUCCESSFULLY INSERTED" << endl;
    cout << "\n\nPress Any Key To Continue..";
    file.close();
    getch();

    
}
void vaccine_management :: display_doctor_data()
{
    system("cls");
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    cout << "\n\n\t\t-->> SHOW DOCTOR DATA <<--";
    ifstream file;
    file.open("Doctor_Data.dat", ios:: in | ios::binary);
    if(!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
      file.read((char *)this, sizeof(*this));
      while(!file.eof())
      {
          cout << "\n";
          doctor_show_data();
          file.read((char *)this, sizeof(*this));
      }
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();

}
void vaccine_management :: doctor_show_data()
{
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Name: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << name;
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Identification No.: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << identification_id;
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Aadhaar No.: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << adhaar;
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Mobile Number: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << phone_no;
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Gender: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << gender;
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Age: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << age;
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Specialization: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << specialization;
    cout.setf(ios :: left, ios :: adjustfield);
    cout.width(20);
    cout << endl << "Center Alloted: ";
    cout.setf(ios :: right, ios :: adjustfield);
    cout.width(25);
    cout << setfill(' ') << center;
}

void vaccine_management :: search_doctor_data()
{
    system("cls");
    int choice;
    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
    cout << "\n\t\t\t\t*************************************";
    cout << "\n\n\t\t-->> SEARCH DOCTOR DATA <<--";
    cout << "\n\t\t1. Search Data By Aadhaar \t\t\t2. Search Data By Identification ID" <<
    endl;
    cout << "\n\t\t3. Search Data By \t\t\t4. Search Data By Gender" << endl;
    cout << "\n\t\t5. EXIT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
      case 1:
      {
        int count = 0;
        string sadhaar;
        ifstream file;
        file.open("Doctor_Data.dat", ios:: in | ios::binary);
        system("cls");
        cout << "\n\t\t\t\t************************************";
        cout << "\n\t\t\t\t  *  VACCINATION MANAGEMENT SYSTEM  *";
        cout << "\n\t\t\t\t*************************************";
        cout << "\n\n\t\t-->> SEARCH DOCTOR DATA <<--";
        cout << "\n\n\t\tEnter Your Aadhaar No.:";
        cin >> sadhaar;
        if(!file)
        {
            cout <<"\nFile Not Found!";
        }
        else
        {
            file.read((char *)this, sizeof(vaccine_management));
        }
        while(!file.eof())
        {
          if(sadhaar.compare(adhaar) == 0)
          {
              count++;
              doctor_show_data();
          }
          file.read((char *)this, sizeof(vaccine_management));
        }
        if (count == 0)
        {
            cout << "\nrecord Not Found!";
        }
        file.close();
        cout << "\n\nPress Any Key To Continue..";
        getch();
        break;
      }
      default:
        break;
    }
}

int main()
{
  system("color B");
  vaccine_management system;
  system.menu();
}
