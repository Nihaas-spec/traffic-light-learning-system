// =============================================================================
// Traffic Light Learning & Assessment System
// Course  : Programming Fundamentals (CS-101)
// Semester: 1st Semester
// Authors : M. Nihaas Bhatti (F2024266196)
//           Hafiz M. Ibrahim  (F2024266162)
// =============================================================================
//
// Description:
//   A console-based educational tool that teaches users about traffic signals
//   and road safety rules, then tests their knowledge through an interactive
//   quiz. An admin panel allows dynamic question management at runtime.
//
// Features:
//   - Learn module  : traffic signal phases and road safety tips
//   - Admin panel   : add, delete, and view quiz questions at runtime
//   - Quiz engine   : randomised question order, configurable question count
//   - History       : tracks up to 10 quiz attempts per session
//   - Input guard   : all user inputs validated with clear error messages
//
// Compilation:
//   g++ -std=c++11 -o traffic_quiz src/main.cpp
// =============================================================================

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------
const int MAX_QUESTIONS = 100;
const int MAX_OPTIONS   = 3;
const int MAX_HISTORY   = 10;

// ---------------------------------------------------------------------------
// Global state
// ---------------------------------------------------------------------------
string questions[MAX_QUESTIONS];
string options[MAX_QUESTIONS][MAX_OPTIONS];
int    correctOptions[MAX_QUESTIONS];
int    questionCount = 0;

int quizScores[MAX_HISTORY];
int numQuestionsAttempted[MAX_HISTORY];
int historyCount = 0;

string extraInstructions = "No extra instructions available.";

// ---------------------------------------------------------------------------
// Utility: read a validated integer in [lo, hi] from stdin
// ---------------------------------------------------------------------------
int readInt(int lo, int hi)
{
    int value;
    while (true)
    {
        cin >> value;
        if (!cin.fail() && value >= lo && value <= hi)
            return value;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between "
             << lo << " and " << hi << ": ";
    }
}

// ===========================================================================
// Admin Panel
// ===========================================================================

void addQuestion()
{
    if (questionCount >= MAX_QUESTIONS)
    {
        cout << "Maximum question limit reached. Cannot add more questions.\n";
        return;
    }

    cin.ignore();
    cout << "Enter the question text: ";
    getline(cin, questions[questionCount]);

    for (int i = 0; i < MAX_OPTIONS; i++)
    {
        cout << "Enter option " << i + 1 << ": ";
        getline(cin, options[questionCount][i]);
    }

    cout << "Enter the correct option number (1-3): ";
    correctOptions[questionCount] = readInt(1, 3);

    questionCount++;
    cout << "Question added successfully!\n";
}

void deleteQuestion()
{
    if (questionCount == 0)
    {
        cout << "No questions available to delete.\n";
        return;
    }

    cout << "Enter the question number to delete (1-" << questionCount << "): ";
    int index = readInt(1, questionCount);

    // Shift remaining questions left
    for (int i = index - 1; i < questionCount - 1; i++)
    {
        questions[i] = questions[i + 1];
        for (int j = 0; j < MAX_OPTIONS; j++)
            options[i][j] = options[i + 1][j];
        correctOptions[i] = correctOptions[i + 1];
    }

    questionCount--;
    cout << "Question deleted successfully!\n";
}

void viewQuestions()
{
    if (questionCount == 0)
    {
        cout << "No questions available.\n";
        return;
    }

    for (int i = 0; i < questionCount; i++)
    {
        cout << "\nQuestion " << i + 1 << ": " << questions[i] << "\n";
        for (int j = 0; j < MAX_OPTIONS; j++)
            cout << "  " << j + 1 << ". " << options[i][j] << "\n";
        cout << "Correct Option: " << correctOptions[i] << "\n";
    }
}

void addInstructions()
{
    cin.ignore();
    cout << "Enter the new instruction text: ";
    string newInstruction;
    getline(cin, newInstruction);

    if (extraInstructions == "No extra instructions available.")
        extraInstructions = newInstruction;
    else
        extraInstructions += "\n" + newInstruction;

    cout << "Instruction added successfully!\n";
}

void adminPanel()
{
    while (true)
    {
        cout << "\n--- Admin Panel ---\n"
             << "1. Add Question\n"
             << "2. Delete Question\n"
             << "3. View Questions\n"
             << "4. Add Instructions\n"
             << "5. Exit to Main Menu\n"
             << "Enter your choice: ";

        switch (readInt(1, 5))
        {
            case 1: addQuestion();    break;
            case 2: deleteQuestion(); break;
            case 3: viewQuestions();  break;
            case 4: addInstructions();break;
            case 5: return;
        }
    }
}

