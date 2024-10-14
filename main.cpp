#include "libs.h"
#include "Array.h"
#include "OList.h"
#include "BinarySearchTree.h"
#include "Stack.h"
#include "HashTable.h"
#include "Set.h"
#include <cctype>

using namespace std;

int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

bool isOperator(const string& c) {
    return c == "+" || c == "-" || c == "*" || c == "/";
}

void task_1() {
    cout << "Enter infix form: ";
    string infix;
    cin >> infix;

    Stack operators;
    string postfix;

    for (auto token : infix) {
        if (token == ' ') {
            continue;
        }
        if (isalnum(token)) {
            postfix += token;
        } else if (token == '(') {
            operators.push(string(1, token));
        } else if (token == ')') {
            while (!operators.is_empty() && operators.head->data != "(") {
                postfix += operators.head->data;
                operators.pop();
            }
            if (!operators.is_empty()) {
                operators.pop();
            }
        } else if (isOperator(string(1, token))) {
            while (!operators.is_empty() && precedence(operators.head->data) >= precedence(string(1, token))) {
                postfix += operators.head->data;
                operators.pop();
            }
            operators.push(string(1, token));
        }
    }

    if (operators.is_empty()){
        cout << "Postfix form: " << postfix << endl;
        return;
    }
    else {
        ONode* curr = operators.head;

        while(curr != operators.tail){
            postfix += curr->data;
            curr = curr->next;
        }

        postfix += curr->data;
    }

    cout << "Postfix form: " << postfix << endl;
}

/*
void pair_genom(OList& paired, const string& genom){
    for (int i = 0; i < genom.size() - 1; ++i){
        paired.push_back(string(1, genom[i]) + string(1, genom[i + 1]));
    }
}

void task_3(){
    cout << "Enter genom 1: ";
    string genom1;
    cin >> genom1;
    cout << "Enter genom 2: ";
    string genom2;
    cin >> genom2;

    OList paired1, paired2;
    pair_genom(paired1, genom1);
    pair_genom(paired2, genom2);

    paired1.print(" ");
    paired2.print(" ");
    //ABBACAB
    //BCABB

    unsigned int cntr = 0;
    if (paired1.size < paired2.size){
        for (auto i = paired1.first; i != nullptr; i = i->next){
            if (paired2.find_value(i->data) != -1){
                ++cntr;
            }
        }
    }
    else {
        for (auto i = paired2.first; i != nullptr; i = i->next){
            if (paired1.find_value(i->data) != -1){
                ++cntr;
            }
        }
    }

    cout << "Answer: " << cntr << endl;
}
*/

void pair_genom(Set& paired, const string& genom){
    for (int i = 0; i < genom.size() - 1; ++i){
        paired.add(string(1, genom[i]) + string(1, genom[i + 1]));
    }
}

void task_3(){
    cout << "Enter genom 1: ";
    string genom1;
    cin >> genom1;
    cout << "Enter genom 2: ";
    string genom2;
    cin >> genom2;

    Set paired1, paired2;
    pair_genom(paired1, genom1);
    pair_genom(paired2, genom2);

    paired1.data.print(" ");
    paired2.data.print(" ");
    //ABBACAB
    //BCABB

    unsigned int cntr = 0;
    if (paired1.data.size < paired2.data.size){
        for (auto i = paired1.data.first; i != nullptr; i = i->next){
            if (paired2.contains(i->data) != -1){
                ++cntr;
            }
        }
    }
    else {
        for (auto i = paired2.data.first; i != nullptr; i = i->next){
            if (paired1.contains(i->data) != -1){
                ++cntr;
            }
        }
    }

    cout << "Answer: " << cntr << endl;
}

int count_capitals(const string& word){
    int cntr = 0;
    for (auto i: word){
        if (isupper(i)) ++cntr;
    }

    return cntr;
}

void task_4(){
    cout << "Enter count of words in dictionsry: ";
    int cnt;
    cin >> cnt;

    cout << "Enter " << cnt << " words" << endl;
    Array dictionary;
    for (int i = 0; i < cnt; ++i){
        string word;
        cin >> word;
        dictionary.push_back(word);
    }

    cin.ignore();
    cout << "Enter text:" << endl;
    string text;
    getline(cin, text);

    int incorrectWords = 0;
    OList splitedText = split(text, " ");
    for (auto i = splitedText.first; i != nullptr; i = i->next){
        if (count_capitals(i->data) != 1){
            ++incorrectWords;
            continue;
        }
        if (dictionary.find_value(i->data) == 0){
            ++incorrectWords;
        }
    }

    cout << "There are " << incorrectWords << " mistakes" << endl;
}

void task_5(){
    BinTree tree;

    cout << "Enter numbers in tree, enter \"end\" if you want to stop" << endl;
    string number;
    cin >> number;
    while (number != "end"){
        tree.insert(stoi(number));
        cin >> number;
    }

    cout << "Tree before deleting" << endl;
    cout << "---------------------" << endl;
    tree.print_tree(tree.root, 0, 4);
    cout << "---------------------" << endl << endl;

    cout << "Enter number you want to delete: ";
    cin >> number;
    tree.remove(stoi(number));

    cout << endl << "Tree after deleting" << endl;
    cout << "---------------------" << endl;
    tree.print_tree(tree.root, 0, 4);
    cout << "---------------------" << endl;
}

void task_6() {
    cout << "Enter string to check: ";
    string str;
    cin >> str;
    HashTable hashTable;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < str.length(); ++end) {
        string currentChar(1, str[end]);

        string lastPositionStr = hashTable.get_values(currentChar);
        if (lastPositionStr != "No such a key") {
            int lastPosition = stoi(lastPositionStr);
            if (lastPosition >= start) {
                start = lastPosition + 1;
            }
        }

        maxLength = maxLength > end - start + 1 ? maxLength : end - start + 1;
        hashTable.set(currentChar, to_string(end));
    }

    cout << "Max substring has length: " << maxLength << endl;
}

int main()
{
    cout << "Enter task number: ";
    int taskNum;
    cin >> taskNum;

    switch(taskNum){
        case 1: task_1(); break;
        case 3: task_3(); break;
        case 4: task_4(); break;
        case 5: task_5(); break;
        case 6: task_6(); break;
        default: cout << "No such a task" << endl;
    }
    return 0;
}

