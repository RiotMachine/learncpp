#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <string_view>

class Creature
{
public:
    const std::string& name() const { return m_name; }
    char symbol() const             { return m_symbol; }
    int health() const              { return m_health; }
    int damage() const              { return m_damage; }
    int gold() const                { return m_gold; }

    void reduceHealth(int damage) { m_health -= damage; }
    bool isDead() const           { return m_health <= 0; }
    void addDamage(int damage)    { m_damage += damage; }
    void addGold(int gold)        { m_gold += gold; }


protected:
    Creature(std::string_view str, char c, int x, int y, int z)
      : m_name{ str }, m_symbol{ c },
        m_health{ x }, m_damage{ y }, m_gold{ z } {}


private:
    std::string m_name;
    char m_symbol{ };
    int m_health{ };
    int m_damage{ };
    int m_gold{ };
};

#endif
