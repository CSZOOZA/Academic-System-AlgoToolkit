
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;

// Struct لتخزين بيانات الطالب
struct Student {
    int id;
    string name;
    double gpa;
};

// Class لإدارة النظام والمشاريع
class AcademicSystem {
private:
    vector<Student> students;

public:
    // 1. إضافة طالب جديد
    void addStudent(int id, string name, double gpa) {
        students.push_back({id, name, gpa});
        cout << "[+] Student " << name << " added successfully!\n";
    }

    // 2. عرض جميع الطلاب
    void displayStudents() const {
        cout << "\n--- Student Records ---\n";
        if (students.empty()) {
            cout << "No records found.\n";
            return;
        }
        for (const auto& s : students) {
            cout << "ID: " << s.id << " | Name: " << s.name << " | GPA: " << s.gpa << "\n";
        }
    }

    // 3. حفظ البيانات في ملف (Clean Code & File Handling)
    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "[-] Error saving data to file!\n";
            return;
        }
        for (const auto& s : students) {
            outFile << s.id << "," << s.name << "," << s.gpa << "\n";
        }
        outFile.close();
        cout << "[+] Data exported successfully to " << filename << "\n";
    }

    // 4. خوارزمية ترتيب ومقارنة سرعة الأداء (Algorithm & Performance Benchmark)
    void benchmarkSort() {
        if (students.empty()) {
            cout << "[-] Add some students first to run the benchmark.\n";
            return;
        }

        // تسجيل وقت البداية
        auto start = chrono::high_resolution_clock::now();

        // استخدام خوارزمية الترتيب بناءً على الـ GPA
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.gpa > b.gpa; // ترتيب تنازلي
        });

        // تسجيل وقت الانتهاء
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;

        cout << "\n[!] Students sorted by GPA (Highest first).\n";
        cout << "[!] Algorithm Execution Time: " << duration.count() << " ms\n";
    }
};

int main() {
    AcademicSystem system;

    cout << "===========================================\n";
    cout << "   Academic System & AlgoToolkit v1.0      \n";
    cout << "===========================================\n\n";

    // بيانات تجريبية
    system.addStudent(101, "Zaid Mahmoud", 3.8);
    system.addStudent(102, "Ahmed Ali", 3.4);
    system.addStudent(103, "Omar Hassan", 3.9);

    // عرض الطلاب قبل الترتيب
    system.displayStudents();

    // تشغيل خوارزمية الترتيب وحساب الوقت
    system.benchmarkSort();

    // عرض الطلاب بعد الترتيب
    system.displayStudents();

    // حفظ البيانات في ملف external
    system.saveToFile("students_data.txt");

    return 0;
}
