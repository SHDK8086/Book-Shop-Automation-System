# Book-Shop-Automation-System

Overview

The Nethra Book Shop Management System is a C++ console-based application designed to streamline operations within a bookshop. It provides features for owners and cashiers to manage the shop effectively, including inventory management, billing, and customer service. The application is a robust and user-friendly solution for daily operations in a bookshop.

Features

Owner Features:
1. View Available Books:

Displays a comprehensive list of books available in the inventory, including:
* Book Number
* Book Name
* Available Stock
* Price per Unit

2. Add New Book:

* Allows the owner to add new books to the inventory.
* Automatically generates a unique book ID for each new book.
  
3. Search Book:

* Provides a search functionality to find books by their name.

4. Logout:

* Securely logs the owner out of the system.

Cashier Features:

1. Billing System:

* Handles customer transactions efficiently.
* Adds selected books to a shopping cart.
* Automatically calculates total cost and applies a 30% discount on purchases exceeding Rs. 4500.

2. View Available Books:

* Displays the inventory for reference during billing.
  
3. Print Bill:

* Generates a detailed bill including:
* Customer details (Order Number, Name, Telephone Number)
* Purchased items with quantity and price
* Subtotal, discounts, and total amount.

4. Logout:

* Allows the cashier to log out securely.
  
System Modules0

Authentication

1. Owner Authentication:
* Username: owner
* Password: owner123
  
2. Cashier Authentication:
* Username: cashier
* Password: cashier123
  
Inventory Management

1. Preloaded Inventory:

* Five books are preloaded into the system for demonstration.

2. Dynamic Inventory:

* The owner can add new books.
  
Cart Management

* Allows cashiers to add books to the cart and adjust quantities based on customer requirements.
  
Billing
* Generates detailed bills with support for discounts and accurate pricing.
  
User Guide

Main Menu:
1. Owner:

* Access administrative tools such as inventory management and book searches.

2. Cashier:

* Process customer orders and print bills.

3. Help:

* View a detailed guide for using the system.
  
4. Exit:

* Close the application.

Navigation:

* All menus are interactive, prompting users for input and guiding them through operations step-by-step.

Technical Details
* Language: C++
* Development Environment: Any C++ IDE or terminal with a C++ compiler.
* Libraries Used:
 ** <iostream>: For input and output operations.
 ** <string>: To handle string data.
 ** <vector>: To manage dynamic lists of books and cart items.
 ** <iomanip>: To format bill output neatly.
