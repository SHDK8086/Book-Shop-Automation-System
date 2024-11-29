#include<iostream>
#include<string>
#include <vector>   
#include <iomanip>

using namespace std;

struct books {
	int NO;
	string BookName;
	int stockAva;
	double bPrice;
};

struct cartBook {
	books item;
	double selectedBook;
};

void logOutC();
void addBooks();
void viewBooksC();
void billingSystem();
void cashierHomePage();
void logOutO();
void search();
void addBook();
void viewBooksO();
void ownerHomePage();
void help();
int newBookId = 106;

vector<books>book;
vector<cartBook>cart;

void logOutC() {

	string lo;
	cout << "\n\t\t\t   Do you want to log out" << endl << endl;
	cout << "\t\t\t     'YES'        'NO'" << endl << endl << "\n";
	cout << " * Enter what you need --> ";
	cin >> lo;

	if (lo == "yes") {
		system("cls");
		cout << "\n";
		cout << "\t\t\t             Thank You !!!" << endl << endl
			<< "\t\t\t  _You have successfully logged out_" << endl;
		cout << "\t\t\t**************************************" << endl << endl << endl << endl << endl;

	}

	else if (lo == "no") {
		system("cls");
		cashierHomePage();
	}
	else {
		system("cls");
		cout << "\n \t\t ~~~ Please enter 'YES or NO' to log out ~~~" << endl << endl;
		logOutC();
	}
}

void printBill() {

	string customerName;
	int telNumber;
	string orderNo;
	cout << "\n" << endl;
	cout << "\t\t\t    ~ Enter customer details in here ~ " << endl;
	cout << "\t\t\t  *************************************" << endl << endl;
	cout << "\n" << endl;
	cout << "  * Enter Order NO                  : ";
	cin >> orderNo;
	cout << "\n" << endl;
	cout << "  * Enter Customer Name             : ";
	cin >> customerName;
	cout << "\n" << endl;
	cout << "  * Enter Customer telephone number : ";
	cin >> telNumber;
	cout << endl << endl << endl;
	system("cls");
	int option;

	double total = 0.0;
	double discountPercentage = 0.0;
	int noOfBooks = cart.size();

	cout << "\n";
	cout << "\t\t\t=================================================================" << endl << endl;
	cout << "\t\t\t                | Books are the mirrors of the soul |" << endl;
	cout << "\t\t\t                          ___NETHRA SHOP___" << endl << endl;
	cout << "\t\t\t                     No.20,Dalada Weediya,Kandy" << endl;
	cout << "\t\t\t" << left << setw(36) << "TEL: +94769799681" << "Open Time : 9:00AM to 6:00PM" << endl;
	cout << "\t\t\t*****************************************************************" << endl;
	cout << "\t\t\tODER NO :  " << orderNo << endl;
	cout << "\t\t\t*****************************************************************" << endl;
	cout << "\t\t\t" << left << setw(23) << "BOOK NAME" << left << setw(16) << "UNIT PRICE" << left
		<< setw(14) << "QUANTITY" << "TOTAL PRICE" << endl;
	cout << "\t\t\t`````````````````````````````````````````````````````````````````" << endl << endl;

	for (int i = 0; i < noOfBooks; i++) {
		double totalPrice = cart[i].selectedBook * cart[i].item.bPrice;
		total += totalPrice;
		if (total > 4500.0) {
			discountPercentage = 0.3;  

		}
		cout << "\t\t\t" << left << setw(26) << cart[i].item.BookName << left << setw(16) << cart[i].item.bPrice << left
			<< setw(15) << cart[i].selectedBook << totalPrice << "/=" << endl;
	}

	cout << "\t\t\t-----------------------------------------------------------------" << endl;
	cout << "\t\t\t" << left << setw(54) << "SUBTOTAL AMOUNT      :" << "Rs." << total << "/=" << endl;
	double discountAmount = total * discountPercentage;
	total -= discountAmount;

	cout << "\t\t\t" << left << setw(54) << "DISCOUNT AMOUNT(30%) : " << "Rs." << discountAmount << "/=" << endl;
	cout << "\t\t\t-----------------------------------------------------------------" << endl << endl;
	cout << "\t\t\t" << left << setw(54) << "   TOTAL AMOUNT :" << "Rs." << total << "/=" << endl << endl;
	cout << "\t\t\t*****************************************************************" << endl;
	cout << "\t\t\tCustomer Name :" << left << setw(26) << customerName << "Tel Number :" << telNumber << endl;
	cout << "\t\t\t-----------------------------------------------------------------" << endl;
	cout << "\t\t\tAll rights reserved�" << endl << endl;
	cout << "\t\t\t       * THANK YOU " << customerName << " FOR VISITING NETHRA BOOK SHOP * " << endl;
	cout << "\t\t\t                      *** COME AGAIN ***" << endl;
	cout << "\t\t\t`````````````````````````````````````````````````````````````````" << endl << endl << endl;
	cart.clear();
	cout << "\n" << endl << endl;
	cout << "\t * Enter number '1' to go to the billing system ---> ";
	cin >> option;

	switch (option) {
	case 1:
		system("cls");
		billingSystem();
		break;
	default:
		system("cls");
		cashierHomePage();
		break;
	}

	exit(0);
}

