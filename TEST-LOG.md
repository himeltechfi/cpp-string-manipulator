# Test Log

This document records the testing activities performed during the development of the C++ String Manipulator.

## Test Procedures

- **Test Date:** 2019-03-15
  - **Functionality:** `GetWord` function.
  - **Description:** Initially, the function only accepted numbers. After debugging, the issue was resolved, and it now accepts words.

- **Test Date:** 2019-03-15
  - **Functionality:** Main loop and menu.
  - **Description:** Faced issues with the program's main loop and menu flow. The program was terminating prematurely. Re-structured the loop to ensure continuous operation until the user quits.

- **Test Date:** 2019-03-23
  - **Functionality:** Case conversion (`ToUpper`, `ToLower`).
  - **Description:** Both functions were initially only converting the first or last letter of the string. After debugging the loop and array indexing, the functions now correctly convert the entire string.

- **Test Date:** 2019-03-25
  - **Functionality:** Randomization (`RandomiseWord`).
  - **Description:** The function was not working as expected. After checking the function call and parameters, the issue was identified and fixed, and the randomization is now working correctly.

- **Test Date:** 2019-03-31
  - **Functionality:** Menu and switch statement logic.
  - **Description:** The `menuOption` variable was changed from `int` to `char` to handle incorrect user input gracefully. The `switch` statement was updated to use ASCII values, which now correctly displays an error message for invalid input.
