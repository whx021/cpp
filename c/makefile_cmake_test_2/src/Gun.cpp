#include "Gun.h"
#include <iostream>
using namespace std;


void Gun::addBullet(int bullet_num) {
    this->m_bullet_count += bullet_num;
}

bool Gun::shoot() {
    if (this->m_bullet_count <= 0) {
        cout << "there is no bullet!" << endl; 
        return false;
    }
    this->m_bullet_count -= 1;
    cout << "shoot successfully!" << endl;
    return true;
}