void addBooks() {
	int option;
	int NO;
	int stockAva;

	cout << "\n";
	cout << "\t\t\t\t    Available Books in Store" << endl;
	cout << "\t\t\t\t  ****************************" << endl;
	cout << "\n";
	cout << "\t\t===================================================================" << endl;
	cout << "\t\t" << left << setw(10) << "NO" << left << setw(26) << "Book Name"
		<< left << setw(20) << "Available Stock" << left << setw(16) << "Book price" << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl << endl;
	int noOfBooks = book.size();

	for (int i = 0; i < noOfBooks; i++)
	{
		books item = book[i];
		cout << "\t\t" << left << setw(10) << item.NO << left << setw(28) << item.BookName
			<< left << setw(20) << item.stockAva << left << setw(18) << item.bPrice << endl;
	}
	cout << "\t\t-------------------------------------------------------------------" << endl << endl;
	cout << "\n";
	cout << " *___Now you can select the books that the customer purchased___*\n"
		<< endl << "\t\t| press '0' to stop adding items |" << endl << endl;
	cout << "\n";

	do {
		cout << "\t* Enter here book number customer wishes to purchase : ";
		cin >> NO;
		if (NO == 0) {
			break;
		}
		cout << "\t* How many books that customer purchased           : ";
		cin >> stockAva;
		cout << endl;
		int noOfBooks = book.size();
		bool itemFound = false;

		for (int i = 0; i < noOfBooks; i++)
		{
			books addItem = book[i];
			if (addItem.NO == NO) {
				cartBook NewcartBook;
				NewcartBook.item = addItem;
				NewcartBook.selectedBook = stockAva;
				cart.push_back(NewcartBook);
				itemFound = true;
				break;
			}

		}
		if (!itemFound) {
			cout << "\t\t\t || Book not found ||" << endl << endl;
		}

	} while (true);

	system("cls");
	cout << "\n" << endl;
	cout << "     *** Items added to the cart successfully ***" << endl << endl;
	cout << "\n\t\t* Press no.1 to go to the billing system menu" << endl
		<< "\t\t* Press no.2 print bill" << endl << endl;
	cout << "\t * Enter Here ---> ";

	cin >> option;
	switch (option) {
	case 1:
		system("cls");
		billingSystem();
		break;
	case 2:
		system("cls");
		printBill();
		break;
	default:
		system("cls");
		cout << "\n";
		cout << "\t\t\t\t    *** Sorry *** | Invalid option selected " << endl << endl;
		cout << "\t\t\t\t  You will have to add the products back to the cart " << endl;
		cout << "\t\t\t\t*****************************************************" << endl << endl << endl;
		addBook();
	}

}

