# ClockProject

Summary:

The scope of this project is to create and display two clocks, one displaying standard time (12 Hr.) and one displaying military time (24 hr.). It has the capability to allow the user to adjust the seconds, minutes, and hours of the displayed clocks. Upon making this adjustment, the displayed clocks will re-render with the updated time.

What did you do particually well:

Looking back at this project I can say that it was structured really well, readable, and had good overall organization. I built and used methods for every specific task, and added descriptive comments and summaries where ever necessary.

Where could you enchance your code:

One possible enhancement that stands out to me immediately, is that the program is missing exception handling. If a user accidentally enters in a character, it will send the console into an infinite loop. I did write validation for the menu ensuring the entered number is valid, but could have added this character validation as well.

Another enchancement would be abtracting the Clock class specific functions into their own class file. In this project, I placed the Clock class specific functions within Main.cpp. Although this is a more simple way of writing the program, it has an effect on readability and scalability

Which pieces of the code did you find most challenging to write, and how did you overcome this:

I would say the most difficult part of this project was writing the FormatTime function. This contained all of the formulas for calculating the change of time for second, minute, and hour updates. It took a bit of time to get working properly. In order to get the formulas right, I utilized the internet, specifically StackOverflow, for assistance.

What skills from this project will be particularly transferable to other projects or course work:

This project was a major C++ refresher for me. C++ was the first language I've ever programmed in, but that was several years ago. It was great to refresh my memory on C++ syntax, patterns, and general idiosyncrasies of the language.

How did you make this program maintainable, readable, and adaptable: 

The code has comments for any line or method that may be difficult to understand at first glance. I also added summaries for every method. This allows the developer to view a brief description of the method which provides a bit more information on how the function works than by just reading the title. I tried to create a function for every task, making it a bit more readable and definitely adaptable.





