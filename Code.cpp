#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

class Library
{
public:
    char c[20] = "aaa";
    char bookName[50], authorName[50], publication[50], bookId[50];
    int price, quantity, B;

    /*  Library()
      {
          strcpy(bookName, "No Name");
          strcpy(authorName, "No Author");
          strcpy(publication, "No Publication");
          strcpy(bookId, "No Id");
          price = 0;
          quantity = 0;
          B = 0;
      }*/

    void start();
    void student();
    void AnDbook();
    void Librarian();
    void newBook();

    void pass();

    void changePass();

    void showBook(int);
    void bookList(int);
    void getBook(int);
    int branch(int);
    void issueBook();
    void check(char[], int, int);
    void fine(int, int, int, int, int, int);
};
void Library::pass()
{

    int i;
    char ch[20];
    cout << "\n\t\t\tEnter Password: ";
    cin >> ch;

    if (strcmp(ch, c) == 0)
    {
        Librarian();
    }

    else
    {
        cout << "\n\n\t\t\tWRONG PASSWORD!!\n\t\t\t";
        system("PAUSE");
        system("cls");
        start();
    }
}
void Library::changePass()
{

    int i;

    char cp[20], np[20];
up:
    cout << "\n\n\t\tEnter current password: ";
    cin >> cp;

    if (strcmp(cp, c) == 0)
    {
    pp:
        cout << "\n\n\t\tEnter new password: ";
        cin >> np;
    }
    else
    {
        cout << "\n\n\t\tWrong password entered";
        goto up;
    }

    if (strcmp(np, c) == 0)
    {
        cout << "\n\n\t\tPassword same as old password!!!";
        goto pp;
    }
    else
    {
        cout << "\n\n\t\tPassword changed successfully!!!!";

        strcpy(c, np);
        cout << "\n";
        system("PAUSE");
        system("cls");
        Librarian();
    }
}
void Library::start()
{
    int ch;
    cout << "\t~~~~~~~~~~~~~~~~~~~~ LIBRARY MANAGEMENT SYSTEM ~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t>>> LOGIN MENU <<<\n";
    ;
    cout << "\n\t\t\t1. Librarian\n\t\t\t2. Student\n\t\t\t3. Exit\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> ch;

    if (ch == 1)
        pass();
    else if (ch == 2)
    {
        system("cls");
        student();
    }
    else if (ch == 3)
        exit(0);
    else
    {
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        start();
    }
}

void Library::student()
{
    int ch;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~ STUDENT SECTION ~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t>>> MENU <<<\n";
    cout << "\n\t\t\t1. View BookList\n\t\t\t2. Search a Book\n\t\t\t3. Go to Login Menu\n\t\t\t4. Exit\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> ch;

    if (ch == 1)
        bookList(1);
    else if (ch == 2)
        getBook(1);
    else if (ch == 3)
    {
        system("cls");
        start();
    }
    else if (ch == 4)
        exit(0);
    else
    {
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        system("cls");
        student();
    }
}

void Library::Librarian()
{
    int ch;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~ ADMIN SECTION ~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t>>> MENU <<<\n";
    cout << "\n\t\t\t1. View BookList\n\t\t\t2. Search a Book\n\t\t\t3. Add/Delete Book\n\t\t\t4. Issue Book\n\t\t\t5. Go to Login Menu\n\t\t\t6. Change Password\n\t\t\t7. Exit\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        bookList(2);
        break;
    case 2:
        getBook(2);
        break;
    case 3:
        AnDbook();
        break;
    case 4:
        issueBook();
        break;
    case 5:
        system("cls");
        start();
        break;
    case 6:
        changePass();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        system("cls");
        Librarian();
    }
}

