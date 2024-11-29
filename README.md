# Book-Shop-Automation-System

Overview
The Nethra Book Shop Management System is a C++ console-based application designed to streamline operations within a bookshop. It provides features for both owners and cashiers to manage the shop effectively, including inventory management, billing, and customer service. The application serves as a robust and user-friendly solution for daily operations in a bookshop.

Features
Owner Features:
View Available Books:

Displays a comprehensive list of books available in the inventory, including:
Book Number
Book Name
Available Stock
Price per Unit
Add New Book:

Allows the owner to add new books to the inventory.
Automatically generates a unique book ID for each new book.
Search Book:

Provides a search functionality to find books by their name.
Logout:

Securely logs the owner out of the system.
Cashier Features:
Billing System:

Handles customer transactions efficiently.
Adds selected books to a shopping cart.
Automatically calculates total cost and applies a 30% discount on purchases exceeding Rs. 4500.
View Available Books:

Displays the inventory for reference during billing.
Print Bill:

Generates a detailed bill including:
Customer details (Order Number, Name, Telephone Number)
Purchased items with quantity and price
Subtotal, discounts, and total amount.
Logout:

Allows the cashier to log out securely.
System Modules
Authentication
Owner Authentication:
Username: owner
Password: owner123
Cashier Authentication:
Username: cashier
Password: cashier123
Inventory Management
Preloaded Inventory:
Five books are preloaded into the system for demonstration.
Dynamic Inventory:
New books can be added by the owner.
Cart Management
Allows cashiers to add books to the cart and adjust quantities based on customer requirements.
Billing
Generates detailed bills with support for discounts and accurate pricing.
User Guide
Main Menu:
Owner:
Access administrative tools such as inventory management and book searches.
Cashier:
Process customer orders and print bills.
Help:
View a detailed guide for using the system.
Exit:
Close the application.
Navigation:
All menus are interactive, prompting users for input and guiding them through operations step-by-step.
Technical Details
Language: C++
Development Environment: Any C++ IDE or terminal with a C++ compiler.
Libraries Used:
<iostream>: For input and output operations.
<string>: To handle string data.
<vector>: To manage dynamic lists of books and cart items.
<iomanip>: To format bill output neatly.
