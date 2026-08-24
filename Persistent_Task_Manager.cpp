#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

struct Task{
    int id;
    string description;
    bool completed = false;
};

void AddTask(Task &task){
    cout << "Enter the ID: ";
    cin >> task.id;
    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, task.description);
}

void RemoveTask(vector<Task>& t){
    int deleteID;
    cout << "Enter the ID: ";
    cin >> deleteID;
    for(auto it = t.begin(); it!=t.end(); it++){
        if(it->id == deleteID){
            t.erase(it);
            break;
        }
    }
}

void CompleteTask(vector<Task>& t){
    int doneID;
    cout << "Enter the ID: ";
    cin >> doneID;
    for(auto it = t.begin(); it!=t.end(); it++){
        if(it->id == doneID){
            it->completed = true;
            break;
        }
    }
}

void ListTask(const vector<Task>& t){
    for(const auto& each: t){
        cout << "ID: " << each.id << '\n';
        cout << "Task: " << each.description << '\n';
        if(each.completed){
            cout << "Status: Done\n";
        }
        else{
            cout << "Status: Pending\n";
        }
        cout << "----------------------------------\n";
    }

}

void SearchTask(const vector<Task>& t){
    int id, task;
}

void Save(){}

void Load(){}

int main(){
    Task task;
    vector<Task> tasks;
    while(true){
        system("cls");
        cout << "========================\n    Task Manager\n========================\n\n";
        cout << "1. Add task\n2. Remove task\n3. Complete task\n4. List tasks\n5. Search tasks\n6. Save\n7. Load\n8. Exit\n\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: 
                system("cls");
                AddTask(task);
                tasks.push_back(task);
                break;
            case 2: 
                system("cls");
                RemoveTask(tasks);
                break;
            case 3: 
                system("cls");
                CompleteTask(tasks);
                system("pause");
                break;
            case 4: 
                system("cls");
                ListTask(tasks);
                system("pause");
                break;
            case 5: 
                system("cls");
                SearchTask(tasks);
                system("pause");
                break;
            case 6: 
                system("cls");
                Save();
                system("pause");
                break;
            case 7:
                system("cls");
                Load();
                break;
            case 8:
                return 0;
            default: 
                cout << "Invalid choice.";
        }
    }

    return 0;
}