void viewBooksC() {

	int option;

	cout << "\n";
	cout << "\t\t\t    ~ Available Books in Nethra Book Shop ~" << endl;
	cout << "\t\t\t  *******************************************" << endl << endl;
	cout << "\n";
	cout << "\t\t===================================================================" << endl;
	cout << "\t\t" << left << setw(10) << "NO" << left << setw(26) << "Book Name"
		<< left << setw(20) << "Available Stock" << left << setw(16) << "Book price" << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl << endl;
	int noOfBooks = book.size();

	for (int i = 0; i < noOfBooks; i++)
	{
		books item = book[i];
		cout << "\t\t" << left << setw(10) << item.NO << left << setw(28) << item.BookName
			<< left << setw(20) << item.stockAva << left << setw(18) << item.bPrice << endl;
	}
	cout << "\t\t-------------------------------------------------------------------" << endl << endl;
	cout << "\n  * Enter Number '1' to go to the previous menu ;" << endl << endl
		<< "\n\t\t\t * Enter here : ";
	cin >> option;

	switch (option) {
	case 1:
		system("cls");
		billingSystem();
		break;
	default:
		system("cls");
		cout << "\n";
		cout << "\t\t              ___Invalid number entered___" << endl
			<< "\t\t   * Enter correct number to go to the previous menu *" << endl << endl;
		viewBooksC();
		break;
	}

}

void billingSystem() {

	int option;
	cout << "\n";
	cout << "\n\t\t\t       ***  Options  ***\n\n" << endl << endl << endl
		<< "\t1. View Available Books" << endl <<
		"\t2. Add Books to cart" << endl <<
		"\t3. Access to print the bill" << endl <<
		"\t4. Exit" << endl << endl;

	cout << "\t             * Select your option : ";
	cin >> option;
	cout << "\n";
	switch (option) {

	case 1:
		system("cls");
		viewBooksC();
		break;
	case 2:
		system("cls");
		addBooks();
		break;
	case 3:
		system("cls");
		printBill();
		break;
	case 4:
		system("cls");
		cashierHomePage();
		break;
	default:
		system("cls");
		cout << "\n";
		cout << "\t\t\t *** Invalid option selected ***" << endl << endl;
		billingSystem();
		break;
	}
}

void cashierHomePage() {

	int option;
	cout << endl;
	cout << "\t\t        * Welcome to Nethra Book Shop *\n\n";
	cout << "\n\t\t\t       ***  Options  ***\n\n" << endl;
	cout << "\n";
	cout << " \t1.Billing System" << endl << endl <<
		" \t2.Log Out" << endl << endl;
	cout << "   * Select your option: ";
	cin >> option;

	switch (option) {
	case 1:
		system("cls");
		billingSystem();
		break;
	case 2:
		system("cls");
		logOutC();
		break;
	default:
		system("cls");
		cout << "\n \t\t\t\t\t ___Invalid Option Selected___" << endl << endl
			<< "\t\t\t\t\t |Sorry for the inconvnience|" << endl
			<< "\t\t\t\t\t      Please log in again" << endl
			<< "\t\t\t\t\t              ***\n" << endl << endl << endl;
		exit(0);
		break;
	}
}

void cashierLogin() {
	string username;
	string password;
	string cashierUs = "cashier";
	string cashierPw = "cashier123";

	for (int counter = 3; counter > 0; --counter) {
		cout << "\n" << endl;
		cout << "\t\t\t ~~~ Cashier Authentication ~~~" << endl;
		cout << "\t\t\t********************************" << endl << endl;
		cout << " \n \t* Enter your username  : ";
		cin >> username;
		cout << " \n \t* Enter your passwword : ";
		cin >> password;

		if ((username == cashierUs) && (password == cashierPw)) {

			system("cls");
			cashierHomePage();
			break;
		}
		else {
			system("cls");
			cout << "\n \t\t\t  __Wrong username or password__" << endl;
			cout << "\t\t\t**********************************" << endl << endl;
			cout << "\t\t\t       Please try again" << endl;
			cout << "\t\t\t You have another " << "'" << counter - 1 << "'" << "Attempts" << endl << endl;
		}
	}
}

