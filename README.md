# Library-Management-System

The Library Management System is a console-based software application written in C++ that helps in automating the operations of a library, such as managing books, issuing/returning books, and managing user (student and librarian) activities. The system consists of various functions like book issuance, return, listing, searching, and fine calculation, catering to both librarian and student needs. This system uses file handling in C++ to store book and user information and includes password-protected access for the librarian.

## Key Features and Functionalities:

### User Authentication:
The system has two primary user roles: Librarian and Student.
The Librarian section is password-protected, ensuring only authorized personnel can access administrative functionalities. The librarian can manage books, issue/return books, and modify user credentials.
Students can view book lists, search for books, and access general information without needing a password.

### Librarian Functionalities:

#### 1. View Book List: 
The librarian can view the list of books available in the library across different branches.

#### 2. Search for a Book: 
Allows the librarian to search for specific books by title or ID, displaying book details such as the author, publication, price, and availability.

#### 3. Add/Delete Book: 
The librarian can add new books or delete existing books from the inventory.

#### 4. Issue Book: 
The librarian can issue a book to a student, updating the book's availability and ensuring proper record keeping.

#### 5. Change Password: 
The librarian can change the password for system security, ensuring only authorized personnel have access.

### Student Functionalities:

#### 1. View Book List: 
Students can browse the list of available books, including relevant details.

#### 2. Search a Book: 
Students can search for specific books by title or ID to check availability.

#### 3. Return to Login Menu: 
Students can easily switch back to the login screen or exit the system.

### Book Issuance and Return:
The system allows books to be issued and returned. Issuing a book decreases its quantity, while returning it increases the available quantity.
Each book is identified by a unique Book ID, and both librarian and student operations are dependent on this identifier for precise record management.
When issuing a book, the system cross-checks the Book ID to ensure availability. When returning, the system verifies the Book ID to register the book return successfully.

### Fine Calculation (Planned Feature):
The system includes a planned function for calculating fines based on overdue returns. The fine is calculated by comparing the return date with the due date (set at 15 days), and the student is charged for any extra days beyond this period.

### File Handling:
The system uses file operations for data storage. Book information and user records are stored in files such as Books.txt and student.txt. This ensures data persistence between sessions, allowing the library's inventory and records to be maintained over time.
Functions such as fstream are used to read and write book and student data, ensuring seamless book issuance, return, and search operations.

### Branch-Specific Operations:
The system supports book management across multiple library branches. Both the librarian and students can select a branch to view or manage book lists, making it easier to segregate library operations based on location.

## Technologies and Concepts Used:
-> Programming Language: C++

-> File Handling: The use of fstream for reading and writing data to files like Books.txt and student.txt ensures that all records are stored persistently.

-> Object-Oriented Programming (OOP): Encapsulation is used to bundle the data and related functions in the Library class. The class contains methods for managing the library's functionalities.

-> Password Protection: Used for librarian login to protect administrative functions.

-> Console-based User Interface: The application runs in a terminal/console environment, providing menu-based navigation.