void Library::newBook()
{

    fflush(stdin);
    cout << "\n\n\t\t\tEnter Book Details:\n";
    cout << "\n\n\t\t\tEnter Book's Name: ";
    cin.getline(bookName, 50);

    cout << "\t\t\tEnter Author Name: ";
    cin.getline(authorName, 50);
    cout << "\t\t\tEnter Publication: ";
    cin.getline(publication, 50);
    cout << "\t\t\tEnter Book's ID: ";
    cin.getline(bookId, 50);
    cout << "\t\t\tEnter Book's Price: ";
    cin >> price;
    cout << "\t\t\tEnter Book's Quantity: ";
    cin >> quantity;
}

void Library::showBook(int i)
{
    cout << "\n\t\t\tBook Name: " << bookName << endl;
    cout << "\t\t\tBook's Author: " << authorName << endl;
    cout << "\t\t\tBook's ID: " << bookId << endl;
    cout << "\t\t\tBook's Publication: " << publication << endl;

    if (i == 2)
    {
        cout << "\t\t\tBook's Price: " << price << endl;
        cout << "\t\t\tBook's Quantity: " << quantity << endl;
    }
}

void Library::bookList(int i)
{
    int b, r = 0;
    system("cls");
    b = branch(i);
    system("cls");

    ifstream intf("Books.txt", ios::binary);
    if (!intf)
    {
        cout << "\n\t\t\tFile not Found!\n\t\t\t";
        // system("PAUSE");
    }
    else
    {
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~ BOOK LIST ~~~~~~~~~~~~~~~~~~~~\n";
        intf.read((char *)this, sizeof(*this));

        while (!intf.eof())
        {

            if (b == B)
            {
                if (quantity == 0)
                {
                }
                else
                {
                    r++;
                    cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~ " << r << " ~~~~~~~~~~~~~~~~~~~~\n";
                    showBook(i);
                }
            }

            intf.read((char *)this, sizeof(*this));
        }
    }
    cout << "\n\t\t\t";
    system("PAUSE");
    system("cls");
    if (i == 1)
        student();
    else
        Librarian();
}
void Library::AnDbook()
{
    char ch, str[100];
    int i = 0, b, cnt = 0;
    system("cls");

    cout << "\t\t\tMENU\n";
    cout << "\n\t\t\t1. Add new Book\n\t\t\t2. Delete a Book\n\t\t\t3. Go to Main Menu\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;

    if (i == 1 || 2)
    {
        goto sp;
    }
    else if (i == 3)
    {
        Librarian();
    }
sp:
    switch (i)
    {
    case 1:
    {
        system("cls");
        B = branch(2);
        newBook();
        ofstream outf;

        outf.open("Books.txt", ios::app | ios::binary);

        outf.write((char *)this, sizeof(*this));
        outf.close();
        cout << "\n\t\t\tBook added successfully!!!!";
        Librarian();
    }
        break;
    case 2:
    {
        system("cls");
        b = branch(2);
        // char ch[50];
        char str[100];
        cout << "\n\t\t\tEnter the Book Id: ";
        cin >> str;
        remove("Books.txt");
        cout << "\n\t\t\tDeletion successful";
        // ofstream f1("temp1.txt", ios::app|ios::binary);
        /*ifstream f2("Books.txt", ios::binary);
        f2.read((char*) this, sizeof(*this));
         //while(!f2.eof()){
                //for(i = 0; b == B && bookId[i] != '\0' && str[i] != '\0' && bookId[i] == str[i]; i++);
                if(bookId[i] ==  str[i]  )
                {
                    remove("Books.txt");
                    cout<<"\n\t\t\tDeletion successful";
                    }
                    else{
                        cout<<"\n\t\t\tDeletion Unsuccessful";
                    }

                 /*   cnt++;
                    f2.read((char*) this, sizeof(*this));
                }
                else{
                    f1.write((char*) this, sizeof(*this));
                    f2.read((char*) this, sizeof(*this));
                }
            }
            f2.close();
            f1.close();
            remove("Books.txt");
            rename("temp1.txt", "Books.txt");
            cout<<"Deletion successful";


/*
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Books.txt");
        while (!read.eof())
        {
            // read >> bookName;
            read.ignore();
            // getline(read, bookName[i]);
            read >> bookName;
            read >> authorName;
            read >> bookId;
            read >> publication;
            read >> price;
            read >> quantity;
            if (*bookName != ch)
            {
                tempFile << "\n"
                         << bookName;
                tempFile << "\n"
                         << authorName;
                tempFile << "\n"
                         << bookId;
                tempFile << "\n"
                         << publication;
                tempFile << "\n"
                         << price;
                tempFile << "\n"
                         << quantity;
            }
        }
        read.close();
        tempFile.close();
        remove("Books.txt");
        rename("temp.txt", "Books.txt");
        cout << "\n\tData deleted successfuly";

        // char filename[]="D:\\C C++\\MiniProject2\\Books.txt";
        /* fstream stud;
         fstream temp;

         stud.open("Books.txt",ios::in);
         temp.open("temp.txt",ios::out);
         //char ch[50];
         char bookNam [50];
         char authorNam[50];
         char publicatio[50];
         char bookI[50];
         int pric;
         int quantit;
          char ch[50];
          cin.ignore();





         cout << " \n\t\tEnter the BookName : ";
         cin.getline(ch,50);

          while(!stud.eof())
          {
              stud.getline(bookNam,50);
              stud.getline(authorNam,50);
              stud.getline(publicatio,50);
              stud.getline(bookI,50);
              stud >> (price);
              stud >> (quantity);

              if(strcmp(bookNam,ch)==0)
              {
                  continue;
              }
              else
              {
                  temp<< bookNam<<'\n\t\t\t'<<authorNam<<'\n\t\t\t'<<publicatio<<'\n\t\t\t'<<bookI<<'\n\t\t\t'<<pric<<'\n\t\t\t'<<quantit<<'\n';
              }


          }
          temp.close();
          stud.close();

          stud.open("Books.txt",ios::out);
          temp.open("temp.txt",ios::in);
          while(!temp.eof())
          {
              temp.getline(bookNam,50);
              temp.getline(authorNam,50);
              temp.getline(publicatio,50);
              temp.getline(bookI,50);
              temp >> (pric);
              temp >> (quantit);

              stud<< bookNam<<'\n\t\t\t'<<authorNam<<'\n\t\t\t'<<publicatio<<'\n\t\t\t'<<bookI<<'\n\t\t\t'<<pric<<'\n\t\t\t'<<quantit<<'\n';


          }
          temp.close();
          stud.close();
          remove("temp.txt");
          cout<<"\n done !!! \n";*/

        /*{ system("cls");
        b = branch(2);
        ifstream intf1("Books.txt", ios::binary);

        if(!intf1){
            cout << "\n\t\t\tFile not Found\n\t\t\t";
            system("PAUSE");
            intf1.close();
            system("cls");
            Admin();
        }

        intf1.close();
        system("cls");
        cout << "\n\t\t\tMENU\n";
        cout << "\n\t\t\t1. Delete by Bookname\n\t\t\t2. Delete by Book ID\n";
        cout << "\n\t\t\tEnter your choice: ";
        cin >> i;
        fflush(stdin);

        if(i == 1){
            system("cls");
            cout << "\n\t\t\tEnter Book's Name: ";
            cin.getline(str, 100);
            ofstream outf("temp.txt", ios::out|ios::binary);
            ifstream intf("Books.txt", ios::in|ios::binary);
            intf.read((char*) this, sizeof(*this));


            int res = strcmp((bookName),str);
            while(!intf.eof()){
                //for(i = 0; b == B && bookName[i] != '\0' && str[i] != '\0' && bookName[i] == str[i]; i++);
                if(res==0)
                {
                    intf.read((char*) this, sizeof(*this));
                    //intf.read((char*) this, sizeof(*this));
                }
              else{
                   // outf.write((char*) this, sizeof(*this));
                    outf.write((char*) this, sizeof(*this));
              }
            }
            outf.close();
            intf.close();
            remove("Books.txt");
            rename("temp.txt", "Books.txt");
            cout << "\n\t\t\tBook Deleted!\n\t\t\t";
            system("pause");
            system("cls");
        }











        /*system("cls");
        b= branch(2);
        //char filename[]="D:\\C C++\\MiniProject2\\Books.txt";
        //     fstream stud;
        // fstream temp;

        // stud.open("Books.txt",ios::in);
        char ch[50];
        /* temp.open("temp.txt",ios::out);3
         bookName [50];
         authorName[50];
         publication[50];
         bookId[50];
         price;
         quantity;
         char ch[50];
         cin.ignore();*/

        /*cout << " \n\t\t\t Enter the BookName : ";
        cin >> ch;
        
            remove("Books.dat");
            cout << "\n\t\t\t Book removed!!!";
         /*while(!stud.eof())
         {
             stud.getline(bookName,50);
             stud.getline(authorName,50);
             stud.getline(publication,50);
             stud.getline(bookId,50);
             stud >> (price);
             stud >> (quantity);

             if(strcmp(bookName,ch)==0)
             {
                 continue;
             }
             else
             {
                 temp<< bookName<<'\n\t\t\t'<<authorName<<'\n\t\t\t'<<publication<<'\n\t\t\t'<<bookId<<'\n\t\t\t'<<price<<'\n\t\t\t'<<quantity<<'\n';
             }


         }
         temp.close();
         stud.close();

         stud.open("Books.txt",ios::out);
         temp.open("temp.txt",ios::in);
         while(!temp.eof())
         {
             temp.getline(bookName,50);
             temp.getline(authorName,50);
             temp.getline(publication,50);
             temp.getline(bookId,50);
             temp >> (price);
             temp >> (quantity);

             stud<< bookName<<'\n\t\t\t'<<authorName<<'\n\t\t\t'<<publication<<'\n\t\t\t'<<bookId<<'\n\t\t\t'<<price<<'\n\t\t\t'<<quantity<<'\n';


         }
         temp.close();
         stud.close();
         remove("temp.txt");
         cout<<"\n done !!! \n";

             }
             }
    }*/}
        break;
        case 3:
        {
            Librarian();
        }
        break;
        }
}
void Library::getBook(int x)
{
    int i, b, cnt = 0;
    char ch[100];
    system("cls");
    b = branch(x);

    ifstream intf("Books.txt", ios::binary);
    if (!intf)
    {
        cout << "\n\t\t\tFile not Found!\n\t\t\t";
        system("PAUSE");
        system("cls");
        if (x == 1)
            student();
        else
            Librarian();
    }
    system("cls");
    cout << "\n\t\t\tMENU\n";
    cout << "\n\t\t\t1. Search by Book's Name\n\t\t\t2. Search by Book's ID\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;

    fflush(stdin);
    intf.read((char *)this, sizeof(*this));
    if (i == 1)
    {
        cout << "\n\t\t\tEnter Book's Name: ";
        cin.getline(ch, 100);
        system("cls");

        while (!intf.eof())
        {
            for (i = 0; b == B && quantity != 0 && (ch[i] == bookName[i]); i++)
            {

                if (bookName[i] == '\0' && ch[i] == '\0')
                {
                    cout << "\n\t\t\tBook Found!\n";
                    showBook(x);
                    cnt++;
                    break;
                }
            }
            intf.read((char *)this, sizeof(*this));
        }
    }
    else if (i == 2)
    {
        cout << "\n\t\t\tEnter Book's ID: ";
        cin.getline(ch, 100);
        system("cls");

        while (!intf.eof())
        {
            for (i = 0; b == B && quantity != 0 && ch[i] == bookId[i]; i++)
            {
                if (bookId[i] == '\0' && ch[i] == '\0')
                {
                    cout << "\n\t\t\tBook Found!\n";
                    showBook(x);
                    cnt++;
                    break;
                }
            }
            intf.read((char *)this, sizeof(*this));
        }
    }
    else
    {
        cnt++;
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        system("cls");
        getBook(x);
    }
    intf.close();
    if (cnt == 0)
        cout << "\n\t\t\tBook not Available!\n";
    cout << "\n\t\t\t";
    system("PAUSE");
    system("cls");
    if (x == 1)
        student();
    else
        Librarian();
}

