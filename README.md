![Screenshot 2024-05-12 220329](https://github.com/olahamdy99/C_Project/assets/152440610/964ff3cf-bd63-4216-bb45-4e21b1cec968)
![Screenshot 2024-05-12 222257](https://github.com/olahamdy99/C_Project/assets/152440610/d6e83f2b-045b-433d-9b23-aac2e8d66a39)
![Screenshot 2024-05-12 222353](https://github.com/olahamdy99/C_Project/assets/152440610/a95d84f2-abde-4321-8a46-55030af46b21)
![Screenshot 2024-05-12 222438](https://github.com/olahamdy99/C_Project/assets/152440610/06bbc42e-1277-4a85-9a1c-0aab211b8c32)
![Screenshot 2024-05-12 222511](https://github.com/olahamdy99/C_Project/assets/152440610/43fe372b-5be6-4346-aed4-1c012ee9a56a)


# Store Inventory & Ordering System

A console-based **store inventory and ordering system** developed in **C**.

The project manages product categories, products, inventory quantities, product transfers between categories, and customer orders through an interactive Windows console interface.

---

## Features

### Category Management

- Add product categories
- Assign a unique ID to each category
- View all categories and their products

### Product Management

- Add products with:
  - Product ID
  - Product name
  - Price
  - Quantity
  - Category
- Validate product price and quantity input
- Associate each product with a category
- Move products between categories

### Inventory Management

- Track available product quantities
- Validate requested order quantities against available stock
- Automatically reduce product quantity after a successful order

### Ordering & Billing

- Select a product by ID
- Enter the required quantity
- Prevent orders that exceed available stock
- Generate a simple bill containing:
  - Product name
  - Quantity
  - Total price

### Console Interface

- Interactive keyboard-controlled menu
- Arrow-key navigation
- Colored console output
- Screen positioning using the Windows Console API

---

## Programming Concepts Used

- C Programming
- Structures (`struct`)
- Pointers
- Dynamic Memory Allocation
- `malloc`
- `realloc`
- Arrays
- Functions
- Loops and Conditional Statements
- Input Validation
- Windows Console API

---

## Data Model

The application uses two main structures.

### Category

```c
struct category
{
    int id;
    char name[30];
};
