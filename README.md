
# 📒 Address Book in C

## 📝 Overview

This is a command-line based **Address Book** application written in C. It allows users to **create, search, edit, delete, list, and save contacts** with validations. Each contact includes a **name, phone number, and email address**. Contacts are saved to a text file (`contacts.txt`) to ensure data persistence between runs.

---

## 🚀 Features

- ✅ Add new contacts with validation
- 🔍 Search by name, phone, or email
- 📝 Edit existing contact details
- 🗑️ Delete unwanted contacts
- 📃 List all contacts in a structured format
- 🔤 Quick search by starting character of names
- 💾 Save contacts to a file for future use

---

## 🛠️ Project Structure

```
├── main.c           # Entry point: handles menu and user interaction
├── contact.c        # Core logic for contact management
├── contact.h        # Contact structures and function declarations
├── file.c           # File read/write functionality
├── file.h           # File operation declarations
├── contacts.txt     # Data file storing contact records
```

---

## ⚙️ How to Compile and Run

### 🔧 Compile
Use `gcc` or any C compiler:
```bash
gcc main.c contact.c file.c -o address_book
```

### ▶️ Run
```bash
./address_book
```

---

## 📂 File Format

Contacts are stored in `contacts.txt` using this format:

```
<number_of_contacts>
name1,phone1,email1
name2,phone2,email2
...
```

---

## 🧪 Validations

- **Name**: Must not contain symbols or numbers.
- **Phone**: Must be exactly 10 digits.
- **Email**: Must be lowercase and follow basic structure (e.g., `user@domain.com`).

---

## 👨‍💻 Author

- **Name**: Vinodh Kumar J
- **Date**: 28/05/2025
- **Project**: Address Book in C

---

## 🗃️ Example Usage

```text
ADDRESSBOOK_MENU
1. Create Contact
2. Search Contact
3. Quick Search
4. Edit Contact
5. Delete contact
6. List Contact
7. Save and Exit
```
