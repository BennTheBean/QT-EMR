
# EMR System

## Project Overview

The EMR (Electronic Medical Records) System is a C++ application developed using **Qt Creator** and **SQLite**. 
It allows users to manage and maintain patient medical records efficiently. This project is designed to be modular and extendable, making it easy to add new features or integrate with existing healthcare systems.

---

## Features

- **Patient Management**: Add, update, and view patient profiles.
- **Appointment Scheduling**: Schedule, view, and edit appointments.
- **Medical File Handling**: Create, access, and edit medical files associated with each patient.
- **User Management**: Create users with varrying permissions to access the software.
- **Modular Architecture**: Easily extendable to include new file types or templates.
- **SQLite Integration**: Lightweight and reliable database management for storing records.
- **User-Friendly Interface**: Intuitive UI designed with Qt Creator.

---

## Requirements

- **Qt Creator IDE** (version 6.5 or newer recommended)
- **SQLite3** library
- **C++ Compiler** supporting C++17 or newer

---

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/BennTheBean/QT-EMR.git
   cd QT-EMR
   ```

2. Open the project in **Qt Creator**:
   - Launch Qt Creator.
   - Click on **Open Project** and select the `EMR.pro` file.

3. Configure the build environment:
   - Ensure the correct compiler and Qt version are selected.
   - Install SQLite development libraries if not already installed.

4. Build the project:
   - Click **Build** → **Build All**.

5. Run the application:
   - Click **Run** or press `Ctrl+R`.

---

## Usage

1. **Log in**:
   - Default admin account login: Username: Admin, Password: 1234567890
   - Can enter settings to add more Users
1. **Adding a Patient**:
   - Navigate to the "Patients" section.
   - Click **Add Patient** and fill in the required fields.
2. **Managing Medical Files**:
   - Select a patient to view their medical records.
   - Click **Add File** to create a new medical file or **Edit** to modify an existing one.
3. **Search**:
   - Use the search bar to find a patient from their OHIP.
---
