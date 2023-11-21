#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct DomainTreeNode {
    string name;
    string ip;
    DomainTreeNode* firstChild;
    DomainTreeNode* nextSibling;

    DomainTreeNode(const string& nodeName, const string& nodeIp = "")
        : name(nodeName), ip(nodeIp), firstChild(nullptr), nextSibling(nullptr) {}
};

struct LNode {
    string data;
    LNode* next;
};

typedef LNode* Stack;

DomainTreeNode* createNode(const string& name, const string& ip = "") {
    return new DomainTreeNode(name, ip);
}

vector<string> splitDomain(const string& domain) {
    vector<string> parts;
    size_t start = 0, end;
    while ((end = domain.find('.', start)) != string::npos) {
        parts.push_back(domain.substr(start, end - start));
        start = end + 1;
    }
    parts.push_back(domain.substr(start));
    return parts;
}

void insertDomain(DomainTreeNode* root, const vector<string>& domainParts, const string& ip) {
    DomainTreeNode* current = root;

    for (auto it = domainParts.rbegin(); it != domainParts.rend(); ++it) {
        DomainTreeNode* child = current->firstChild;
        DomainTreeNode* prev = nullptr;
        while (child && child->name != *it) {
            prev = child;
            child = child->nextSibling;
        }
        if (!child) {
            child = createNode(*it);
            if (!prev) {
                current->firstChild = child;
            }
            else {
                prev->nextSibling = child;
            }
        }
        current = child;
    }
    current->ip = ip;
}

string queryDomain(DomainTreeNode* root, const vector<string>& domainParts) {
    DomainTreeNode* current = root;

    for (auto it = domainParts.rbegin(); it != domainParts.rend(); ++it) {
        DomainTreeNode* child = current->firstChild;
        while (child && child->name != *it) {
            child = child->nextSibling;
        }
        if (!child) {
            return "NO FOUND!";
        }
        current = child;
    }
    return !current->ip.empty() ? current->ip : "NO FOUND!";
}

void saveTree(ofstream& file, DomainTreeNode* node) {
    if (!node) return;
    file << "(" << node->name << " " << (node->ip.empty() ? "()" : node->ip);
    saveTree(file, node->firstChild);
    file << ")";
    saveTree(file, node->nextSibling);
}


DomainTreeNode* loadTree(istream& in) {
    string line;
    DomainTreeNode* root = createNode("root");

    while (getline(in, line)) {
        if (line.empty() || line == "( ())") continue; // Skip empty lines or empty nodes
        stringstream ss(line);
        char ch;
        ss >> ch;     
        string domain, ip;
        getline(ss, domain, ' ');
        getline(ss, ip, ')');
        if (ip == "()") ip = "";

        vector<string> domainParts = splitDomain(domain);
        insertDomain(root, domainParts, ip);
    }

    return root;
}


void freeDomainTree(DomainTreeNode* node) {
    if (!node) return;
    freeDomainTree(node->firstChild);
    freeDomainTree(node->nextSibling);
    delete node;
}

void printStorageData() {
    ifstream inFile("storage.txt");
    string line;

    if (!inFile.is_open()) {
        cout << "\t\t\t\t  �޷����ļ� storage.txt" << endl;
        return;
    }

    cout << "\t\t\t\t  storage.txt �����ݣ�" << endl;

    while (getline(inFile, line)) {
        line.erase(remove(line.begin(), line.end(), '('), line.end());
        line.erase(remove(line.begin(), line.end(), ')'), line.end());
        cout << "\t\t\t\t  " << line << endl;
    }

    inFile.close();
}


int main() {
    // ���ļ�������
    ifstream file("storage.txt");
    DomainTreeNode* root = nullptr;
    if (file.is_open()) {
        root = loadTree(file);
        file.close();
    }
    else {
        root = createNode("root");
    }

    string domain, ip;
    int choice;

    while (true) {
        system("color F0");
        system("cls");
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t\t  -----------------------------------------------" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             1.  ������ַ                  **" << endl;
        cout << "\t\t\t\t  **             2.  ��ѯ��ַ                  **" << endl;
        cout << "\t\t\t\t  **             3.  ��ӡ��������              **" << endl;
        cout << "\t\t\t\t  **             4.  �˳�ϵͳ                  **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t  �������������ţ�";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            char q = '0';

            while (1)
            {
               
                cout << "\t\t\t\t  �������ַ: ";
                cin>>domain;

                cout << "\t\t\t\t  ������IP: ";
                cin>>ip;
                vector<string> domainParts = splitDomain(domain);
                insertDomain(root, domainParts, ip);

                ofstream outFile("storage.txt", ios::app); // Append to the file
                if (outFile.is_open()) {
                    outFile << "(" << domain << " " << ip << ")" << endl;
                    outFile.close();
                }
                while (1)
                {
                    cout << "\n\t\t\t\t  �Ƿ������ӣ�y/n��";
                    cin >> q;
                    if (q == 'y' || q == 'n')break;
                    else cout << "\t\t\t\t�����������²�����" << endl;
                }
                if (q == 'n') break;
            }
                break;
        }
        case 2: {
            char q = '0';
            while (1)
            {
                
                cout << "\t\t\t\t  �������ַ: ";
                cin >> domain;
                vector<string> domainParts = splitDomain(domain);
                string result = queryDomain(root, domainParts);
                cout << "\t\t\t\t  IP��ַ��: " << result << endl;
                while (1)
                {
                    cout << "\n\t\t\t\t  �Ƿ������ѯ��y/n��";
                    cin >> q;
                    if (q == 'y' || q == 'n')break;
                    else cout << "\t\t\t\t�����������²�����" << endl;
                }
                if (q == 'n') break;
            }
            break;
        }
        case 3: {
            char q = '0';
           
                printStorageData();
                
                cout << "\n\t\t\t\t  �Ƿ������y/n��";
                getchar();
                q = getchar();
                if (q == 'n') return 0;
                break;
        }
      
        case 4: {
            freeDomainTree(root);
            return 0;
        }
        default:
            cout << "\t\t\t\t  ������������ԡ�\n";
            break;
        }
    }

    
    freeDomainTree(root);
    return 0;
}