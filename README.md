# Take Away Restaurant System

## Overview

This project is a simple take away restaurant system implemented in C++. The system utilizes a hashed table data structure for storing menus efficiently. It allows users to view menus, place orders, and calculate the total bill.

## Features

1. Menu imported from CSV files.
2. Place Orders and calculate bill.
3. Search Function and custom-designed Hash Table.

## Compilation Instructions

1. Run the makefile using 'make' command.
2. Execute the compiled program by running './Restaurant'.

## Usage Instructions

1. Enter menu file(s) in CSV format. Ensure that the files are in the same folder as the program code and they are correctly formatted with item names, ingredients, and prices (Please do not integrate commas within the columns as they will clash with the CSV formatting). 
2. Main Menu is displayed.
    2.1. Choose Option 1 - Take Order.
        2.1.1. Choose option 1 - Display Menu to view all currently loaded menu items.
        2.1.2. Choose option 2 - Search Menu to find an item by its name or an ingredient.
        2.1.3. Choose option 3 - Take Order: Add items to order, Remove items from order, View order, View loaded menu(s), Calculate bill, and Exit.
        2.1.4. Choose option 4 - Exit.
    2.2. Choose Option 2 - Modify Menu.
        2.2.1. Choose Add Item to add a new item to a specified menu.
        2.2.2. Choose Remove Item to remove an item from a specified menu.
        2.2.3. Choose Display or Search to help in modification decision.
    2.3. Choose Option 3 - Exit the system.

## Authors

- Bhavna Chummun [Team Leader]
- Shreya Dosieah [Secretary]
- Harshvardhan V Doyal [Developer]
- Sneha L Gunput [Developer]
- Nathan A Kagoro [Tester]