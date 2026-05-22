# ICT Lab Report: Traffic Light Management & Learning System

**Authors:** M. Nihaas Bhatti (F2024266196) · Hafiz M. Ibrahim (F2024266162)  
**Submitted to:** Miss Jaweria Amir — ICT Lab, V4

---

## Problem Statement

Traffic management is critical for ensuring road safety. With increasing traffic volumes, it is essential for both drivers and pedestrians to understand traffic signals and their meanings. There is a need for a tool that can educate people about traffic signals, test their knowledge, and help them track their learning progress. This report presents a Traffic Light Management System designed to achieve these objectives.

---

## Objectives

- **Educate Users:** Teach users about the different colors of traffic lights and their meanings.
- **Test Knowledge:** Provide quizzes to assess users' understanding of traffic rules.
- **Track Scores:** Maintain a record of the user's quiz scores to monitor progress.
- **Manage Scores:** Enable users to sort and search their test scores for better accessibility.

---

## Background

Traffic management systems have evolved over the decades, with the first electric traffic signal installed in Cleveland, Ohio, in 1914. Educational tools for traffic rules have often been limited to physical classes or static materials. Digital systems like this program aim to bridge that gap by making learning interactive and accessible.

---

## Gap Analysis

Existing traffic education methods lack interactivity and performance tracking. Many tools focus solely on theoretical knowledge without providing quizzes or feedback mechanisms. This program addresses these gaps by integrating interactive learning, quizzes, and performance analysis in a single tool.

---

## Feasibility Analysis

### Financial Feasibility
The project is cost-effective, requiring only a standard C++ compiler. No specialised hardware or paid software is needed, making it accessible to any student or institution.

### Technical Feasibility
Written in C++, the program runs on any standard computer without additional dependencies. C++ was chosen for its performance, wide availability, and alignment with the course curriculum.

---

## Target Market

- **Students:** School and university students learning about traffic rules.
- **Drivers:** Current and prospective drivers refreshing their knowledge of traffic signals.
- **Schools:** Educational institutions integrating traffic safety into their curriculum.

---

## Methodology

The development process followed three steps:

1. **Design:** Created a menu-driven interface divided into three modules — learning, quiz, and admin — for intuitive navigation.
2. **Implementation:** Programmed in C++ using arrays, functions, input validation, and randomisation.
3. **Testing:** Validated all user inputs and tested each module independently before integration.

---

## Key Features Evaluated

| Feature | Description |
|---|---|
| Learning Module | Users access information about traffic signals and road safety tips |
| Quiz Module | Users take quizzes with immediate right/wrong feedback |
| Admin Panel | Admins add/delete questions and custom instructions at runtime |
| Score History | Session-based history of up to 10 quiz attempts |

---

## Results

The quiz module successfully tested users' knowledge with immediate feedback. The admin panel allowed question management without recompilation. User feedback highlighted the following improvement suggestions:

- Adding more quiz questions
- Incorporating interactive elements (images, multimedia)
- Increasing the history capacity beyond 10 entries

---

## Scope for Future Improvement

- **More Questions:** Expand the quiz to cover a broader range of traffic rules and scenarios.
- **Persistent Storage:** Save scores to a file so history survives across sessions.
- **Graphical Interface:** Migrate from console to a GUI for a more engaging experience.
- **Multilingual Support:** Offer content in multiple languages for wider reach.
- **Real-Time Simulation:** Integrate traffic light simulations for hands-on learning.

---

## References

- C++ Programming Language Documentation — [cppreference.com](https://cppreference.com)
- Traffic Safety and Education Resources
- User Feedback and Testing Reports
