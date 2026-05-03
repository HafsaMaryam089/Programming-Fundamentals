#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title, isbn, author, publisher;
    int copies, edition;
};

Book library[100] = {};
int totalBooks = 0;

void addBook() {
 
    Book b;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, b.title);

    cout << "Enter ISBN: ";
    getline(cin, b.isbn);

    cout << "Enter Author: ";
    getline(cin, b.author);

    cout << "Enter Publisher: ";
    getline(cin, b.publisher);

    cout << "Enter Number of Copies: ";
    cin >> b.copies;

    cout << "Enter Edition: ";
    cin >> b.edition;

    library[totalBooks] = b;
    totalBooks++;
    cout << "Book added " << endl;
}

void deleteBook() {
    string isbn;
    cin.ignore();
    cout << "Enter ISBN of the book to delete: ";
    getline(cin, isbn);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].isbn == isbn) {
            for (int j = i; j < totalBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            totalBooks--;
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void modifyBook() {
    string isbn;
    cin.ignore();
    cout << "Enter ISBN of the book to modify: ";
    getline(cin, isbn);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].isbn == isbn) {
            cin.ignore();
            cout << "Enter new Title: ";
            getline(cin, library[i].title);
            cout << "Enter new Author: ";
            getline(cin, library[i].author);
            cout << "Enter new Publisher: ";
            getline(cin, library[i].publisher);
            cout << "Enter new Number of Copies: ";
            cin >> library[i].copies;
            cout << "Enter new Edition: ";
            cin >> library[i].edition;
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void searchBookByISBN() {
    string isbn;
    cin.ignore();
    cout << "Enter ISBN to search: ";
    getline(cin, isbn);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].isbn == isbn) {
            cout << "Title: " << library[i].title << ", Author: " << library[i].author
                << ", Publisher: " << library[i].publisher << ", Copies: " << library[i].copies
                << ", Edition: " << library[i].edition << endl;
            return;
        }
    }
    cout << "Book not found.\n";
}

void searchBookByTitle() {
    string title;
    cin.ignore();
    cout << "Enter Title to search: ";
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < totalBooks; i++) {
        if (library[i].title == title) {
            cout << "ISBN: " << library[i].isbn << ", Author: " << library[i].author
                << ", Publisher: " << library[i].publisher << ", Copies: " << library[i].copies
                << ", Edition: " << library[i].edition << endl;
            found = true;
        }
    }
    if (!found) cout << "Book not found.\n";
}

void sortByTitle() {
    for (int i = 0; i < totalBooks - 1; i++) {
        for (int j = 0; j < totalBooks - i - 1; j++) {
            if (library[j].title > library[j + 1].title) {
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
    cout << "Books sorted by Title.\n";
}

void sortByEdition() {
    for (int i = 0; i < totalBooks - 1; i++) {
        for (int j = i + 1; j < totalBooks; j++) {
            if (library[i].title == library[j].title && library[i].edition > library[j].edition) {
                Book temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }
    cout << "Books sorted by Edition.\n";
}

void borrowBook() {
    string isbn;
    cin.ignore();
    cout << "Enter ISBN to borrow: ";
    getline(cin, isbn);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].isbn == isbn) {
            if (library[i].copies > 0) {
                library[i].copies--;
                cout << "Book borrowed successfully!\n";
            }
            else {
                cout << "No copies available.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void returnBook() {
    string isbn;
    cin.ignore();
    cout << "Enter ISBN to return: ";
    getline(cin, isbn);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].isbn == isbn) {
            library[i].copies++;
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void displayBooks() {
    if (totalBooks == 0) {
        cout << "No books in the library.\n";
        return;
    }
    for (int i = 0; i < totalBooks; i++) {
        cout << i + 1 << ". Title: " << library[i].title << ", ISBN: " << library[i].isbn << ", Author: " << library[i].author << ", Publisher: " << library[i].publisher << ", Copies: " << library[i].copies << ", Edition: " << library[i].edition << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Library Management System For Kinnaird  =====\n  Enter your choice: \n1. Add Book\n2. Delete Book\n3. Modify Book\n4. Search by ISBN\n5. Search by Title\n 6. Sort by Title\n7. Sort by Edition\n8. Borrow Book\n9. Return Book\n10. Display All Books\n0. Exit\n";
        cin >> choice;
      
        switch (choice) {
        case 1: addBook();
            break;
        case 2: deleteBook();
            break;
        case 3: modifyBook();
            break;
        case 4: searchBookByISBN();
            break;
        case 5: searchBookByTitle();
            break;
        case 6: sortByTitle();
            break;
        case 7: sortByEdition();
            break;
        case 8: borrowBook();
            break;
        case 9: returnBook();
            break;
        case 10: displayBooks();
            break;
        case 0: cout << "Exiting Library System \n"; break;
        default: cout << "choice invalid \n";
        }
    } while (choice != 0);

    return 0;
}