void logOutO() {
	string lo;
	cout << "\n\t\t\t   Do you want to log out" << endl << endl;
	cout << "\t\t\t     'YES'        'NO'" << endl << endl << "\n";
	cout << " * Enter what you need --> ";
	cin >> lo;


	if (lo == "yes") {
		system("cls");
		cout << "\n";
		cout << "\t\t\t             Thank You !!!" << endl << endl
			<< "\t\t\t  _You have successfully logged out_" << endl;
		cout << "\t\t\t**************************************" << endl << endl << endl << endl << endl;

	}

	else if (lo == "no") {
		system("cls");
		ownerHomePage();
	}
	else {
		system("cls");
		cout << "\n \t\t ~~~ Please enter 'YES or NO' to log out ~~~" << endl << endl;
		logOutO();
	}
}
void search() {

	string searchKeyword;
	int option;

	cout << "\n\t\t\t   *** Search for a Book ***" << endl;
	cout << "\t\t\t********************************" << endl << endl;
	cout << "\n\t\t Enter the name of the book to search: ";
	cin >> searchKeyword;

	bool found = false;


	for (const auto& item : book) {
		if (item.BookName == searchKeyword) {
			found = true;
			system("cls");
			cout << "\n";
			cout << "\t\t\t\t ---------------------------------" << endl;
			cout << "\t\t\t\t |       *** Book Found! ***     |" << endl;
			cout << "\t\t\t\t ---------------------------------" << endl << endl << endl << endl << endl;
			cout << "\t\t===================================================================" << endl;
			cout << "\t\t" << left << setw(10) << "NO" << left << setw(26) << "Book Name"
				<< left << setw(20) << "Available Stock" << left << setw(16) << "Book price" << endl;
			cout << "\t\t-------------------------------------------------------------------" << endl;
			cout << "\t\t" << left << setw(10) << item.NO << left << setw(28) << item.BookName
				<< left << setw(20) << item.stockAva << left << setw(18) << item.bPrice << endl;
			cout << "\t\t-------------------------------------------------------------------" << endl << endl;
			break;
		}
	}

	if (!found) {
		system("cls");
		cout << "\n";
		cout << "\t\t\t ---------------------------------" << endl;
		cout << "\t\t\t |     *** Book Not Found! ***   |" << endl;
		cout << "\t\t\t ---------------------------------" << endl << endl << endl;
	}

	cout << "\n  * Enter Number '1' to go to the previous menu ;" << endl << endl
		<< "\n\t\t\t * Enter here : ";
	cin >> option;

	switch (option) {
	case 1:
		system("cls");
		ownerHomePage();
		break;
	default:
		system("cls");
		cout << "\n";
		cout << "\t\t              ___Invalid number entered___" << endl
			<< "\t\t   * Enter correct number to go to the previous menu *" << endl << endl << endl;
		cout << "\n\t\t\t * Enter here : ";
		cin >> option;

		system("cls");
		ownerHomePage();
		break;
	}
}

void addBook() {

	int option;

	books newBook;
	cout << "\n";
	newBook.NO = newBookId;
	cout << "\n\t\t\t* Enter Book Name     : ";
	cin >> newBook.BookName;
	cout << "\n\t\t\t* Enter Stock         : ";
	cin >> newBook.stockAva;
	cout << "\n\t\t\t* Enter Book Price    : ";
	cin >> newBook.bPrice;
	book.push_back(newBook);
	newBookId += 1;

	system("cls");
	cout << "\n";
	cout << "\t\t    # New Book Added Successfully #" << endl;
	cout << "\t\t ------------------------------------" << endl << endl;
	cout << "\n  * Enter Number '1' to go to the previous menu ;" << endl <<
		"\n  * Enter Number '2' to add another book ;" << endl << endl
		<< "\n\t\t\t * Enter here : ";
	cin >> option;

	switch (option) {

	case 1:
		system("cls");
		ownerHomePage();
		break;

	case 2:
		system("cls");
		addBook();
		break;

	default:
		system("cls");
		cout << "\n";
		cout << "\t\t              ___Invalid number entered___" << endl
			<< "\t\t          * You will logout from the system *" << endl << endl;
		exit(0);
		break;
	}

}

