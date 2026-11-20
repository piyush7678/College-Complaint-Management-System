# College Complaint Management System

A menu-driven C program to register, view, search and track college complaints. Built as a mini-project for Software Development Fundamentals Lab-1 at Jaypee Institute of Information Technology, Noida.

## Features

1. **Register Complaint** - store Complaint ID, Student ID, name, category and description
2. **View Complaints** - display all stored complaints
3. **Search Complaint** - find a complaint by its Complaint ID
4. **Update Status** - change status to Pending, In Progress or Resolved
5. **Summary** - total complaints and count for each status
6. **File Handling** - records are saved in `complaints.dat`, so data stays after the program closes

## Concepts Used

Arrays, strings, structures, pointers, functions, control statements (`if-else`, loops, `switch`) and file handling.

## Run

```
gcc complaint_system.c -o complaint_system
./complaint_system
```

On Windows, run `complaint_system` instead of `./complaint_system`.

## Sample Flow

```
===== COLLEGE COMPLAINT MANAGEMENT SYSTEM =====
1. Register Complaint
2. View Complaints
3. Search Complaint
4. Update Complaint Status
5. Complaint Summary
6. Exit
```

Register a complaint, update its status from Pending to In Progress, then check the summary:

```
------ COMPLAINT SUMMARY ------
Total Complaints: 1
Pending: 0
In Progress: 1
Resolved: 0
```

## Limits

- Stores up to 100 complaints
- Duplicate Complaint IDs are not allowed

## Team

- Piyush
- Anant Saraswat
- Deep Yadav
- Shivansh Sharma

Supervisor: Mr. Dhruv Garg