int Library::branch(int x)
{
    int i;
    cout << "\n\t\t\tMENU\n";
    cout << "\n\t\t\t1. TOC\n\t\t\t2. Electrical\n\t\t\t3. Electronics\n\t\t\t4. OOPs\n\t\t\t5. Mechanics\n\t\t\t6. Back to Main Menu\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;

    if (i < 6 && i > 0)
        return i;
    else if (i == 6)
    {
        system("cls");
        if (x == 1)
            student();
        else
            Librarian();
    }
    else
    {
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
      system("PAUSE");
        system("cls");
        branch(x);
    }
}

void Library::issueBook()
{
    char s[50], str[20];
    int b, i, j, cnt = 0;
    system("cls");
    cout << "\n\t\t\tMENU\n";
    cout << "\n\t\t\t1. Issue Book\n\t\t\t2. View Issued Books\n\t\t\t3. Search Student who Issued Book\n\t\t\t4. Return Book\n\t\t\t5. Back to Main Menu\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;

    fflush(stdin);
    if (i == 1)
    {
        system("cls");
        b = branch(2);
        system("cls");
        fflush(stdin);
        cout << "\n\t\t\tEnter Book's Name: ";
        cin.getline(bookName, 100);
        cout << "\n\t\t\tEnter Book's ID: ";
        cin.getline(bookId, 20);
        check(bookId, b, 1);
        cout << "\n\t\t\tEnter Student's Name: ";
        cin.getline(authorName, 100);
        cout << "\n\t\t\tEnter Student's ID: ";
        cin.getline(publication, 20);
        cout << "\n\t\t\tEnter Date: ";
        cin >> quantity >> B >> price;

        ofstream outf("student.txt", ios::binary | ios::app);
        outf.write((char *)this, sizeof(*this));
        outf.close();
        cout << "\n\t\t\tBook Issued!\n";
    }
    else if (i == 2)
    {
        ifstream intf("student.txt", ios::binary);
        system("cls");
        cout << "\n\t\t\tIssued Books:\n";
        intf.read((char *)this, sizeof(*this));

        i = 0;
        while (!intf.eof())
        {
            i++;
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~ " << i << ". ~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\n\t\t\tStudent's Name: " << authorName << "\n\t\t\tStudent's ID: " << publication << "\n\t\t\tBook's Name: " << bookName << "\n\t\t\tBook's ID: " << bookId << "\n\t\t\tDate: " << quantity << "/" << B << "/" << price << endl;
            intf.read((char *)this, sizeof(*this));
        }
        intf.close();
    }
    else if (i == 3)
    {
        system("cls");
        fflush(stdin);
        cout << "\n\t\t\tEnter Student's Name: ";
        cin.getline(s, 50);
        cout << "\n\t\t\tEnter Student's ID: ";
        cin.getline(str, 50);
        system("cls");

        ifstream intf("student.txt", ios::binary);
        intf.read((char *)this, sizeof(*this));

        while (!intf.eof())
        {
            for (i = 0; publication[i] != '\0' && str[i] != '\0' && publication[i] == str[i] && authorName[i] == s[i]; i++)
                ;
            if (publication[i] == '\0' && str[i] == '\0')
            {
                cnt++;
                if (cnt == 1)
                {
                    cout << "\n\t\t\tDETAILS: \n";
                    cout << "\n\t\t\tStudent's Name: " << authorName;
                    cout << "\n\t\t\tStudent's ID: " << publication;
                }

                cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~ " << cnt << " . Book Details ~~~~~~~~~~~~~~~~~~~~\n";
                cout << "\n\t\t\tBook's Name: " << bookName;
                cout << "\n\t\t\tBook's ID: " << bookId;
                cout << "\n\t\t\tDate: " << quantity << "/" << B << "/" << price << endl;
            }
            intf.read((char *)this, sizeof(*this));
        }
        intf.close();
        if (cnt == 0)
            cout << "\n\t\t\tNo Record Found\n";
    }

    else if (i == 4)
    {
        system("cls");
        b = branch(2);
        system("cls");
        fflush(stdin);

        cout << "\n\t\t\tEnter Book ID: ";
        cin.getline(str, 50);
        check(str, b, 2);
        cout << "\n\t\t\tEnter Student's ID: ";
        cin.getline(s, 50);
        // cout << "\n\t\t\tEnter Present Date: ";
        // cin >> d >> m >> y;

        ofstream outf("temp.txt", ios::app | ios::binary);
        ifstream intf("student.txt", ios::binary);
        intf.read((char *)this, sizeof(*this));

        while (!intf.eof())
        {
            for (i = 0; publication[i] != '\0' && str[i] != '\0' && publication[i] == s[i]; i++)
                ;
            for (j = 0; bookId[j] != '\0' && s[j] != '\0' && str[j] == bookId[j]; j++)
                ;
            if (publication[i] == '\0' && str[i] == '\0' && bookId[j] == '\0' && s[j] == '\0' && cnt == 0)
            {
                cnt++;
                intf.read((char *)this, sizeof(*this));
                // fine(quantity, B, price, d, m, y);
                cout << "\n\t\t\tBook Returned!\n";
            }
            else
            {
                outf.write((char *)this, sizeof(*this));
                intf.read((char *)this, sizeof(*this));
            }
        }
        intf.close();
        outf.close();
        cout << "\t\t\t";
        system("PAUSE");
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
    else if (i == 5)
    {
        system("cls");
        Librarian();
    }
    else
    {
        cout << "\n\t\t\tInvalid Input!\n\t\t\t";
        system("PAUSE");
        system("cls");
        Librarian();
    }
}

void ::Library::check(char s[], int b, int x)
{
    int i, cnt = 0;
    fstream intf("Books.txt", ios::in | ios::out | ios::ate | ios::binary);
    intf.seekg(0);
    intf.read((char *)this, sizeof(*this));

    while (!intf.eof())
    {
        for (i = 0; b == B && quantity != 0 && bookId[i] != '\0' && s[i] != '\0' && s[i] == bookId[i]; i++);
            
        if (bookId[i] ==  s[i] )
        {
            cnt++;
            if (x == 1)
                quantity--;
            else
                quantity++;
           intf.seekp(intf.tellp() - sizeof(*this));
            intf.write((char *)this, sizeof(*this));
            break;
        }
        intf.read((char *)this, sizeof(*this));
    }
    if (cnt == 0)
    {
        cout << "\n\t\t\tBook Not Found!\n\t\t\t";
        system("PAUSE");
        system("cls");
        issueBook();
    }
    intf.close();
}

/*void Library::fine(int d, int m, int y, int dd, int mm, int yy)
{
    long int n1, n2;
    int yrs, l, i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    n1 = y * 365 + d;
    for (i = 0; i < m - 1; i++)
        n1 += monthDays[i];
    yrs = y;
    if (m <= 2)
        yrs--;
    l = yrs / 4 - yrs / 100 + yrs / 400;
    n1 += l;
    n2 = yy * 365 + dd;
    for (i = 0; i < mm - 1; i++)
        n2 += monthDays[i];
    yrs = yy;
    if (m <= 2)
        yrs--;
    l = yrs / 4 - yrs / 100 - yrs / 400;
    n2 += l;
    n1 = n2 - n1;
    n2 = n1 - 15;
    if (n2 > 0)
        cout << "\n\t\t\tTotal fine is: " << n2 << endl;
}*/

int main()
{
    Library ob;
    ob.start();
    return 0;
}
