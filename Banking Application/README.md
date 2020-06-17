# CS 100 Programming Project - BankingSystem

## Group Members 

Jonathan Clarke: jclarke084@ucr.edu

Emily Wu: ewu020@ucr.edu

Michelle Dozal: mdoza001@ucr.edu

## Title

The Banking System Application

## Class Diagrams

### Composite Pattern
>Our group will be implementing three design patterns for this application. The first pattern is the composite pattern which will be building a system of trees for the various types of accounts that a user could potentially have on the application. Stemming from the Account root: CashAccounts, which will have a checking and savings subclass. CreditAccount which will have a Visa and Mastercard subclass. Lastly, Loan Account which will be limited to Home and Car loan accounts. All of which stem of the fully virtual class Account.

![Composite Pattern Account](https://user-images.githubusercontent.com/60416759/81995526-7330d280-95ff-11ea-90a1-2e7d3334a0cb.png)

### Decorator Pattern
>The second design pattern will be the Decorator Pattern. This will be used to wrap the accounts that are held by the user. This will have a Decorator Stragey interface. It will show the interest for three different types of accounts. 

<img width="583" alt="Screen Shot 2020-06-08 at 4 53 14 AM" src="https://user-images.githubusercontent.com/62925991/84027637-244b3400-a944-11ea-923e-dba99f9f6ba2.png">

### Visitor Pattern
>Lastly, we will be implementing the visitor pattern that will enable the addition of different types of services to the Account class. In this project, services are the different functions that can be operated on the accounts like offering specials on loans to users in a certain tax bracket. Each concrete visitor class is created for every functionality. Each concrete class is created for every functionality. This pattern allows adding new services for account classes without making any changes to the specific account classes.

<img width="870" alt="Screen Shot 2020-06-09 at 3 23 09 AM" src="https://user-images.githubusercontent.com/62925991/84136744-941ef480-aa00-11ea-8614-43a2099ed247.png">


## What app do you plan to work on?

> The banking system application, has a user based login with records of all transactions and loans made by said user. This information is only viewable by an admin or by the user's specific account. 

## Why is it important/ interesting?

> This project utilizes many real world applications just in our initial brain storming of it. It's something that can be used later and easy to visualize how the design patterns are implemented.

## What language/tools do we plan to use?

> We plan to use C++, and three design patterns:composite, visitor, and decorator.

## What will be the input/ouput?

> The input will be user's choice, and the output will be based on the options they want to view or actions they want to make. Below are some examples of input/ouput choices.

<img width="209" alt="Screen Shot 2020-06-09 at 9 36 19 AM" src="https://user-images.githubusercontent.com/62925991/84179628-1b895980-aa3b-11ea-98a1-036fa152599b.png">
<img width="280" alt="Screen Shot 2020-06-09 at 9 36 36 AM" src="https://user-images.githubusercontent.com/62925991/84179644-204e0d80-aa3b-11ea-8ad1-6bc61db103db.png">
<img width="169" alt="Screen Shot 2020-06-09 at 9 37 16 AM" src="https://user-images.githubusercontent.com/62925991/84179655-2217d100-aa3b-11ea-976d-613125983292.png">
