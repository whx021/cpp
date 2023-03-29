//12、STL案例1——评委打分

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

class Player
{
public:
    Player(string name, int score = 0) : m_Name(name), m_Score(score){};
    
    void showInfo(void) const;
public:
    string  m_Name;
    int     m_Score;
};

void Player::showInfo(void) const
{
    cout << "name: " << this->m_Name << "\tscore: " << this->m_Score << endl;
}


//创建选手
void createPlayer(vector<Player>& v,int num = 0)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < num; ++i)
    {
        Player p("player");
        p.m_Name += nameSeed[i];

        v.push_back(p);
    }
}

//打印信息
void printInfo(const vector<Player>& v)
{
    for (vector<Player>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        (*it).showInfo();
    }
}

//评委打分
void setScore(vector<Player>& v)
{
    for (vector<Player>::iterator it = v.begin(); it != v.end(); ++it)
    {
        deque<int> d;
        for (int i = 0; i < 10; ++i)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        
        //对打分排序
        sort(d.begin(), d.end());

        //删除最高分，最低分
        d.pop_front();
        d.pop_back();

        //计算平均分
        int sect_Score = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit)
        {
            sect_Score += (*dit);
        }
        int average_Score = sect_Score / d.size();

        (*it).m_Score = average_Score;
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));

    vector<Player> v;

    createPlayer(v,5);

    //printInfo(v);

    setScore(v);

    printInfo(v);

    return EXIT_SUCCESS;
}