void viewBooksO() {
	int option;

	cout << "\n";
	cout << "\t\t\t    ~ Available Books in Nethra Book Shop ~" << endl;
	cout << "\t\t\t  *******************************************" << endl << endl;
	cout << "\n";
	cout << "\t\t===================================================================" << endl;
	cout << "\t\t" << left << setw(10) << "NO" << left << setw(26) << "Book Name"
		<< left << setw(20) << "Available Stock" << left << setw(16) << "Book price" << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl << endl;
	int noOfBooks = book.size();

	for (int i = 0; i < noOfBooks; i++)
	{
		books item = book[i];
		cout << "\t\t" << left << setw(10) << item.NO << left << setw(28) << item.BookName
			<< left << setw(20) << item.stockAva << left << setw(18) << item.bPrice << endl;
	}
	cout << "\t\t-------------------------------------------------------------------" << endl << endl;
	cout << "\n  * Enter Number '1' to go to the previous menu ;" << endl << endl
		<< "\n\t\t\t * Enter here : ";
	cin >> option;

	switch (option) {
	case 1:
		system("cls");
		ownerHomePage();
		break;
	default:
		system("cls");
		cout << "\n";
		cout << "\t\t              ___Invalid number entered___" << endl
			<< "\t\t   * Enter correct number to go to the previous menu *" << endl << endl;
		viewBooksO();
		break;
	}

}

void ownerHomePage() {

	cout << endl;
	cout << "\t\t        * Welcome to Nethra Book Shop *\n\n";
	cout << "\n\t\t\t       ***  Options  ***\n\n" << endl;
	cout << "\t 1. View Available Books" << endl
		<< "\t 2. Add New Book" << endl
		<< "\t 3. Search Book" << endl
		<< "\t 4. Log Out" << endl << endl;
	int option;
	cout << "\t             * Select your option : ";
	cin >> option;

	switch (option) {

	case 1:
		system("cls");
		viewBooksO();
		break;

	case 2:
		system("cls");
		addBook();
		break;

	case 3:
		system("cls");
		search();
		break;

	case 4:
		system("cls");
		logOutO();
		break;

	default:
		system("cls");
		cout << "\n \t\t\t\t\t ___Invalid Option Selected___" << endl << endl
			<< "\t\t\t\t\t |Sorry for the inconvnience|" << endl
			<< "\t\t\t\t\t      Please log in again" << endl
			<< "\t\t\t\t\t              ***\n" << endl << endl << endl;
		exit(0);
		break;
	}
}

void ownerLogin() {
	string username;
	string password;
	string ownerUs = "owner";
	string ownerPw = "owner123";

	for (int counter = 3; counter > 0; --counter) {
		cout << "\n" << endl;
		cout << "\t\t\t ~~~ Owner Authentication ~~~" << endl;
		cout << "\t\t\t********************************" << endl << endl;
		cout << " \n \t* Enter your username  : ";
		cin >> username;
		cout << " \n \t* Enter your passwword : ";
		cin >> password;

		if ((username == ownerUs) && (password == ownerPw)) {

			system("cls");
			ownerHomePage();
			break;
		}
		else {
			system("cls");
			cout << "\n \t\t\t  __Wrong username or password__" << endl;
			cout << "\t\t\t**********************************" << endl << endl;
			cout << "\t\t\t       Please try again" << endl;
			cout << "\t\t\t You have another " << "'" << counter - 1 << "'" << "Attempts" << endl << endl;
		}
	}

}

