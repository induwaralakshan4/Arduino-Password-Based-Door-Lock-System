
🔐 Arduino Password-Based Door Lock System

https://github.com/user-attachments/assets/c213216d-d87d-400d-bcd8-fe812c0986b1

An Arduino-based security project that simulates a password-protected door locking system using a keypad, LCD display, servo motor, buzzer, and LED indicators.

🚀 Features

- Password Verification: Enter and verify a predefined password using a 4×3 matrix keypad.
- LCD Interface: Display password input and access status using an I2C LCD.
- Servo Motor Control: Simulate door locking and unlocking.
- Buzzer Alerts: Provide audio feedback for key presses and incorrect passwords.
- LED Indicators: Indicate access status.
- Password Reset: Reset the entered password after each verification attempt.

🛠️ Hardware Components

- Arduino-compatible board
- 4×3 Matrix Keypad
- I2C LCD Display
- Servo Motor
- Buzzer
- LED indicators
- Jumper wires

💻 Technologies Used

- Arduino (C/C++)
- Arduino IDE
- Servo Library
- Keypad Library
- Wire Library
- LiquidCrystal_AIP31068_I2C Library

⚙️ How It Works

1. The LCD displays a welcome message and prompts the user to enter a password.
2. The user enters the password using the keypad.
3. Pressing "=" verifies the entered password.
4. If the password is correct ("456"), the servo motor moves to simulate unlocking the door.
5. If the password is incorrect, the system displays an error message and activates the buzzer and LED indicators.
6. Pressing "*" clears the entered password.

🎯 Project Goals

This project demonstrates practical applications of Arduino programming, embedded systems, hardware interfacing, and basic access-control logic.

⚠️ Note

This is an educational prototype designed to demonstrate password-based access control. Additional security measures and hardware testing are required before using it in a real-world door-locking application.