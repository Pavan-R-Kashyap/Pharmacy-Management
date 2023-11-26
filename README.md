# Pharmacy Management System
# Overview
This C program implements a simple Pharmacy Management System. The system allows a pharmacist to manage the stock of pharmaceutical items, make updates to the stock, and perform various operations like filling, displaying, altering, and deleting stock items.

# Features

**Fill Stock**: Add new pharmaceutical items to the stock, including their names and quantities.

**Display Stock**: View the current contents of the stock.

**Alter Stock**: Modify the stock by adding new items, selling items to customers, or refilling supplies.

**Delete from Stock**: Remove items from the stock.


 # How to Use

1. Compile the Program:
   **gcc pharmacy_management.c -o pharmacy_management**
  

2. Run the Program:
   **./pharmacy_management**

3. Follow On-Screen Instructions:
   - Enter the desired action (1 to 4) based on the operations mentioned above.
   - For each operation, follow the prompts to input necessary information.

4. View Stock File:
   - The stock details are stored in the **'data1.txt'** file.



# File Descriptions

- **pharmacy_management.c**: The main C program containing the implementation of the Pharmacy Management System.

- **data1.txt**: The text file where stock details are stored. Created on the user’s machine in the same directory as pharmacy_management.c once the user fills the initial stock (option 1). 

# Important Note

- The program maintains a residual stock of 2 items. If the stock falls below this limit, the program prompts the user to refill supplies.
  
- This is a course project demonstration. It hasn’t been uploaded on GitHub till now as juniors could misuse this project and demonstrate it as theirs. It has been made available now, for the admissions process.


 # Authors

1. **Pavan R Kashyap (Primary contributor)** : Wrote the codebase for the array of structures, the main_function, the alter function and the append_accord function (for deletion). 
2. **Pranav Sirnapalli** : Wrote the code for adding new stock
3. **Prajwal V Bhat** : Wrote the code for displaying fresh stock