void help() {
	int option;
	cout << "\n";
	cout << "\t\t\t\t  ** Nethra Book Shop Management System User Guide **" << endl;
	cout << "\t\t\t\t*****************************************************" << endl << endl;
	cout << "\n\t1. Owner Login:" << endl <<
		"\t   * Choose the 'Owner' option to log in as the owner of Nethra Book Shop." << endl <<
		"\t   * Owners have access to manage inventory, view sales reports, and oversee the overall operation of the bookshop." << endl <<
		"\t   * Enter the correct owner credentials for full administrative control." << endl << endl;

	cout << "\t2. Cashier Login:" << endl <<
		"\t   * Select the 'Cashier' option to log in as a cashier." << endl <<
		"\t   * Cashiers can process customer purchases, handle payments, and generate receipts." << endl <<
		"\t   * Use the assigned cashier credentials to efficiently manage transactions." << endl << endl;

	cout << "\t3. Help:" << endl <<
		"\t   * Choose the 'Help' option to access this user guide for assistance." << endl <<
		"\t   * This guide provides information on how to use the different features of the Nethra Book Shop Management System." << endl <<
		"\t   * If you have specific questions or encounter issues, consult this guide or contact the bookstore manager." << endl << endl;

	cout << "\t4. Exit:" << endl <<
		"\t   * To exit the system, choose the 'Exit' option." << endl <<
		"\t   * Make sure to save any unsaved data before exiting." << endl << endl << endl;

	cout << "\n\t\t*| We hope this help description provides you with the guidance you need for a seamless experience at Nethra Book Shop |*" << endl << endl;
	cout << endl << "\n  * Enter Number '1' to go to the previous menu ;" << endl << endl
		<< "\n\t\t\t * Enter here --> ";

	cin >> option;

	switch (option) {
	case 1:
		system("cls");
		break;

	default:
		system("cls");
		cout << "\n\t\t\t\t                            ___Invalid number entered___" << endl;
		cout << "\t\t\t\t                   Enter correct number to exit from the system" << endl << endl;
		cout << "\t\t\t\t                *************************************************" << endl << endl << endl;
		help();
		break;
	}

}

int main() {

	books book1;
	book1.NO = 101;
	book1.BookName = "Forgot_Me_Not";
	book1.stockAva = 20;
	book1.bPrice = 1500.00;
	book.push_back(book1);

	books book2;
	book2.NO = 102;
	book2.BookName = "The_Moon_in_the_Water";
	book2.stockAva = 15;
	book2.bPrice = 1350.00;
	book.push_back(book2);

	books book3;
	book3.NO = 103;
	book3.BookName = "Anil's_Ghost";
	book3.stockAva = 25;
	book3.bPrice = 1750.00;
	book.push_back(book3);

	books book4;
	book4.NO = 104;
	book4.BookName = "Running_in_the_Family";
	book4.stockAva = 14;
	book4.bPrice = 1550.00;
	book.push_back(book4);

	books book5;
	book5.NO = 105;
	book5.BookName = "Funny_Boy";
	book5.stockAva = 14;
	book5.bPrice = 1550.00;
	book.push_back(book5);


	int option;
	do {
		cout << "\n\t\t            _____Nethra Book Shop_____" << endl;
		cout << "\t\t   *******************************************" << endl << endl;
		cout << "\t\t     ~~ Books are the mirrors of the soul ~~" << endl << endl << endl << endl;
		cout << "\n * Select Your Login Option *" << endl << endl
			<< "\t 1.Owner" << endl
			<< "\t 2.Cashier" << endl
			<< "\t 3.Help" << endl
			<< "\t 4.Exit" << endl << endl;
		cout << "\t\t *** Select your option *** : ";
		cin >> option;

		switch (option) {

		case 1:
			system("cls");
			ownerLogin();
			break;

		case 2:
			system("cls");
			cashierLogin();
			break;

		case 3:
			system("cls");
			help();
			break;

		case 4:
			system("cls");
			cout << "\n \t\t\t              Your are successfully exit from the system " << endl;
			cout << "\n \t\t\t                     Have a great day! Goodbye!" << endl << endl;
			cout << "\t\t\t         **************************************************" << endl << endl << endl << endl << endl;
			break;

		default:
			system("cls");
			cout << "\n \t\t\t           ***Invalid Option Selected***" << endl;
			cout << "\n \t\t\t                 Have a nice day !" << endl << endl;
			cout << "\t\t\t         *********************************" << endl << endl << endl << endl << endl;
			exit(0);
			break;
		}
	} while (option != 4);


	return 0;
}