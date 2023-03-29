#ifndef GUN_H
#define GUN_H

#include <string>

class Gun {
public:
    Gun(std::string type) : m_type(type), m_bullet_count(0) {}
    void addBullet(int bullet_num);
    bool shoot();
private:
    int m_bullet_count;
    std::string  m_type;
};

#endif  // GUN_H