#include <iostream>
#include <vector>
#include <Windows.h> // Sleep( )
#include <fstream>
#include <algorithm>
using namespace std;

class newqueue : public vector<int> {
public:
    newqueue() : Ni(10), No(20), NC(100) {
        this->reserve(NC);
    };
    newqueue(int ni, int no, int x) : Ni(ni), No(no), NC(x) {
        this->reserve(NC);
    };
    int Ni, No, NC;
};

int main() {
    //Sprint 1
    int elapsedSeconds = 0, x, T = 1;
    cout << " RANDMAX  " << RAND_MAX << endl;
    while (elapsedSeconds < 10) {
        Sleep(T * 1000);  // milliseconds
        x = rand() % 100;  // 0~99 random  
        elapsedSeconds += T;
        cout << "  Elapsed time[sec] = "
            << elapsedSeconds << "   " << x << endl;
    }

    //Sprint 2
    vector <int> q;
    for (int i = 0; i < 10; i++) {
        q.push_back(rand() % 100);
        cout << q[q.size() - 1] << "in" << q.size() << endl;
    }
    for (int i = 0; i < 10; i++) {
        int ii = q[0];
        if (q.size() != 0) {
            cout << ii << " out " << q.size() << endl;
            q.erase(q.begin());
        }
    }

    //Sprint 3
    vector <int> queue;
    int capacity = 100;
    int NI = 20, NO = 30, ni, no, lost = 0, NofPackets[120];

    int queueSeconds = 0, qT = 1;
    while (queueSeconds < 120) {
        Sleep(T * 1000);  // milliseconds
        ni = rand() % NI;  // ni < NI random 
        no = rand() % NO;  // no < NO random

        if (capacity < queue.size() + ni) {
            lost += queue.size() + ni - capacity;
            ni = capacity - queue.size();
        }
        for (int i = 0; i < ni; i++) {
            queue.push_back(rand() % 100);
        }
        for (int i = 0; i < no; i++) {
            if (queue.size() != 0) {
                queue.erase(queue.begin());
            }
        }
        queueSeconds += qT;
        NofPackets[queueSeconds] = queue.size();
        cout << "ÆÐÅ¶ÀÇ °¹¼ö: " << NofPackets[queueSeconds] << "\n";
    }

    //Sprint 4
    newqueue qq(30, 15, 100);
    lost = 0;
    int sum = 0, newNofPackets[120];

    queueSeconds = 0, qT = 1;

    ofstream xx("excel.txt");
    while (queueSeconds < 120) {
        Sleep(T * 1000);  // milliseconds
        ni = rand() % qq.Ni;  // ni < NI random 
        no = rand() % qq.No;  // no < NO random
        if (qq.NC < qq.size() + ni) {
            lost += qq.size() + ni - qq.NC;
            ni = qq.NC - qq.size();
        }
        for (int i = 0; i < ni; i++) {
            qq.push_back(rand() % 100);
        }
        for (int i = 0; i < no; i++) {
            if (qq.size() != 0) {
                qq.erase(qq.begin());
            }
        }
        newNofPackets[queueSeconds] = qq.size();
        xx << queueSeconds + 1 << " " << newNofPackets[queueSeconds] << "\n";
        sum += newNofPackets[queueSeconds];
        queueSeconds += qT;
    }
    xx.close();
    cout << "¼Õ½Ç: " << lost << "\n";
    cout << "Æò±Õ: " << sum / 120. << "\n";
    sort(newNofPackets, newNofPackets + 120);
    cout << "ÃÖ´ñ°ª: " << newNofPackets[119] << "\n";
    return 123;
}