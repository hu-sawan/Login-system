# Login-System
This repository contains a simple command-line Login System application that allows users to either log in, sign up, or reset their password. The application reads and writes user information to a file named "users.txt" and uses a simple hashing algorithm to encrypt user passwords.

## Requirements
To run this application, you need to have:

- C++ compiler installed
- A text editor or IDE
- A command prompt or terminal

## Installation
1. Clone the repository using `git clone https://github.com/hu-sawan/Login-System.git`
2. Navigate to the project directory using the command prompt or terminal.
3. Compile the application using your C++ compiler by running the command `g++ -o Login-System main.cpp gate.cpp`
4. Run the compiled application using the command `./Login-System.`

## Usage
Upon launching the application, the user is presented with four options to choose from:

1. Login: Allows existing users to log in to their accounts.
2. Signup: Allows new users to create an account.
3. Reset password: Allows users to reset their password if they forget it.
4. Exit: Exits the application.

If the user chooses the login or signup option, the application will ask them to enter a username and a password. The password will be hashed and stored in the "users.txt" file.

If the user chooses the reset password option, the application will ask them to enter the username associated with their account. If the username exists in the "users.txt" file, the user will be prompted to enter a new password. The new password will be hashed and stored in the "users.txt" file.

If the user enters an invalid option or the wrong username and password, the application will prompt them to try again.

After successfully logging in or creating an account, the user will be taken back to the main menu where they can choose another option or exit the application.

## Contributing
Contributions to this project are always welcome. Here are some ways you can contribute:

- Submit a bug report or feature request.
- Help improve the code by fixing a bug or implementing a new feature.
- Improve the documentation by fixing a typo or adding more information.

If you are interested in contributing to this project, please fork the repository and create a pull request with your changes.
