# Timetable-Analyzer
This C++ program is designed to manage and display a class timetable. The program reads data from a CSV file containing information about class schedules for different days of the week and then allows the user to view the timetable for a specified day.

# Classroom Timetable Management

This C++ program is designed to manage and display a classroom timetable. It reads schedule data from a CSV file and allows the user to view the timetable for specific days of the week.

## Features
- **Classroom Management**: Stores the names of classrooms and their corresponding lectures for different time slots.
- **Day Schedule Management**: Organizes the timetable by day, allowing for easy retrieval and display of daily schedules.
- **CSV File Input**: Reads timetable data from a CSV file, parsing classroom names and their schedules for the week.
- **User Interaction**: Allows the user to select a day and view the corresponding timetable.

## Class Structure

### `Classroom`
- **Attributes**:
  - `name`: Stores the name of the classroom.
  - `lecture[]`: An array of lectures corresponding to 7 time slots.

- **Methods**:
  - `setClassName(string n)`: Sets the classroom name.
  - `setLecture(int slot, const string& subject)`: Assigns a lecture to a specific time slot.
  - `print()`: Displays the classroom name and the lectures for each time slot.

### `daySchedule`
- **Attributes**:
  - `dayname`: Stores the name of the day.
  - `details[]`: An array of 50 `Classroom` objects.

- **Methods**:
  - `daySchedule()`: Default constructor initializing empty values.
  - `daySchedule(string dn)`: Constructor that sets the day name.

### `TTADT`
- **Attributes**:
  - `root[]`: An array of 6 `daySchedule` objects representing Monday to Saturday.

- **Methods**:
  - `TTADT()`: Initializes the days of the week.
  - `ifstream load(char filename[])`: Loads the CSV file containing the timetable data.
  - `void initializeTT(char filename[])`: Populates the timetable by reading data from the CSV file.
  - `void printTimetable(string forday)`: Prints the timetable for a specified day.

## CSV File Format
The CSV file should be structured such that:
- The first few lines contain header information.
- Classroom schedules for each day are stored in specific line ranges:
  - Monday: Lines 3-52
  - Tuesday: Lines 55-104
  - Wednesday: Lines 107-156
  - Thursday: Lines 159-208
  - Friday: Lines 211-260
  - Saturday: Lines 263-279

Each line in the CSV file represents a classroom's schedule, with the first value being the classroom name, followed by the lectures for each time slot, separated by commas.

## Installation and Setup
1. **Clone the repository**:
    ```bash
    git clone https://github.com/yourusername/classroom-timetable-management.git
    ```
2. **Navigate to the directory**:
    ```bash
    cd classroom-timetable-management
    ```
3. **Compile the code**:
    ```bash
    g++ -o timetable main.cpp
    ```
4. **Run the program**:
    ```bash
    ./timetable
    ```

## Usage
1. Prepare a CSV file containing the timetable data and specify its path in the `filename` variable in the `main()` function. 
2. Run the program. When prompted, enter the day for which you want to view the timetable (e.g., "Monday").
3. The program will display the schedule for that day. You can choose to view another day or exit the program.

## Example
```bash
Enter Day:
Monday
Day= Monday

Classroom: Room 101
Time slots and Lectures:
8:30-9:50: Math
10:00-11:20: Physics
...

Press 1 to display timetable: 0