// ===========================================================================
// Quiz Engine
// ===========================================================================

// Fisher-Yates partial shuffle for the first numQuestions entries
void shuffleQuestions(int numQuestions)
{
    for (int i = 0; i < numQuestions; i++)
    {
        int randIndex = i + rand() % (questionCount - i);

        swap(questions[i],    questions[randIndex]);
        swap(correctOptions[i], correctOptions[randIndex]);
        for (int j = 0; j < MAX_OPTIONS; j++)
            swap(options[i][j], options[randIndex][j]);
    }
}

void takeQuiz()
{
    if (questionCount == 0)
    {
        cout << "No questions available. Please ask an admin to add questions first.\n";
        return;
    }

    cout << "Enter the number of questions you want to attempt (1-"
         << questionCount << "): ";
    int numQuestions = readInt(1, questionCount);

    shuffleQuestions(numQuestions);

    int score = 0;
    for (int i = 0; i < numQuestions; i++)
    {
        cout << "\nQuestion " << i + 1 << ": " << questions[i] << "\n";
        for (int j = 0; j < MAX_OPTIONS; j++)
            cout << "  " << j + 1 << ". " << options[i][j] << "\n";

        cout << "Enter your answer (1-3): ";
        int answer = readInt(1, 3);

        if (answer == correctOptions[i])
        {
            cout << "Correct!\n";
            score++;
        }
        else
        {
            cout << "Incorrect. The correct answer was option "
                 << correctOptions[i] << ".\n";
        }
    }

    // Save to history
    if (historyCount < MAX_HISTORY)
    {
        quizScores[historyCount]          = score;
        numQuestionsAttempted[historyCount] = numQuestions;
        historyCount++;
    }

    cout << "\nYour final score: " << score << "/" << numQuestions << "\n";
}

void viewQuizHistory()
{
    if (historyCount == 0)
    {
        cout << "No quiz history available.\n";
        return;
    }

    cout << "\n--- Quiz History ---\n";
    for (int i = 0; i < historyCount; i++)
    {
        cout << "Quiz " << i + 1
             << " | Score: " << quizScores[i]
             << "/" << numQuestionsAttempted[i] << "\n";
    }
}

void userPanel()
{
    while (true)
    {
        cout << "\n--- User Panel ---\n"
             << "1. Take Quiz\n"
             << "2. View Quiz History\n"
             << "3. Exit to Main Menu\n"
             << "Enter your choice: ";

        switch (readInt(1, 3))
        {
            case 1: takeQuiz();        break;
            case 2: viewQuizHistory(); break;
            case 3: return;
        }
    }
}

// ===========================================================================
// Learn Module
// ===========================================================================

void learnTrafficSignals()
{
    cout << "\n--- Learn About Traffic Signals ---\n"
         << "\nTraffic Light Phases:\n"
         << "  1. Red    : Stop\n"
         << "  2. Yellow : Prepare to stop\n"
         << "  3. Green  : Go\n"
         << "\n--- Road Safety Tips ---\n"
         << "  - Traffic signals help regulate vehicle and pedestrian movement.\n"
         << "  - Always follow traffic signals to ensure safety.\n"
         << "  - Pedestrian signals often accompany traffic lights to guide walkers.\n"
         << "  - Flashing yellow lights indicate caution; proceed carefully.\n"
         << "  - A flashing red light is treated like a stop sign.\n"
         << "  - Use zebra crossings to ensure safe pedestrian crossings.\n"
         << "  - Vehicles must stop before the zebra crossing when the light is red.\n"
         << "  - Make way for emergency vehicles by moving to the side of the road.\n"
         << "  - Always use indicators when turning to inform other drivers.\n"
         << "  - Avoid blocking intersections; keep a safe distance from other vehicles.\n"
         << "\n--- Additional Instructions ---\n"
         << extraInstructions << "\n";
}

// ===========================================================================
// Entry Point
// ===========================================================================

int main()
{
    srand(static_cast<unsigned int>(time(0)));   // seed once at startup

    while (true)
    {
        cout << "\n=== Traffic Light Learning & Assessment System ===\n"
             << "1. Admin Panel\n"
             << "2. User Panel\n"
             << "3. Learn About Traffic Signals\n"
             << "4. Exit\n"
             << "Enter your choice: ";

        switch (readInt(1, 4))
        {
            case 1: adminPanel();          break;
            case 2: userPanel();           break;
            case 3: learnTrafficSignals(); break;
            case 4:
                cout << "Thank you for using the Traffic Light Learning System. Goodbye!\n";
                return 0;
        }
    }
}
