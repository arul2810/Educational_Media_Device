# ELEC5620M - Mini Project - Arul Prakash Samathuvamani

# Education Media Device

Description of Repository:

Education media device has been designed to function on ARM Cortex A9 Processor

This module is designed for ELEC5620M Mini Project

## Major Files in Repository:
| File | Purpose |
| ---  | --- |
| MiniProject/main.c         | Main Program File |


#### Dependencies:

| File | Purpose |
| ---  | --- |
| MiniProject/PrivateTimer.c  | A9 Private Timer BareMetal Driver |
| MiniProject/Sevenseg.c      | Seven Segment Bare Metal Driver |
| MiniProject/Images          | Contains the .c image files for images used in module |
| MiniProject/DE1SoC_LT24     | LT24 Driver |
| MiniProject/DE1SoC_WM8731   | WM8731 Audio CODEC |
| MiniProject/HPS_I2C         | HPS I2C Driver |
| MiniProject/HPS_IRQ         | HPS IRQ Driver |
| MiniProject/FattFs          | FATFs File System module |
| MiniProject/HPS_Watchdog    | HPS Watchdog driver |


Project is tested to work using DE1-SoC Board.

The media device has following specifications.

The device has two modes.

1.	Count Mode – Counts from one to ten. Starts from one, and after one number has completed, the user would have to press Button 1 to move to the next number. The mode uses audio and visual aid for better understanding. 
2.	Test Mode – Checks the learning of the child. On displaying a number, the child would have to press the push Button 1 for displayed number of times. For example, if number two is displayed, the child would have to press the button for 2 times before the system moves to the next number.
3.	During start up, the user would have to select which mode to run. The user can select the mode using Button 2 and Button 3. Button 2 corresponds to Count Mode, and Button 3 corresponds to Test Mode.
4.	When any mode is running, pressing Button 4 would reset the board and call mode selector and the user would be able to change the mode.
5.	When in Test Mode, without any input from user for 10 seconds, resets the board, and calls mode selector.
6.	Animation on LT24 display during mode selector.
