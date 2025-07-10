
#include <iostream>
#include <map>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
    string name;
    map<string, string> answers;
};

struct CareerNode {
    string career;
    vector<string> skills;
};

void setConsoleColor(int textColor, int bgColor = 0) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void animatedText(const string& text, int delay = 40) {
    for (char c : text) {
        cout << c << flush;
        Sleep(delay);
    }
    cout << endl;
}

void drawBox(const string& title) {
    setConsoleColor(11);
    cout << "\n\t+--------------------------------------+" << endl;
    cout << "\t|         " << setw(26) << left << title << "         |" << endl;
    cout << "\t+--------------------------------------+\n";
    setConsoleColor(7);
}

void printQuestionBox(const string &q, string &ans) {
    setConsoleColor(10);
    cout << "\n\t> " << q << " (yes/no): ";
    setConsoleColor(7);
    getline(cin, ans);
}

void showWelcomeScreen() {
    system("cls");
    setConsoleColor(14);
    cout << "\n\n\t**************************************" << endl;
    cout << "\t*   AI-Powered Career Recommendation *" << endl;
    cout << "\t**************************************\n" << endl;
    setConsoleColor(11);
    animatedText("\tAnalyzing your potential...", 40);
    animatedText("\tBuilding your career graph...", 40);
    animatedText("\tLet's begin your journey!\n", 50);
    setConsoleColor(7);
    Sleep(800);
    system("cls");
}

void askQuestions(Student &student) {
    drawBox("Career Questionnaire");
    cout << "\tEnter your name: ";
    getline(cin, student.name);

    cout << "\n\tPlease answer the following questions.\n";

    printQuestionBox("1. Do you enjoy coding?", student.answers["coding"]);
    printQuestionBox("2. Are you good at math?", student.answers["math"]);
    printQuestionBox("3. Do you enjoy designing?", student.answers["design"]);
    printQuestionBox("4. Do you like solving problems?", student.answers["problem_solving"]);
    printQuestionBox("5. Do you prefer working with people?", student.answers["people"]);
}

string recommendCareer(Student &student) {
    string coding = student.answers["coding"];
    string math = student.answers["math"];
    string design = student.answers["design"];
    string problem_solving = student.answers["problem_solving"];
    string people = student.answers["people"];

    if (coding == "yes" && math == "yes" && problem_solving == "yes") {
        return "Software Engineer";
    } else if (design == "yes" && coding == "no") {
        return "Graphic Designer";
    } else if (people == "yes" && coding == "no") {
        return "HR Manager";
    } else if (math == "yes" && design == "yes") {
        return "Architect";
    } else if (coding == "yes" && problem_solving == "yes") {
        return "Data Analyst";
    } else if (people == "yes" && problem_solving == "yes") {
        return "Psychologist";
    } else if (math == "yes") {
        return "Accountant";
    } else if (design == "yes") {
        return "Interior Designer";
    } else if (people == "yes") {
        return "Counselor";
    } else {
        return "Generalist";
    }
}

void showCareerGraph(const string &career) {
    map<string, CareerNode> graph;
    graph["Software Engineer"] = {"Software Engineer", {"Coding", "Math", "Problem Solving"}};
    graph["Graphic Designer"] = {"Graphic Designer", {"Design", "Creativity", "Photoshop/Illustrator"}};
    graph["HR Manager"] = {"HR Manager", {"Communication", "Teamwork", "Empathy"}};
    graph["Architect"] = {"Architect", {"Math", "Design", "Spatial Thinking"}};
    graph["Data Analyst"] = {"Data Analyst", {"Coding", "Statistics", "Excel/Python"}};
    graph["Psychologist"] = {"Psychologist", {"Empathy", "People Skills", "Research"}};
    graph["Accountant"] = {"Accountant", {"Math", "Finance", "Accuracy"}};
    graph["Interior Designer"] = {"Interior Designer", {"Creativity", "Design", "Aesthetics"}};
    graph["Counselor"] = {"Counselor", {"Empathy", "Communication", "Listening Skills"}};
    graph["Generalist"] = {"Generalist", {"Discover Interests", "Try Workshops", "Seek Mentorship"}};

    setConsoleColor(11);
    cout << "\n\n\tCareer Graph for: " << career << "\n";
    setConsoleColor(7);
    cout << "\t--------------------------------------\n";
    for (const string &skill : graph[career].skills) {
        cout << "\t  -> " << skill << endl;
        Sleep(500);
    }
    cout << "\t--------------------------------------\n";
}

void showResult(const Student &s, const string &career) {
    system("cls");
    drawBox("Your Career Recommendation");
    setConsoleColor(14);
    cout << "\tHello, " << s.name << "!\n\n";
    cout << "\tBased on your responses, your ideal career path is:\n\n";
    setConsoleColor(13);
    cout << "\t>> " << career << "\n";
    setConsoleColor(7);

    showCareerGraph(career);
    cout << "\n\tPress any key to exit...";
    _getch();
}

int main() {
    showWelcomeScreen();

    Student s;
    askQuestions(s);

    string career = recommendCareer(s);
    showResult(s, career);

    return 0;
}
