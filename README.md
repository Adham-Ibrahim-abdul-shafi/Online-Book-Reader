# Online Book Reader Project

This is a C++ console-based **Online Book Reader System** that simulates a basic digital library with user and admin roles. Users can read books and track their reading sessions, while admins can manage the library by adding new books.

## Table of Contents

- [Functional Requirements](#functional-requirements)
- [Non-Functional Requirements](#non-functional-requirements)
- [Features](#features)
  - [Admin Features](#admin-features)
  - [User Features](#user-features)
- [Core Files](#core-files)


## Functional Requirements

The system has two types of users:
- **Admin User**: Can add books to the system.
- **Customer/User**: Can browse and read books, and track reading sessions.

### Admin Actions:
- Admins can add books to the system.

### User Actions:
- Users can read one book at a time, but maintain a history of their reading sessions.
- Users can navigate through book pages or end the session.

### System Restrictions:
- For simplicity, users cannot have multiple sessions at the same time.

## Non-Functional Requirements

- **Usability**: The system is user-friendly and compatible with other systems.
- **Security**, **Reliability**, **Performance**, **Maintainability**, and **Scalability** are considered for future development.

## Features

### Admin Features
- **Add Books**: Admins can add books to the system's catalog, providing book title, author, and content.
- **Multiple Admins**: The system can support multiple admins.

### User Features
- **Login/Sign-up**: Users can sign up or log in to access the system.
- **Reading Sessions**: Users can open books and navigate through pages. If they stop reading, their position in the book is saved.
- **Reading History**: Users can view their previous reading sessions and pick up where they left off.

### Core Files:
- Book.h / Book.cpp: Handles book-related operations.
- BookReadingSession.h / BookReadingSession.cpp: Tracks the user's reading sessions.
-User.h / User.cpp: Manages user information and actions.
- UsersManager.h / UsersManager.cpp: Handles login, signup, and user management.
- BooksManager.h / BooksManager.cpp: Manages the collection of books in the system.
- UserView.h / UserView.cpp: Provides the interface for user interactions.
- AdminView.h / AdminView.cpp: Provides the interface for admin interactions.
- Utilities.h / Utilities.cpp: General utility functions like menus and input handling.
- main.cpp: The main entry point of the application.


Are you an Admin or a User?
1) Admin
2) User
3) Exit
